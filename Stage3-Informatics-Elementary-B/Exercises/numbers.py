with open("numbers.in","w") as f:
    for i in range(10000000):
        f.write(str(i%100)+"\n")
