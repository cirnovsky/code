n, k = map(int, input().split())

for _ in range(k):
    l, r, x = map(int, input().split())
    print(l, r, format(x, '06b'))
