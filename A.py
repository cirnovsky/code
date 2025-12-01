from random import shuffle
import sys

n = int(input())
cnm = [x-1 for x in list(map(int, input().split()))]
perm = list(range(n))

def ask(a):
    assert len(a) == n
    print("?", *[x+1 for x in a])
    sys.stdout.flush()

    def fuck():
        sus = [0] * n
        for p in a:
            if sus[p] == 0:
                sus[cnm[p]] = 1
        return sus
    
    return fuck()
    return list(map(int, input().split()))
"""
def ask(a):
    assert len(a) == n
    print("?", *[x+1 for x in a])
    sys.stdout.flush()
    
    return list(map(int, input().split()))
"""

adj = [[True] * n for _ in range(n)]
for _ in range(4*n-1):
    shuffle(perm)
    res = ask(perm)

    for i in range(n):
        if not res[i]:
            for j in range(i, n):
                if not res[j]:
                    adj[i][j] = adj[j][i] = False

visited = [-1] * n
ans = [0] * n

sl = []
for i in range(n):
    def check(u):
        for v in range(n):
            if not adj[u][v]:
                return False
        return True

    if check(i):
        ans[i] = i
        sl.append(i)

for i in sl:
    for j in range(n):
        adj[i][j] = adj[j][i] = False

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
        if cnt != len(block)//2:
            use = block[::-1]

        if len(block) == 3:
            assert res[use[0]] == 1
            if not res[use[1]]:
                use[0], use[1] = use[1], use[0]

        for i in range(len(use)):
            ans[use[i]] = use[(i+1)%len(use)]

print("!", *[x+1 for x in ans])
sys.stdout.flush()
