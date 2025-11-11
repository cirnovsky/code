with open("in", 'r') as f:
    n = int(f.readline())
    perm = [x-1 for x in list(map(int, f.readline().split()))]

def perform(od):
    sus = [0] * n
    od = [x-1 for x in od]

    for p in od:
        if sus[p] == 0:
            sus[perm[p]] = 1

    return sus

print(n, flush=True)

for _ in range(4*n):
    s = input()
    if s[0] == '?':
        s = s[2:]
        sus = perform(list(map(int, s.split())))
        print(*sus, flush=True)
    else:
        s = s[2:]
        s = s.split()
        with open('result', 'w') as f:
            f.write("niubi" if s == perm else "shabi")
            f.write(str(s))
            f.write(str(perm))
        break
