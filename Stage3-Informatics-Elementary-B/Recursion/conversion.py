line = input("Please input a binary number: ")

d = 0
for c in line[::]:
    d = d*2 + int(c)

print(d)

d = int(input("Please input a decimal number: "))
b = []
while d > 0:
    r = d % 2
    b.insert(0,str(r))
    d = d//2

print("".join(b))



