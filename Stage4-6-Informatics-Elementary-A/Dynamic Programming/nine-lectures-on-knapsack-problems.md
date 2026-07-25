# Nine Lectures on Knapsack Problems (2.0 beta1.2)

**Tianyi Cui** (a.k.a. dd_engi) — 2012-05-08

> This article, titled *Nine Lectures on Knapsack Problems*, belongs to the series *The Art of Thinking About Dynamic Programming*.
>
> The first edition of this series was produced in the second half of 2007 using Emacs Muse and published online in HTML format; it was widely reposted and had a certain influence.
>
> In September 2011 the series was reproduced and thoroughly revised by the original author using LaTeX. What you are reading is the 2.0 beta version. For the revision history and the latest version, see <https://github.com/tianyicui/pack>.
>
> Copyright belongs to the original author, released under the CC BY-NC-SA license.

---

## Contents

1. [The 0-1 Knapsack Problem](#1-the-0-1-knapsack-problem)
2. [The Complete (Unbounded) Knapsack Problem](#2-the-complete-unbounded-knapsack-problem)
3. [The Multiple (Bounded) Knapsack Problem](#3-the-multiple-bounded-knapsack-problem)
4. [Mixing the Three Knapsack Types](#4-mixing-the-three-knapsack-types)
5. [The Two-Dimensional-Cost Knapsack Problem](#5-the-two-dimensional-cost-knapsack-problem)
6. [The Grouped Knapsack Problem](#6-the-grouped-knapsack-problem)
7. [The Knapsack Problem with Dependencies](#7-the-knapsack-problem-with-dependencies)
8. [Generalized Items](#8-generalized-items)
9. [Variations on How Knapsack Problems Are Posed](#9-variations-on-how-knapsack-problems-are-posed)

---

## 1. The 0-1 Knapsack Problem

### 1.1 Problem Statement

There are `N` items and a knapsack of capacity `V`. Placing the *i*-th item costs `C[i]`[^1] and yields value `W[i]`. Determine which items to place in the knapsack so as to maximize the total value.

[^1]: i.e., the amount of knapsack capacity it occupies; from here on this is uniformly called the "**cost**".

### 1.2 Basic Idea

This is the most fundamental knapsack problem. Its defining feature: **each item is available exactly once, and you choose whether to take it or not.**

Define the state as a subproblem: let `F[i, v]` denote the maximum value obtainable when placing exactly the first `i` items into a knapsack of capacity `v`. The state transition equation is then:

```
F[i, v] = max{ F[i-1, v],  F[i-1, v - C[i]] + W[i] }
```

This equation is extremely important — essentially every equation for any knapsack-related problem is derived from it. So it is worth explaining in detail. Consider the subproblem "place the first `i` items into a knapsack of capacity `v`," looking only at the strategy for the *i*-th item (take it or not). It reduces to a problem involving only the first `i − 1` items:

- **If we do not take the *i*-th item**, the problem reduces to "place the first `i − 1` items into a knapsack of capacity `v`," with value `F[i-1, v]`.
- **If we do take the *i*-th item**, the problem reduces to "place the first `i − 1` items into the remaining capacity `v − C[i]`," and the maximum value obtainable is `F[i-1, v - C[i]]` plus the value `W[i]` gained by adding item `i`.

Pseudocode:

```
F[0, 0..V] ← 0
for i ← 1 to N
    for v ← C[i] to V
        F[i, v] ← max{ F[i-1, v], F[i-1, v - C[i]] + W[i] }
```

### 1.3 Optimizing Space Complexity

The above method has both time and space complexity `O(VN)`. The time complexity probably cannot be improved further, but the space complexity can be reduced to `O(V)`.

Recall how the basic idea is implemented: there is a main loop `i ← 1..N`, and each iteration computes all values of the two-dimensional array `F[i, 0..V]`. The question is: if we use only a single array `F[0..V]`, can we still guarantee that after the *i*-th iteration `F[v]` holds the state we defined as `F[i, v]`? Since `F[i, v]` is derived from the two subproblems `F[i-1, v]` and `F[i-1, v - C[i]]`, can we guarantee that when computing `F[i, v]` (i.e., when updating `F[v]` in the *i*-th iteration of the main loop) the values `F[i-1, v]` and `F[i-1, v - C[i]]` are still available?

In fact, this requires that in each main-loop iteration we compute `F[v]` in **decreasing** order `v ← V..0`, so that when computing `F[v]`, `F[v - C[i]]` still holds the state `F[i-1, v - C[i]]`. Pseudocode:

```
F[0..V] ← 0
for i ← 1 to N
    for v ← V downto C[i]
        F[v] ← max{ F[v], F[v - C[i]] + W[i] }
```

The line `F[v] ← max{ F[v], F[v - C[i]] + W[i] }` corresponds exactly to our original transition equation, because the current `F[v - C[i]]` plays the role of the old `F[i-1, v - C[i]]`. If we changed the loop order of `v` from decreasing to increasing, then `F[i, v]` would be derived from `F[i, v - C[i]]`, which does not match this problem (it would allow taking an item more than once).

Because the one-dimensional-array solution of the 0-1 knapsack is used repeatedly later, we abstract out a procedure that processes a single 0-1-knapsack item, and call it directly in later code without further explanation:

```
def ZeroOnePack(F, C, W)
    for v ← V downto C
        F[v] ← max(F[v], F[v - C] + W)
```

With this procedure, the 0-1 knapsack pseudocode becomes:

```
F[0..V] ← 0
for i ← 1 to N
    ZeroOnePack(F, C[i], W[i])
```

### 1.4 A Detail About Initialization

In the maximization-style knapsack problems we encounter, there are actually two slightly different formulations. Some problems ask for the optimum when the knapsack is **exactly filled**; others do **not** require the knapsack to be full. One way to distinguish them is by initializing differently.

- **If the knapsack must be exactly filled**, then during initialization set `F[0] = 0` and `F[1..V] = −∞`. This guarantees that the final `F[V]` is an optimum that exactly fills the knapsack.
- **If the knapsack need not be full**, and we only want the value to be as large as possible, then initialize all of `F[0..V]` to `0`.

Why? Think of the initialized `F` array as the set of legal states when no item has yet been placed. If the knapsack must be exactly filled, then only a knapsack of capacity `0` has a legal state — it can be "exactly filled" by putting nothing in it, with value `0`; every other capacity has no legal solution, is an undefined state, and should be assigned `−∞`. If the knapsack need not be full, then every capacity has the legal solution "put nothing in," with value `0`, so all initial states are `0`.

This little trick generalizes to every other type of knapsack problem, so the initialization before the state transition will not be discussed again.

### 1.5 A Constant-Factor Optimization

The lower bound of the inner loop above,

```
for i ← 1 to N
    for v ← V downto C[i]
```

can be improved. It can be optimized to:

```
for i ← 1 to N
    for v ← V downto max(V - Σ_{i}^{N} W[i]... , C[i])
```

That is, the lower bound becomes `max(C[i], V − (sum of the costs of items i..N))`. The reader is left to work out why this is valid. (Hint: it is easier to reason with the two-dimensional transition equation.)

### 1.6 Summary

The 0-1 knapsack problem is the most fundamental knapsack problem; it embodies the most basic ideas of designing states and equations in knapsack problems. Moreover, other knapsack types can often be converted into 0-1 knapsack problems. So do carefully absorb the derivation of the basic idea above, the meaning of the state transition equation, and how the space complexity is optimized.

---

## 2. The Complete (Unbounded) Knapsack Problem

### 2.1 Problem Statement

There are `N` kinds of items and a knapsack of capacity `V`; **each kind of item is available in unlimited quantity.** Item kind `i` has cost `C[i]` and value `W[i]`. Determine which items to pack so that the total cost does not exceed the capacity and the total value is maximized.

### 2.2 Basic Idea

This is very similar to the 0-1 knapsack, except each kind of item is unlimited. From the viewpoint of a given kind of item, the strategy is no longer just take/don't-take but take `0`, `1`, `2`, … up to `⌊V / C[i]⌋` copies.

Following the 0-1 approach, let `F[i, v]` be the maximum value packing exactly the first `i` kinds of items into capacity `v`. We can write the transition equation by enumerating strategies:

```
F[i, v] = max{ F[i-1, v - k·C[i]] + k·W[i]  |  0 ≤ k·C[i] ≤ v }
```

Like the 0-1 knapsack this has `O(VN)` states, but computing each state is no longer constant time — computing `F[i, v]` takes `O(v / C[i])`, so the total complexity is roughly `O(NV · Σ (V / C[i]))`, which is fairly large.

This shows the 0-1 knapsack equation is indeed important and extends to other types. But we still want to improve this complexity.

### 2.3 A Simple and Effective Optimization

The complete knapsack has a simple, effective optimization: **if two items `i` and `j` satisfy `C[i] ≤ C[j]` and `W[i] ≥ W[j]`, then item `j` can be discarded outright.**

The correctness is obvious: in any situation you can replace the more expensive, less valuable `j` with the cheaper, better `i`, and the resulting plan is at least as good. For randomly generated data this often greatly reduces the number of items and speeds things up. However, it does not improve the worst case, because specially crafted data may allow no item to be discarded.

This optimization can be implemented simply in `O(N²)`, which is usually affordable. A better approach specifically for knapsack: first discard items whose cost exceeds `V`, then use a counting-sort-like method to find, among items of the same cost, the one with the highest value — achievable in `O(V + N)`. This minor procedure's pseudocode is omitted; try writing it yourself.

### 2.4 Converting to a 0-1 Knapsack Problem

Since the 0-1 knapsack is the most basic, consider converting the complete knapsack into it.

The simplest idea: item kind `i` is taken at most `⌊V / C[i]⌋` times, so convert it into `⌊V / C[i]⌋` copies of an item with unchanged cost and value, then solve the resulting 0-1 knapsack. This does not improve the time complexity at all, but it points to the general approach: **split one kind of item into several "take 0 or 1" items.**

A more efficient conversion: **split item kind `i` into items with cost `C[i]·2^k` and value `W[i]·2^k`, where `k` ranges over all non-negative integers satisfying `C[i]·2^k ≤ V`.**

This is the binary-representation idea. No matter how many copies of item `i` the optimal strategy takes, that count written in binary can always be expressed as a sum of several `2^k` terms. Thus each kind of item is split into `O(log⌊V / C[i]⌋)` items — a large improvement.

### 2.5 An `O(VN)` Algorithm

This algorithm uses a one-dimensional array. First the pseudocode:

```
F[0..V] ← 0
for i ← 1 to N
    for v ← C[i] to V
        F[v] ← max(F[v], F[v - C[i]] + W[i])
```

You will notice this differs from the 0-1 knapsack pseudocode **only in the loop order of `v`**.

Why does this work? Recall why the 0-1 knapsack loops `v` in decreasing order: it ensures the state `F[i, v]` in iteration `i` is derived from `F[i-1, v - C[i]]` — in other words, it guarantees each item is taken at most once, so that when considering "take item `i`," the subresult `F[i-1, v - C[i]]` definitely does not already include item `i`. But the complete knapsack allows unlimited copies, so when considering "take one more copy of kind `i`," we precisely want a subresult `F[i, v - C[i]]` that may already include kind `i` — hence we can and must loop `v` in **increasing** order. That is why this simple program is correct.

Worth noting: the order of the two `for` loops above can be swapped. This may yield a constant-factor speedup.

This algorithm can also be derived another way. Write out the transition equation for `F[i, v - C[i]]` explicitly and substitute it into the original; you'll find the equation transforms equivalently into:

```
F[i, v] = max( F[i-1, v],  F[i, v - C[i]] + W[i] )
```

Implementing this with a one-dimensional array yields the pseudocode above.

Finally, abstract the procedure for processing a single complete-knapsack item:

```
def CompletePack(F, C, W)
    for v ← C to V
        F[v] ← max{ F[v], F[v - C] + W }
```

### 2.6 Summary

The complete knapsack is also quite fundamental and has two transition equations. Absorb both carefully — not just memorizing them but understanding how they are derived, ideally inventing a derivation yourself. Indeed, for every DP problem, pondering the meaning of its equation and how it arises is a great way to deepen your understanding of dynamic programming.

---

## 3. The Multiple (Bounded) Knapsack Problem

### 3.1 Problem Statement

There are `N` kinds of items and a knapsack of capacity `V`. Item kind `i` is available in at most `M[i]` copies, each occupying space `C[i]` with value `W[i]`. Determine which items to pack so that the total space does not exceed the capacity and the total value is maximized.

### 3.2 Basic Algorithm

Very similar to the complete knapsack; the basic equation just modifies it slightly. Kind `i` has `M[i] + 1` strategies: take `0, 1, …, M[i]` copies. Let `F[i, v]` be the maximum value packing exactly the first `i` kinds into capacity `v`:

```
F[i, v] = max{ F[i-1, v - k·C[i]] + k·W[i]  |  0 ≤ k ≤ M[i] }
```

Complexity: `O(V · Σ M[i])`.

### 3.3 Converting to a 0-1 Knapsack Problem

Another easy-to-write basic method converts to 0-1: replace kind `i` with `M[i]` copies of a 0-1-knapsack item, giving a 0-1 knapsack with `Σ M[i]` items. Solving directly is still `O(V · Σ M[i])`.

But we hope, as with the complete knapsack, to lower the complexity after conversion. Again use the binary idea: replace kind `i` with several items so that every strategy in the original — taking `0..M[i]` copies — is equivalent to taking some subset of the replacement items, and no strategy taking more than `M[i]` copies can arise.

**Method:** split kind `i` into several 0-1 items, each with a coefficient. The item's cost and value equal the original cost and value times this coefficient. Let the coefficients be `1, 2, 2², …, 2^(k−1), M[i] − 2^k + 1`, where `k` is the largest integer with `M[i] − 2^k + 1 > 0`. For example, if `M[i] = 13`, then `k = 3`, and this "take at most 13" item is split into four items with coefficients `1, 2, 4, 6`.

The coefficients sum to `M[i]`, so no more than `M[i]` copies can be taken. This method also guarantees that every integer in `0..M[i]` can be represented as a sum of some coefficients. (The correctness proof can be split into the ranges `0..2^k − 1` and `2^k..M[i]`; try it yourself.)

Thus kind `i` is split into `O(log M[i])` items, turning the original problem into a 0-1 knapsack of complexity `O(V · Σ log M[i])` — a large improvement.

Procedure for processing a single multiple-knapsack item in `O(log M)` time:

```
def MultiplePack(F, C, W, M)
    if C · M ≥ V
        CompletePack(F, C, W)
        return
    k ← 1
    while k < M
        ZeroOnePack(F, k·C, k·W)
        M ← M - k
        k ← 2k
    ZeroOnePack(F, C·M, W·M)
```

(If `C · M ≥ V`, then this kind is effectively unlimited within the knapsack, so treat it as a complete-knapsack item.) Work through this pseudocode carefully; if it is unclear, translate it into real code and single-step through it, or simulate it by hand, to deepen your understanding.

### 3.4 An `O(VN)` Algorithm for the Feasibility Problem

When the problem is "can items, each with a bounded count, exactly fill a given capacity" — i.e., we only care about feasibility of filling, not about values — the multiple knapsack also has an `O(VN)` algorithm.

For instance, a monotonic-queue data structure can optimize the basic transition equation so each state is computed in amortized `O(1)`.[^2]

[^2]: I first learned this method from Lou Tiancheng's "Eight Problems for Men" slides.

Here is a simpler-to-implement `O(VN)` algorithm. The idea: let `F[i, j]` denote "after using the first `i` kinds of items to fill capacity `j`, at most how many copies of kind `i` remain available." If `F[i, j] = −1` the state is infeasible; if feasible then `0 ≤ F[i, j] ≤ M[i]`.

Pseudocode:

```
F[0, 1..V] ← −1
F[0, 0]    ← 0
for i ← 1 to N
    for j ← 0 to V
        if F[i-1][j] ≥ 0
            F[i][j] ← M[i]
        else
            F[i][j] ← −1
    for j ← 0 to V - C[i]
        if F[i][j] > 0
            F[i][j + C[i]] ← max{ F[i][j + C[i]], F[i][j] - 1 }
```

Finally `F[N][0..V]` gives the answer to the multiple-knapsack feasibility problem.

### 3.5 Summary

In this lecture we saw a complexity improvement from `O(V · Σ M[i])` to `O(V · Σ log M[i])`, and learned that an `O(VN)` algorithm exists. Pay special attention to the "splitting items" idea and method; prove its correctness yourself and write out the complete program.

---

## 4. Mixing the Three Knapsack Types

### 4.1 Problem Statement

What if we mix the three knapsack types from §§1, 2, 3 — some items may be taken only once (0-1), some unlimited times (complete), and some up to a fixed limit (multiple)? How do we solve it?

### 4.2 Mixing 0-1 and Complete Knapsacks

The 0-1 and complete pseudocode differ in only one place. So with just two categories — take-once and take-unlimited — we simply choose the increasing or decreasing loop order per item, giving `O(VN)`:

```
for i ← 1 to N
    if item i is a 0-1 item
        for v ← V downto C[i]
            F[v] ← max(F[v], F[v - C[i]] + W[i])
    else if item i is a complete item
        for v ← C[i] to V
            F[v] ← max(F[v], F[v - C[i]] + W[i])
```

### 4.3 Adding the Multiple Knapsack

Adding items with a finite take-limit, a monotonic queue can give an amortized `O(VN)` solution. But without it, splitting each such item into `O(log M[i])` 0-1 items is already quite good.

The cleanest way is to call the three procedures defined earlier:

```
for i ← 1 to N
    if item i is a 0-1 item
        ZeroOnePack(F, C[i], W[i])
    else if item i is a complete item
        CompletePack(F, C[i], W[i])
    else if item i is a multiple item
        MultiplePack(F, C[i], W[i], M[i])
```

When first writing those three procedures, one may not have imagined they would combine here. This shows the power of abstraction in programming. If you always write each knapsack type by "abstracting out a procedure" and are clear on the subtle differences in their implementations, then when you meet the mixed problem you will quickly arrive at the concise solution above.

### 4.4 Summary

Some say hard problems are built by stacking easy ones. Whether that is axiomatic aside, it is well illustrated here. The 0-1, complete, and multiple knapsacks are individually not hard, but combined they form a problem that would surely intimidate many. Yet with a solid foundation and command of the three basic ideas, you can decompose a hard problem into easy ones.

---

## 5. The Two-Dimensional-Cost Knapsack Problem

### 5.1 Problem Statement

In the two-dimensional-cost knapsack, each item has **two different costs**; taking an item requires paying both. Each cost has its own maximum (its own "capacity"). Choose items to maximize total value.

Let item `i`'s two costs be `C[i]` and `D[i]`. The two maximums (capacities) are `V` and `U`. Item value is `W[i]`.

### 5.2 Algorithm

One extra cost dimension ⇒ one extra state dimension. Let `F[i, v, u]` be the maximum value using the first `i` items with the two costs paid being `v` and `u`:

```
F[i, v, u] = max{ F[i-1, v, u],  F[i-1, v - C[i], u - D[i]] + W[i] }
```

As with the space optimization earlier, use only a two-dimensional array: loop `v` and `u` in decreasing order for take-once items, increasing order for complete-knapsack items, and split items for multiple-knapsack items. Pseudocode is omitted; with the earlier foundation you should be able to implement it yourself.

### 5.3 Limiting the Total Number of Items

Sometimes the "two-dimensional cost" is given implicitly: **at most `U` items may be taken.** This is equivalent to each item having an extra "count" cost of `1`, with maximum count-cost `U`. Let `F[v, u]` be the maximum value paying cost `v` while taking at most `u` items; update by the item type (0-1 / complete / multiple), then search for the answer in `F[0..V, 0..U]`.

### 5.4 Knapsack over the Complex-Integer Domain

Another view of the two-dimensional knapsack: regard it as a knapsack over the **complex integers** (Gaussian integers) — the capacity and each item's cost are complex integers, whereas the ordinary one-dimensional knapsack is over the natural numbers. So the various one-dimensional ideas often apply to the two-dimensional problem, since only the number domain has been enlarged.

As an exercise, try extending the "subset-sum problem" mentioned later to two dimensions and solving it within the same complexity.

### 5.5 Summary

When you meet a problem that is a variation of a familiar DP problem, **adding a dimension to the state to satisfy the new constraint** is a fairly general method. May this lecture give you a first taste of it.

---

## 6. The Grouped Knapsack Problem

### 6.1 Problem Statement

There are `N` items and a knapsack of capacity `V`. Item `i` has cost `C[i]` and value `W[i]`. The items are partitioned into `K` groups; **items within a group conflict — at most one may be chosen.** Maximize total value without exceeding capacity.

### 6.2 Algorithm

Each group now has several strategies: choose one particular item of the group, or choose none. Let `F[k, v]` be the maximum value using the first `k` groups with cost `v`:

```
F[k, v] = max{ F[k-1, v],  F[k-1, v - C[i]] + W[i]  |  item i ∈ group k }
```

One-dimensional pseudocode:

```
for k ← 1 to K
    for v ← V downto 0
        for all item i in group k
            F[v] ← max{ F[v], F[v - C[i]] + W[i] }
```

The order of the three loops guarantees at most one item per group is added. (Note: the `v` loop must be the outer of the two innermost loops, so that within group `k` you never combine two items of the same group.)

Also, the optimization of §2.3 clearly applies within each group.

### 6.3 Summary

The grouped knapsack calls a set of mutually exclusive items a "group" — a very useful model. Many knapsack variants reduce to the grouped knapsack (e.g., §7), and from it one can further define the notion of the "**generalized item**," which is very helpful for problem solving.

---

## 7. The Knapsack Problem with Dependencies

### 7.1 A Simplified Version

Here items have a **dependency** relation: item `i` depends on item `j` means that choosing `i` requires choosing `j`. To simplify, first assume no item both depends on another and is depended upon by another, and no item depends on multiple items simultaneously.

### 7.2 Algorithm

This problem extends the task "Jinming's Budget Plan" from NOIP2006. Following that task, call an item that depends on nothing a **main item** (master), and an item depending on some main item an **accessory** (attachment). Under the simplification, all items consist of several main items, each with a set of accessories.

Following the usual knapsack approach, consider a single main item and its accessory set. But the strategies are numerous: choose nothing; choose the main only; choose the main plus one accessory; choose the main plus two accessories; … With `n` accessories there are `2^n + 1` strategies — exponential — impossible to express directly by a transition equation.

Since all these strategies are mutually exclusive (you can pick only one), a main item together with its accessory set corresponds exactly to a **group** in §6, and each strategy (main plus some accessories) corresponds to one item in that group, whose cost and value are the sums over the items chosen in that strategy. But this conversion alone gives no good algorithm, because the group still has exponentially many items.

Now apply the §2.3-style optimization within each group: among the group's items, of all items with the same cost we keep only the most valuable, without affecting the result. So we can first run a **0-1 knapsack over the accessory set** of main item `k`, obtaining, for each cost `0..V − C[k]`, the corresponding maximum value `Fk[0..V − C[k]]`. Then this main item together with its accessory set is equivalent to a group of `V − C[k] + 1` items, where the item of cost `v` has value `Fk[v − C[k]] + W[k]`, for `C[k] ≤ v ≤ V`.

That is, of the originally exponentially many strategies, many are redundant; a single 0-1 knapsack turns main item `k` and its accessories into a group of `V − C[k] + 1` items, and then §6's algorithm solves the problem directly.

### 7.3 A More General Version

The more general problem gives the dependencies as a **forest**[^3] in graph terms — a main item's accessory may itself have accessories. The only restriction is that each item depends on at most one item (has one master) and there are no cyclic dependencies.

[^3]: i.e., a set of multi-way (rooted) trees.

We still convert each main item and its accessory set into a group. The only difference: because an accessory may have its own accessories, an accessory can no longer be treated as an ordinary 0-1 item; if it has an accessory set it must first be converted into a group, then the grouped-knapsack method is used to compute, for the accessory group of the master and its accessories, the value corresponding to each cost.

This is in fact a form of **tree dynamic programming**: before computing a parent node's attribute by DP, one must first perform a DP-style evaluation over each of its children's attributes. This already touches the idea of the "generalized item." After reading §8 you will see that each subtree of this "dependency tree" is equivalent to one generalized item, and computing the generalized item for the subtree rooted at a node amounts to summing the generalized items of all its children.

### 7.4 Summary

I did that NOIP2006 knapsack problem very unsuccessfully — I wrote over a hundred lines of code and scored zero. Later, by reflecting, I found that introducing the notions of "group" and "dependency" deepens the understanding and even solves the generalization. Using the group idea on that task's very special dependency structure — an item cannot be both a main and an accessory, and each main has at most two accessories — one finds that a main item with its two accessories is equivalent to a group of four items, which reveals something essential about the problem.

Later, summarizing this in the first edition of *Nine Lectures on Knapsack Problems*, I wrote: "Failure is not shameful; gaining nothing from failure is." In the subsequent NOIP2007 contest, I scored full marks.

---

## 8. Generalized Items

### 8.1 Definition

Consider an item that has no fixed cost and value; instead its value varies with the cost you allocate to it. This is the notion of a **generalized item**.

More rigorously: in a knapsack problem of capacity `V`, a generalized item is a function `h` with domain the integers `0..V`; when the cost allocated to it is `v`, the value obtained is `h(v)`. Another way to see it: a generalized item is just an array `h[0..V]`; give it cost `v` and get value `h[v]`.

- An item of cost `c`, value `w` in a **0-1** knapsack, viewed as a generalized item, is the function with `h(c) = w` and all other values `0`.
- In a **complete** knapsack it is the function with `h(v) = w · (v / c)` when `c` divides `v`, and `0` otherwise.
- In a **multiple** knapsack with repetition limit `m`, `h(v) = w · (v / c)` when `c` divides `v` **and** `v / c ≤ m`, and `0` otherwise.
- A **group** of items can be viewed as a generalized item `h`: for `v` in `0..V`, if the group has no item of cost `v` then `h(v) = 0`, otherwise `h(v)` is the maximum value among all items of cost `v`. And from §6, each main item with its accessory set is equivalent to a group, hence also a generalized item.

### 8.2 The Sum of Generalized Items

Given two generalized items `h` and `l`, how do we obtain the maximum value from both under a given cost? For a fixed cost `v`, just enumerate how to split `v` between the two. For each integer `v` in `0..V` we can find the maximum value `f(v)` of splitting `v` between `h` and `l`:

```
f(v) = max{ h(k) + l(v - k)  |  0 ≤ k ≤ v }
```

Here `f` is itself a generalized item with domain `0..V`, determined by `h` and `l`. We **define `f` as the sum of the generalized items `h` and `l`**. The time complexity of this sum operation depends on the capacity and is `O(V²)`.

From the definition: in a knapsack problem, replacing two generalized items by their sum does not affect the answer. In fact, for a knapsack problem whose items are all generalized items, computing the answer **is** the process of summing all these generalized items. If the total sum is `s`, the answer is the maximum of `s(0..V)`.

### 8.3 The Generalized Item of a Knapsack Problem

A knapsack problem may impose many conditions — each item's cost and value, groupings, dependencies, and so on. Yet the problem must correspond to some generalized item: given all conditions, for each non-negative integer `v` we can determine the maximum value obtainable when the capacity is `v`. This can be seen as a single generalized item over the non-negative integers. This generalized item — the function over the non-negatives that the problem corresponds to — encodes highly condensed information about the problem itself. Generally, once we compute the values of this generalized item on a sub-domain (say `0..V`), the final answer follows from its values.

In summary: solving a knapsack problem generally means solving the function — the generalized item — that the problem corresponds to. And a common way to compute a generalized item is to express it as a sum of several generalized items and then compute that sum.

### 8.4 Summary

This lecture is a theory I arrived at while learning the functional programming language Scheme, examining the various knapsack problems through a functional lens.

I want to say: "**thinking**" is the most important quality of a programmer. Even simple problems, thought about deeply, can reveal much more.

---

## 9. Variations on How Knapsack Problems Are Posed

All the knapsack problems above ask for the maximum value under a capacity (cost) constraint, but there are many flexible ways to pose the problem, worth mentioning here. In my view, once you truly understand the method for the maximum-value knapsack, algorithms for the variants are not hard to devise.

For example, "how many items at most can be placed" or "how much of the knapsack's space can at most be filled" can both be obtained, per the specific problem, after computing all state values (the `F` array) with the earlier equations.

Also, if the requirement is "minimum total value" or "minimum total count," just change `max` to `min` in the transition equation.

Below are variations that differ more substantially.

### 9.1 Outputting the Plan

Usually a knapsack problem asks for an optimal value; if it asks to output the plan achieving that optimum, follow the general DP method for outputting plans: record, for each state's optimum, which term of the transition equation produced it — i.e., which strategy. Then trace back that strategy to the previous state and continue backward.

Take the 0-1 knapsack, equation `F[i, v] = max{ F[i-1, v], F[i-1, v - C[i]] + W[i] }`. Use an array `G[i, v]`: `G[i, v] = 0` means `F[i, v]` used the first term (`F[i, v] = F[i-1, v]`, item `i` **not** taken); `G[i, v] = 1` means the second term (item `i` taken). Output pseudocode (final state `F[N, V]`):

```
i ← N
v ← V
while i > 0
    if G[i, v] = 0
        print "item i not chosen"
    else if G[i, v] = 1
        print "item i chosen"
        v ← v - C[i]
    i ← i - 1
```

Alternatively, decide the term on the fly from the value of `F[i, v]`, without storing `G`: replace `G[i, v] = 0` with `F[i, v] = F[i-1, v]`, and `G[i, v] = 1` with `F[i, v] = F[i-1][v - C[i]] + W[i]`.

### 9.2 Outputting the Lexicographically Smallest Optimal Plan

Here "lexicographically smallest" means the smallest when the choice vector for items `1..N` is laid out. Take the 0-1 knapsack.

Generally, to get the lexicographically smallest optimum, just be careful with the strategy during transition. Note: if there exists an optimal plan that takes item `1`, then the answer must include item `1`, and the original problem reduces to a subproblem with capacity `V − C[1]` and items `2..N`. Otherwise the answer excludes item `1`, reducing to capacity `V`, items `2..N`. Either way, the subproblem's items are defined as `i..N` rather than `1..i`, so the state definition and transition need adjusting.

A simpler method: first relabel items by `x ← N + 1 − x`, then transform back when outputting the plan. After relabeling, use the classic transition equation. When outputting, take care: if both `F[i, v] = F[i-1, v]` and `F[i, v] = F[i-1][v - C[i]] + W[i]` hold, output according to the **latter** — i.e., choose item `i` and output its original label.

### 9.3 Counting the Number of Plans

For a knapsack with given capacity, item costs, and inter-item relations (grouping, dependency, …), besides the maximum value (given item values), we can also count the number of plans that fill the knapsack, or fill it to a specified capacity.

For such counting variants, generally just change `max` to `sum` in the transition equation. For instance, if every item is a complete-knapsack item:

```
F[i, v] = sum{ F[i-1, v],  F[i, v - C[i]] }
```

with initial condition `F[0, 0] = 1`. This works because the transition equation already examines every possible way the knapsack can be composed.

### 9.4 The Number of Optimal Plans

Here an "optimal plan" means one with maximum total value. Take the 0-1 knapsack. Combining the max-value and plan-counting ideas: let `F[i, v]` be the maximum value of the state and `G[i, v]` the number of optimal plans for that subproblem. Compute both together:

```
G[0, 0] ← 1
for i ← 1 to N
    for v ← 0 to V
        F[i, v] ← max{ F[i-1, v], F[i-1, v - C[i]] + W[i] }
        G[i, v] ← 0
        if F[i, v] = F[i-1, v]
            G[i, v] ← G[i, v] + G[i-1][v]
        if F[i, v] = F[i-1, v - C[i]] + W[i]
            G[i, v] ← G[i, v] + G[i-1][v - C[i]]
```

(Note: initialize `F` appropriately; if both branches match, both counts are added.) If you are seeing such a problem for the first time, work through the pseudocode carefully.

### 9.5 The Second-Best and K-th-Best Solutions

For finding the second-best or K-th-best solution: if the corresponding best-solution problem has a transition equation solvable by DP, then the second-best is usually solvable at the same complexity, and the K-th-best at an extra factor of `K` over the best.

The basic idea: represent each state as an **ordered queue**, and turn the `max`/`min` in the transition equation into a **merge of ordered queues**. Again take the 0-1 knapsack.

The best-solution equation is `F[i, v] = max{ F[i-1, v], F[i-1, v - C[i]] + W[i] }`. For the K-th-best, the state `F[i, v]` becomes a queue `F[i, v, 1..K]` of size `K`, where `F[i, v, k]` is the value of the k-th-best solution using the first `i` items with capacity `v`. Think of it as adding a dimension representing the priority order of results. Clearly `F[i, v, 1..K]` is sorted in decreasing order, i.e., an ordered queue.

The equation is then read as: the ordered queue `F[i, v]` is obtained by merging the two ordered queues `F[i-1, v]` and `F[i-1, v - C[i]] + W[i]`. The former is `F[i-1, v, 1..K]`; the latter is the ordered queue obtained by adding `W[i]` to each element of `F[i-1, v - C[i], 1..K]`. Merging these two ordered queues and keeping the top `K` into `F[i, v, 1..K]` costs `O(K)`. The final K-th-best answer is `F[N, V, K]`. Total time `O(VNK)`.

Why is this correct? A correct transition equation's solution traverses all usable strategies, covering all plans; because we sought the best, plans not optimal on any strategy were discarded. If each state holds a size-`K` array with its top `K` values in sorted order, then the `max` of any two states is equivalent to merging two decreasing ordered queues.

Also mind the problem's definition of "K-th-best": whether two plans with different strategies but equal value count as the same solution or different ones. If the same, then when maintaining the ordered queue, ensure there are no duplicate values.

### 9.6 Summary

Clearly, this cannot exhaust every way of posing knapsack-type DP problems. There is even a class combining knapsack DP with other fields (e.g., number theory, graph theory), which this treatise on the knapsack will not cover. But as long as you deeply grasp the ideas and transition equations of all the categories above, you should find it not hard to devise algorithms for other variants.

Drawing inferences and reasoning by analogy — that too should be a quality a programmer possesses.

---

*Translated from the Chinese original by Tianyi Cui (a.k.a. dd_engi). Released under CC BY-NC-SA. Latest source: <https://github.com/tianyicui/pack>.*
