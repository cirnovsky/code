MOD = 998244353

import sys
sys.setrecursionlimit(1 << 25)

def contains(a, b):
    return a in b

def prune(patterns):
    patterns = sorted(set(patterns), key=len)  # unique, increasing length
    kept = []
    for i, p in enumerate(patterns):
        if any(contains(p, q) for q in patterns if len(q) > len(p)):
            continue
        kept.append(p)
    # The above removes p if it is contained in any longer q.
    # Faster: scan once using the sorted list.
    kept2 = []
    for i, p in enumerate(patterns):
        if not any(p in patterns[j] for j in range(i+1, len(patterns))):
            kept2.append(p)
    return kept2

def build_automaton(patterns):
    nxt = [[-1]*26]  # trie edges
    link = [-1]      # failure link
    out  = [0]       # bitmask of matched patterns

    def add_word(w, idx):
        node = 0
        for ch in w:
            c = ord(ch) - 97
            if nxt[node][c] == -1:
                nxt[node][c] = len(nxt)
                nxt.append([-1]*26)
                link.append(0)
                out.append(0)
            node = nxt[node][c]
        out[node] |= (1 << idx)

    for i, w in enumerate(patterns):
        add_word(w, i)

    from collections import deque
    q = deque()
    # Initialize root transitions
    for c in range(26):
        if nxt[0][c] != -1:
            link[nxt[0][c]] = 0
            q.append(nxt[0][c])
        else:
            nxt[0][c] = 0
    # BFS build
    while q:
        v = q.popleft()
        out[v] |= out[link[v]]
        for c in range(26):
            u = nxt[v][c]
            if u != -1:
                link[u] = nxt[link[v]][c]
                q.append(u)
            else:
                nxt[v][c] = nxt[link[v]][c]
    return nxt, out

def solve():
    import sys
    input = sys.stdin.readline
    N, L = map(int, input().split())
    S = [input().strip() for _ in range(N)]

    P = prune(S)
    K = len(P)
    if K == 0:
        print(pow(26, L, MOD))
        return

    nxt, out = build_automaton(P)
    Ssz = len(nxt)
    full = (1 << K) - 1

    # dp over masks; to save memory use two layers over length
    dp = [ [0]*(1<<K) for _ in range(Ssz) ]
    dp[0][0] = 1

    for _ in range(L):
        ndp = [ [0]*(1<<K) for _ in range(Ssz) ]
        for v in range(Ssz):
            row = dp[v]
            # small optimization: skip empty rows
            if not any(row):
                continue
            for mask in range(1<<K):
                ways = row[mask]
                if ways == 0:
                    continue
                for c in range(26):
                    u = nxt[v][c]
                    m2 = mask | out[u]
                    ndp[u][m2] = (ndp[u][m2] + ways) % MOD
        dp = ndp

    ans = sum(dp[v][full] for v in range(Ssz)) % MOD
    print(ans)

if __name__ == "__main__":
    solve()

