# 二叉树（Binary Tree）专题讲义 —— 冲刺 AIO Gold

> 本讲义基于《Elementary B - Trees》幻灯片的**二叉树部分**（第 14–29 页）整理，并针对 **AIO（Australian Informatics Olympiad，澳大利亚信息学奥林匹克）Gold（金牌）** 目标扩展了进阶内容。
> 所有专业术语首次出现时均附英文（English）对照，方便对照官方题面（题目一律为英文）。

---

## 目录

1. 二叉树基础概念（Fundamentals）
2. 二叉树的存储表示（Representation）
3. 二叉树的遍历（Traversal）
4. 二叉树的性质（Properties）
5. 二叉排序树 BST（Binary Search Tree）
6. **Gold 进阶专题**：树状数组、线段树、LCA、树形 DP
7. 复杂度速查与竞赛注意事项
8. 推荐练习

---

## 0. 学习目标与心态（Why Trees Matter）

在 AIO 里，二叉树本身很少作为「裸题」出现，但它是几乎所有 Gold 级数据结构的**地基（foundation）**：

- 线段树（Segment Tree）、树状数组（Fenwick Tree / BIT）本质是二叉结构；
- 最近公共祖先（LCA, Lowest Common Ancestor）、树形动态规划（Tree DP）都建立在「有根树 + 遍历」之上；
- 平衡树（Balanced BST，如 `std::set` / `std::map`）是你手里现成的武器。

Gold 的门槛不在「知道概念」，而在**能在比赛 3–4 小时内把它们无 bug 地写出来**。所以本讲义每个结构都配可直接背诵的 C++ 模板。

---

## 1. 二叉树基础概念（Fundamentals）

**二叉树（Binary Tree）** 是一种每个结点（node）**至多有两个子结点**的树，且这两个子结点有明确的左右之分：

- 左子结点 / 左孩子（left child）
- 右子结点 / 右孩子（right child）

注意「左右有别」是二叉树区别于一般树（general tree）的关键：即使一个结点只有一个孩子，它是「左孩子」还是「右孩子」也是不同的树。

### 核心术语（对照 PPT 第 3 页的一般树术语）

| 中文 | English | 含义 |
|---|---|---|
| 根 | root | 唯一没有父结点的结点 |
| 叶子 | leaf | 没有孩子的结点（度为 0） |
| 度 | degree | 一个结点的子树个数（二叉树中 ≤ 2） |
| 父结点 | parent | 拥有子树的结点 |
| 孩子 | child | 子树的根 |
| 兄弟 | siblings | 同一个父亲的孩子 |
| 祖先 | ancestor | 从某结点到根路径上的所有结点 |
| 后代 | descendants | 某结点子树中的所有结点 |
| 层 | level | 根为第 1 层，父层 + 1 |
| 高度 / 深度 | height / depth | 所有结点层数的最大值 |

### 几类特殊二叉树（Special Binary Trees）—— Gold 常用

- **满二叉树（Full / Perfect Binary Tree）**：每一层都被填满，深度为 $h$ 时恰有 $2^h - 1$ 个结点。
- **完全二叉树（Complete Binary Tree）**：除最后一层外每层填满，且最后一层结点从左到右连续排列。**堆（Heap）和线段树的隐式数组表示就依赖这个性质。**
- **平衡二叉树（Balanced Binary Tree）**：左右子树高度差有界，保证操作是 $O(\log n)$。`std::set`/`std::map` 底层是红黑树（Red-Black Tree），属于此类。

---

## 2. 二叉树的存储表示（Representation）

### 2.1 结点—父指针表示（Child-Parent Representation）— PPT 第 15 页

每个结点显式记录值、父亲、左右孩子。适合需要「向上找父亲」的题目：

```cpp
struct Node {
    int value;                  // 结点权值 (node value)
    int parent, lchild, rchild; // 父、左孩子、右孩子的下标；0 表示空
} node[N];
```

约定用下标 `0` 表示空结点（null），根的 `parent = 0`。

### 2.2 数组（隐式）表示（Array Representation）— PPT 第 16 页

对**完全二叉树**，可以不存指针，直接用数组下标表达父子关系。设根下标为 `1`：

- 结点 `i` 的左孩子 = `2*i`
- 结点 `i` 的右孩子 = `2*i + 1`
- 结点 `i` 的父亲 = `i / 2`（整数除法，向下取整）

```
下标 i :  1   2   3   4   5   6   7   8   9
结点   :  A   B   C   D   E   F   G   H   I
```

> **为什么 Gold 一定要掌握它？** 线段树（Segment Tree）和二叉堆（Binary Heap）都用这种「数组即树」的技巧，省去指针、常数极小、缓存友好。**从下标 1 开始**是竞赛惯例，因为 `2*i` / `2*i+1` 公式最简洁（下标 0 会与「空」混淆）。

代价：如果树不完全（sparse），会浪费大量空间——最坏一条链需要 $2^n$ 的数组。所以稀疏树用指针/`vector`，规整树用数组。

### 2.3 森林转二叉树（Converting a Forest to a Binary Tree）— PPT 第 17–18 页

任意一般树 / 森林（forest）都能唯一转成一棵二叉树，规则叫「**左孩子右兄弟（left-child right-sibling, LCRS）**」表示法：

- 一个结点的**左指针**指向它的**第一个孩子（first child）**；
- 一个结点的**右指针**指向它的**下一个兄弟（next sibling）**。

这样一棵「多叉」结构就被编码进「二叉」结构，好处是无论原树每个结点有多少孩子，存储都固定为两个指针。Gold 里遇到「不定分叉的树」时，这是把它统一成二叉处理的经典技巧。

---

## 3. 二叉树的遍历（Traversal）— PPT 第 19 页

**遍历（traversal）** = 按某种顺序访问每个结点恰好一次。二叉树有三种深度优先（DFS, Depth-First）遍历，区别在于「访问根」的时机：

| 遍历 | English | 顺序 |
|---|---|---|
| 前序 | preorder | **根** → 左 → 右 |
| 中序 | inorder | 左 → **根** → 右 |
| 后序 | postorder | 左 → 右 → **根** |

```cpp
void preorder(int u) {          // 前序 (root first)
    if (u == 0) return;
    visit(u);
    preorder(lchild[u]);
    preorder(rchild[u]);
}
void inorder(int u) {           // 中序 (root in middle)
    if (u == 0) return;
    inorder(lchild[u]);
    visit(u);
    inorder(rchild[u]);
}
void postorder(int u) {         // 后序 (root last)
    if (u == 0) return;
    postorder(lchild[u]);
    postorder(rchild[u]);
    visit(u);
}
```

还有一种**层序遍历（level-order / BFS, Breadth-First）**，用队列（queue）逐层访问：

```cpp
void bfs(int root) {
    queue<int> q; q.push(root);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        visit(u);
        if (lchild[u]) q.push(lchild[u]);
        if (rchild[u]) q.push(rchild[u]);
    }
}
```

### Gold 必背结论

1. **BST 的中序遍历（inorder）结果是升序序列（sorted order）**——这是 BST 一切性质的来源，务必牢记。
2. 已知**前序 + 中序**，或**后序 + 中序**，可以唯一重建（reconstruct）一棵二叉树；但**前序 + 后序不能**唯一确定（无法区分只有一个孩子时的左右）。AIO 里出现「给两种遍历还原树」的构造题，靠的就是这个。
3. 递归遍历会占用调用栈（call stack）。当树退化成链、深度可达 $n$（例如 $n=10^5$）时，可能爆栈（stack overflow）；必要时改写成显式栈（explicit stack）的迭代版本。

---

## 4. 二叉树的性质（Properties）— PPT 第 20 页

考试中直接可用的定量结论（设根在第 1 层）：

1. 第 $i$ 层最多有 $2^{i-1}$ 个结点。
2. 深度为 $h$ 的二叉树最多有 $2^h - 1$ 个结点（即满二叉树 / perfect binary tree）。
3. 含 $n$ 个结点的二叉树，最小高度为 $\lceil \log_2(n+1) \rceil$，最大高度为 $n$（退化成链 / degenerate chain）。
4. **叶子数关系**：设度为 0 的结点数为 $n_0$，度为 2 的结点数为 $n_2$，则恒有
   $$n_0 = n_2 + 1.$$
   这条「叶子比满分叉结点多一个」的性质在计数类构造题里很常见。

---

## 5. 二叉排序树（Binary Search Tree, BST）— PPT 第 21–29 页

### 5.1 定义（Definition）

**二叉排序树（Binary Search Tree, BST）**，又称**二叉查找树（binary search tree）**，是一棵满足以下性质的二叉树（空树也算）：

1. 若左子树非空，则**左子树所有结点的值 < 根的值**；
2. 若右子树非空，则**右子树所有结点的值 > 根的值**；
3. 左、右子树本身也都是 BST（递归定义 / recursive definition）。

推论：**对 BST 做中序遍历（inorder traversal）会得到从小到大排好序的序列。**

> PPT 第 22 页的红蓝边：红边（red edge）= 指向左孩子，蓝边（blue edge）= 指向右孩子——只是可视化辅助，理解左小右大即可。

### 5.2 查找（Search）— PPT 第 24 页

从根出发，比 key 大就往左走，比 key 小就往右走：

```cpp
int bst_search(int rt, int key) {
    if (rt == 0 || data[rt] == key) return rt; // 空 或 找到
    if (key < data[rt])
        return bst_search(lch[rt], key);        // 目标更小 → 左子树
    else
        return bst_search(rch[rt], key);        // 目标更大 → 右子树
}
```

> 注意：PPT 第 24 页原代码把 `data[rt] < key` 时递归进 **左**子树，这与「右子树更大」的定义相矛盾，是笔误。正确方向如上：**key 更小走左、更大走右**。这类细节在考场上一写反就全错，务必自己推一遍。

### 5.3 插入（Insertion）— PPT 第 25–26 页

沿查找路径走到底，在空位置挂上新叶子（new leaf）；已存在则不插入：

```cpp
void bst_insert(int &rt, int key) {   // 注意 rt 用引用 int&
    if (rt == 0) { rt = new_node(key); return; } // 空位 → 建新结点
    if (data[rt] == key) return;                 // 已存在，忽略
    if (key < data[rt])
        bst_insert(lch[rt], key);   // 插入左子树
    else
        bst_insert(rch[rt], key);   // 插入右子树
}
```

用**引用参数 `int &rt`** 是关键技巧：递归到空指针时能直接把父亲的孩子指针改掉，代码非常简洁。

### 5.4 生成与「退化」问题（Generation & Degeneration）— PPT 第 27 页

生成一棵 BST 就是不断插入的过程。但**同一组 key、不同的插入顺序会得到形状不同的 BST**：

- 若按已排序顺序插入，会退化成一条链（chain），高度 $O(n)$，查找退化到 $O(n)$；
- 随机打乱插入顺序，期望高度约 $O(\log n)$。

这正是为什么竞赛里**几乎不手写裸 BST**，而用**平衡树（balanced tree）**——见 5.6。

### 5.5 删除（Deletion）— PPT 第 28 页

删除要分三种情况，核心是「删完仍保持 BST 性质」：

1. **叶子结点**：直接把父亲对应的孩子指针置空。
2. **只有一个孩子**：用那个唯一的孩子顶替（replace）自己的位置。
3. **有两个孩子**：找**左子树中的最大结点**（即中序前驱 / inorder predecessor），把它的值搬上来，再删掉那个前驱结点（它必然没有右孩子，退化成情况 1 或 2）。
   > 对称做法：也可用**右子树的最小结点**（中序后继 / inorder successor）。两者皆可。

```cpp
// 情况 3：用左子树最大值(前驱)替换被删结点 p，s 为待回收结点
int q = p, s = lch[p];
while (rch[s]) { q = s; s = rch[s]; } // 一路向右找到左子树最大
data[p] = data[s];                    // 值搬上来
if (p == q) lch[q] = lch[s];          // s 就是 p 的左孩子
else        rch[q] = lch[s];          // 否则把 s 的左孩子接到 q 上
// s 可回收
```

### 5.6 复杂度与平衡树（Complexity & Balanced BST）— PPT 第 29 页

| 操作 | 平均（随机/平衡） | 最坏（退化成链） |
|---|---|---|
| 查找 search | $O(\log n)$ | $O(n)$ |
| 插入 insert | $O(\log n)$ | $O(n)$ |
| 删除 delete | $O(\log n)$ | $O(n)$ |

裸 BST 最坏 $O(n)$，靠不住。工程与竞赛都用**自平衡 BST（self-balancing BST）**保证最坏 $O(\log n)$：

- **红黑树（Red-Black Tree）**——`std::set` / `std::map` / `std::multiset` 的底层；
- **AVL 树（AVL Tree）**——严格高度平衡；
- 竞赛常手写的 **Treap**、**Splay Tree**（进阶，Gold 偶尔需要）。

> **Gold 实战建议**：99% 需要「有序集合 + 增删查 + 求前驱后继 + 求第 k 小」的场景，直接用 STL 的 `std::set` / `std::map`，或用**树状数组 / 权值线段树**替代，几乎不用自己写平衡树。把精力花在正确调用上。

**`std::set` 速用：**

```cpp
set<int> s;
s.insert(x);              // 插入
s.erase(x);               // 删除
s.count(x);               // 是否存在 (0/1)
auto it = s.lower_bound(x); // 第一个 >= x 的元素 (前驱后继就靠它)
if (it != s.begin()) { --it; /* 前驱 */ }
```

---

# 第二部分：Gold 进阶专题（Advanced Topics for Gold）

以下四个结构是「二叉树 → 竞赛数据结构」的直接延伸，也是 AIO Gold 的高频考点。都给出可背诵模板。

## 6. 树状数组（Fenwick Tree / Binary Indexed Tree, BIT）

**用途**：$O(\log n)$ 完成「单点修改（point update）+ 前缀和查询（prefix-sum query）」。代码短、常数小，是 Gold 里性价比最高的结构。

它的名字里就有 binary：下标 `i` 管辖的区间长度是 `lowbit(i) = i & (-i)`，即 `i` 二进制最低位的 1 所代表的值——本质是把区间按二进制拆分。

```cpp
long long c[N];          // 1-indexed，务必从下标 1 开始
int n;
int lowbit(int x) { return x & (-x); }

void update(int i, long long v) {      // 第 i 个位置加上 v
    for (; i <= n; i += lowbit(i)) c[i] += v;
}
long long query(int i) {               // 前缀和 a[1..i]
    long long s = 0;
    for (; i > 0; i -= lowbit(i)) s += c[i];
    return s;
}
// 区间和 a[l..r] = query(r) - query(l - 1);
```

**经典应用**：求逆序对（inversions）。把数值离散化后从左到右扫，每读一个数 `x`，「已出现且比它大的个数」就是 `(已插入总数) - query(x)`，累加即逆序对数。

## 7. 线段树（Segment Tree）

**用途**：支持**区间查询（range query）+ 区间/单点修改（range/point update）**，比 BIT 通用（最值、区间和、区间赋值、区间加……都能做），代价是代码更长、常数更大。

用**数组隐式表示**的满二叉树：结点 `p` 管区间 `[l,r]`，左儿子 `2p` 管 `[l,mid]`，右儿子 `2p+1` 管 `[mid+1,r]`。数组开 **`4*n`** 大小最保险。

### 7.1 区间和 + 单点修改（入门版）

```cpp
long long tree[4 * N];
int a[N];

void build(int p, int l, int r) {
    if (l == r) { tree[p] = a[l]; return; }
    int mid = (l + r) / 2;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    tree[p] = tree[2*p] + tree[2*p+1];   // 上传 (pull up)
}
void update(int p, int l, int r, int pos, long long val) {
    if (l == r) { tree[p] = val; return; }
    int mid = (l + r) / 2;
    if (pos <= mid) update(2*p, l, mid, pos, val);
    else            update(2*p+1, mid+1, r, pos, val);
    tree[p] = tree[2*p] + tree[2*p+1];
}
long long query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];      // 完全覆盖
    int mid = (l + r) / 2; long long res = 0;
    if (ql <= mid) res += query(2*p, l, mid, ql, qr);
    if (qr >  mid) res += query(2*p+1, mid+1, r, ql, qr);
    return res;
}
```

### 7.2 区间修改 + 懒标记（Lazy Propagation）

当修改也是「一整段」时，必须用**懒标记 / 延迟标记（lazy tag / lazy propagation）**：先在结点上记「这段整体加了多少」，真正需要往下走时才下传（push down）。这是 Gold 的核心技巧之一。

```cpp
long long tree[4*N], lazy[4*N];

void push_down(int p, int l, int r) {
    if (!lazy[p]) return;
    int mid = (l + r) / 2;
    long long v = lazy[p];
    tree[2*p]   += v * (mid - l + 1); lazy[2*p]   += v;
    tree[2*p+1] += v * (r - mid);     lazy[2*p+1] += v;
    lazy[p] = 0;
}
void update(int p, int l, int r, int ql, int qr, long long v) {
    if (ql <= l && r <= qr) {
        tree[p] += v * (r - l + 1); lazy[p] += v; return;
    }
    push_down(p, l, r);
    int mid = (l + r) / 2;
    if (ql <= mid) update(2*p, l, mid, ql, qr, v);
    if (qr >  mid) update(2*p+1, mid+1, r, ql, qr, v);
    tree[p] = tree[2*p] + tree[2*p+1];
}
long long query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    push_down(p, l, r);
    int mid = (l + r) / 2; long long res = 0;
    if (ql <= mid) res += query(2*p, l, mid, ql, qr);
    if (qr >  mid) res += query(2*p+1, mid+1, r, ql, qr);
    return res;
}
```

**BIT vs 线段树怎么选？** 只要「单点改 + 前缀和」，用 BIT（更快更短）；需要区间改、区间最值、复杂合并，用线段树。

## 8. 最近公共祖先（Lowest Common Ancestor, LCA）

**LCA(u, v)** = 有根树中同时是 `u` 和 `v` 祖先、且深度最大的结点。常用于「树上两点间距离 / 路径」类题目。

竞赛主流写法是**倍增法（binary lifting）**——又是二进制思想：预处理 `up[u][k]` = 结点 `u` 向上跳 $2^k$ 步到达的祖先。预处理 $O(n\log n)$，单次查询 $O(\log n)$。

```cpp
const int LOG = 17;              // 2^17 > 1e5，按 n 调整
vector<int> g[N];
int up[N][LOG], dep[N];

void dfs(int u, int p) {         // 预处理深度与祖先表
    up[u][0] = p;
    for (int k = 1; k < LOG; ++k)
        up[u][k] = up[ up[u][k-1] ][k-1];
    for (int v : g[u])
        if (v != p) { dep[v] = dep[u] + 1; dfs(v, u); }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for (int k = 0; k < LOG; ++k)          // 把较深的 u 提到同层
        if (d >> k & 1) u = up[u][k];
    if (u == v) return u;
    for (int k = LOG - 1; k >= 0; --k)     // 一起往上跳到 LCA 下方
        if (up[u][k] != up[v][k]) { u = up[u][k]; v = up[v][k]; }
    return up[u][0];
}
// 树上距离 dist(u,v) = dep[u] + dep[v] - 2*dep[lca(u,v)]
// 调用前：dep[root]=0; dfs(root, root);
```

## 9. 树形动态规划（Tree DP）

**树形 DP（Tree Dynamic Programming）** = 在树上做 DP，通常一次**后序遍历（post-order DFS）**：先算完所有孩子的 DP 值，再合并（merge）到父亲。「先子后父」正是后序的顺序。

**例题：最大独立集 / 没有上司的舞会（Maximum Weight Independent Set on a tree）。** 选一些结点使权值和最大，且不能同时选相邻两点。

```cpp
vector<int> g[N];
long long dp[N][2];   // dp[u][0]=不选u, dp[u][1]=选u, 各自子树的最优
long long w[N];

void dfs(int u, int fa) {
    dp[u][0] = 0;
    dp[u][1] = w[u];
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]); // u 不选 → v 随意
        dp[u][1] += dp[v][0];                // u 选   → v 必不选
    }
}
// 答案 = max(dp[root][0], dp[root][1]);
```

树形 DP 的通用套路：**状态定义在「以 u 为根的子树」上；转移在 DFS 回溯时用孩子的状态更新父亲。** 换根 DP（re-rooting）是它的进阶变体（需要两次 DFS），Gold 偶有涉及。

---

## 10. 复杂度速查表（Complexity Cheat Sheet）

| 结构 / 操作 | 构建 build | 查询 query | 修改 update | 空间 space |
|---|---|---|---|---|
| 平衡 BST / `std::set` | $O(n\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(n)$ |
| 树状数组 BIT | $O(n)$ | $O(\log n)$ | $O(\log n)$ | $O(n)$ |
| 线段树 Segment Tree | $O(n)$ | $O(\log n)$ | $O(\log n)$ | $O(4n)$ |
| LCA（倍增） | $O(n\log n)$ | $O(\log n)$ | — | $O(n\log n)$ |
| 树形 DP | $O(n)$（一次 DFS） | — | — | $O(n)$ |

## 11. 考场易错点（Common Pitfalls in AIO）

- **下标从 1 开始**：数组表示、BIT、线段树都用 1-indexed，`2*i`/`lowbit` 公式才成立。
- **线段树数组开 `4*n`**，别开 `2*n`（会越界 / RE）。
- **爆栈**：链状树递归深度 $n$。$n \ge 10^5$ 时用迭代或增大栈；AIO 用 C++ 一般默认栈够，但心里要有数。
- **整数溢出（overflow）**：区间和、计数类累加常超 `int`（$>2\times10^9$），该用 `long long` 就用。
- **BST 方向别写反**：key 更小走左、更大走右（PPT 第 24 页有笔误，见 §5.2）。
- **懒标记必须先 `push_down` 再递归**，否则查询/修改读到过期值。
- **读题看清是「有根树」还是「无根树」**：无根树要先定根（PPT 第 12–13 页 `set_parent`）才能做 LCA / 树形 DP。

## 12. 推荐练习（Practice）

按难度递进，建议全部用 C++ 实现并卡时限：

1. 二叉树遍历 + 由「前序 + 中序」重建二叉树（掌握 §3 结论）。
2. BST 增删查 + 求第 k 小 / 前驱后继（可用 `std::set` 或权值 BIT）。
3. 逆序对计数（BIT / 归并，§6 应用）。
4. 区间和 + 区间加（线段树懒标记模板，§7.2）。
5. 树上两点距离（LCA 模板，§8）。
6. 没有上司的舞会 / 树上最大独立集（树形 DP 模板，§9）。

> **备考节奏建议**：先把 §6–§9 的四个模板**默写到无 bug**（每个限时 15 分钟内敲完并通过样例），再去刷综合题。Gold 拼的是模板熟练度 + 读题准确度，而非新知识点数量。

---

*讲义完 · 祝冲金顺利 (Good luck going for Gold!)*





