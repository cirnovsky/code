import sys

def solve():
    t = int(input());
    out_lines = []
    for _ in range(t):
        n = int(input());
        h = [0]*(n+1)  # 1-indexed
        h = list(map(int, input().split()))
        h.insert(0, 0)

        # 1) Baseline cost
        base = h[1]
        for i in range(2, n+1):
            base += max(0, h[i] - 1)

        if n == 2:
            out_lines.append(str(base))
            continue

        # 2) Precompute next index >= i with h[idx] > 1
        next_gt1 = [n+1]*(n+2)
        last = n+1
        for i in range(n, 0, -1):
            if h[i] > 1:
                last = i
            next_gt1[i] = last

        # 3) For each cut position j in [2..n-1], compute weight and block end t_j
        # dp over j: 0 if not usable; dp size n+2 for safe indexing
        w = [0]*(n+2)
        block_end = [0]*(n+2)

        for j in range(2, n):  # cannot cut at n
            x = h[j+1]
            # Delta(j) = 1 + [max(0, x-j) - max(0, x-1)]
            delta = 1 + (max(0, x - j) - max(0, x - 1))
            if delta < 0:
                w[j] = -delta  # benefit if we take this cut
            else:
                w[j] = 0

            # Compute t_j (last index invalidated by choosing this cut)
            if x > j:
                t = j
            else:
                # j+1 dies; then a run of 1's above (each gets 1 fall) also die
                # next_gt1[j+2] is first index >= j+2 with h[idx] > 1 (or n+1)
                first_gt1 = next_gt1[j+2] if (j+2) <= n else n+1
                t = (first_gt1 - 1)  # inclusive last dead
            block_end[j] = t

        # 4) DP (choose non-overlapping beneficial cuts to maximize total benefit)
        dp = [0]*(n+3)
        for j in range(n-1, 1, -1):
            # skip invalid/zero-weight cuts seamlessly
            skip = dp[j+1]
            take = w[j] + dp[block_end[j] + 1]
            if take > skip:
                dp[j] = take
            else:
                dp[j] = skip

        ans = base - dp[2]
        out_lines.append(str(ans))

    print("\n".join(out_lines))


if __name__ == "__main__":
    solve()

