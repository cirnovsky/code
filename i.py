from random import shuffle

n = 6
ans = list(range(n))

while True:
    shuffle(ans)
    with open("in", "w") as f:
        f.write(str(n))
        f.write(str(ans))
