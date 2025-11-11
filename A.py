import random

n = int(input())
perm = list(range(n))

def ask(a):
    print("?", *[x+1 for x in a], flush=True)
    
    return list(map(int, input().split()))

adj = [[True] * n for _ in range(n)]
for _ in range(4*n-1):
    random.shuffle(perm)
    res = ask(perm)

    for i in range(n):
        if not res[i]:
            for j in range(i+1, n):
                if not res[j]:
                    adj[i][j] = adj[j][i] = False

visited = [-1] * n
ans = [0] * n

print(adj)

# handle selfloops
for i in range(n):
    def check(u):
        for v in range(n):
            if v != u and (not adj[u][v] or not adj[v][u]):
                return False
        return True

    if check(i):
        ans[i] = i
        visited[i] = 114514

def dfs(i, color, s):
    s.append(i)
    visited[i] = color
    for j in range(n):
        if adj[i][j] and visited[j] != color:
            dfs(j, color, s)

blocks = []
for i in range(n):
    if visited[i] == -1:
        color = len(blocks)
        blocks.append([])
        dfs(i, color, blocks[-1])

tmp = []
for block in blocks:
    tmp.extend(block)

if tmp:
    res = ask(tmp)

    for block in blocks:
        cnt = len(block)
        for sentinel in block:
            cnt -= res[sentinel]

        use = block
        if cnt > 0:
            use = block[::-1]
        now = block[0]
        if len(block) == 1:
            ans[now] = now
        else:
            for i in range(1, len(use)):
                ans[now] = use[i]
                now = use[i]

print("!", *[x+1 for x in ans], flush=True)
