l = []

"""def f(n):
    if n == 1:
        return 1
    if n == 2:
        return 1

    return f(n-1) + f(n-2)
"""

n = int(input("input number of entries to print: "))

l.append(1)
l.append(1)

for i in range(3, n+1):
    l.append(l[-1]+l[-2])    

print(l)
