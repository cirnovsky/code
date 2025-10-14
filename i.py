
MOD = 998244353

import bisect

class SegmentTree:
    def __init__(self, n):
        # supports indices [0..n-1]
        self.n = n
        self.size = 1
        while self.size < n:
            self.size <<= 1
        self.val = [0] * (2 * self.size)
        self.lazy = [1] * (2 * self.size)

    def _apply(self, idx, mul):
        self.val[idx] = (self.val[idx] * mul) % MOD
        self.lazy[idx] = (self.lazy[idx] * mul) % MOD

    def _push(self, idx):
        if self.lazy[idx] != 1:
            self._apply(idx*2, self.lazy[idx])
            self._apply(idx*2+1, self.lazy[idx])
            self.lazy[idx] = 1

    def range_mul(self, l, r, mul, idx=1, lx=0, rx=None):
        if rx is None:
            rx = self.size
        if l >= rx or r <= lx:
            return
        if l <= lx and rx <= r:
            self._apply(idx, mul)
            return
        self._push(idx)
        mid = (lx + rx) // 2
        self.range_mul(l, r, mul, idx*2, lx, mid)
        self.range_mul(l, r, mul, idx*2+1, mid, rx)
        self.val[idx] = (self.val[idx*2] + self.val[idx*2+1]) % MOD

    def point_add(self, pos, add, idx=1, lx=0, rx=None):
        if rx is None:
            rx = self.size
        if rx - lx == 1:
            self.val[idx] = (self.val[idx] + add) % MOD
            return
        self._push(idx)
        mid = (lx + rx) // 2
        if pos < mid:
            self.point_add(pos, add, idx*2, lx, mid)
        else:
            self.point_add(pos, add, idx*2+1, mid, rx)
        self.val[idx] = (self.val[idx*2] + self.val[idx*2+1]) % MOD

    def get_point(self, pos, idx=1, lx=0, rx=None):
        if rx is None:
            rx = self.size
        if rx - lx == 1:
            return self.val[idx]
        self._push(idx)
        mid = (lx + rx) // 2
        if pos < mid:
            return self.get_point(pos, idx*2, lx, mid)
        else:
            return self.get_point(pos, idx*2+1, mid, rx)

def count_with_target(arr, target):
    # counts subsequences of arr that produce exactly 'target' (strictly increasing)
    k = len(target)
    st = SegmentTree(k+1)   # dp indices 0..k
    st.point_add(0, 1)      # dp[0] = 1
    for x in arr:
        pos = bisect.bisect_left(target, x)  # first index >= x
        # If x equals next required element, we'll need dp[pos] (old value)
        add = 0
        if pos < k and target[pos] == x:
            add = st.get_point(pos)
        # Doubling affects dp[j] for j in [pos+1 .. k] (if any)
        if pos + 1 <= k:
            st.range_mul(pos+1, k+1, 2)
        if add:
            st.point_add(pos+1, add)
    # result is dp[k]
    return st.get_point(k) % MOD

def count_with_target_right(arr_rev, target, M):
    # arr_rev is the suffix reversed (scanning from right).
    # target is R without final M.
    # This function allows, after finishing target, taking an extra M (and then more elements).
    k = len(target)
    st = SegmentTree(k+1)
    st.point_add(0, 1)
    extra_M = 0  # counts subsequences that have already taken an extra M (and matched all k)
    for x in arr_rev:
        pos = bisect.bisect_left(target, x)
        add = 0
        if pos < k and target[pos] == x:
            add = st.get_point(pos)
        # transfer: if x == M we can take it to move sequences that have already matched all k
        transfer = 0
        if x == M:
            transfer = st.get_point(k)  # dp_noM[k] before updates

        # apply doublings (use old dp values)
        if pos + 1 <= k:
            st.range_mul(pos+1, k+1, 2)
        # dp_with_M doubles on every element (once M taken, any element <= M allowed)
        extra_M = (extra_M * 2) % MOD

        # apply adds/transfers
        if add:
            st.point_add(pos+1, add)
        if transfer:
            extra_M = (extra_M + transfer) % MOD

    return (st.get_point(k) + extra_M) % MOD

def solve_one(a):
    n = len(a)
    M = max(a)
    # build left-record sequence (L) and right-record sequence (R)
    L = []
    cur = -10**30
    for x in a:
        if x > cur:
            L.append(x)
            cur = x
    R = []
    cur = -10**30
    for x in reversed(a):
        if x > cur:
            R.append(x)
            cur = x
    # remove the final M from both sequences (they must end with M)
    Lreq = L[:-1]   # left required before M
    Rreq = R[:-1]   # right required before M (in order scanned from right)

    total = 0
    for i, val in enumerate(a):
        if val != M:
            continue
        left_seq = a[:i]
        right_seq = a[i+1:]
        left_count = count_with_target(left_seq, Lreq)
        right_count = count_with_target_right(list(reversed(right_seq)), Rreq, M)
        total = (total + left_count * right_count) % MOD
    return total

# ---- main I/O ----
import sys
data = list(map(int, sys.stdin.read().strip().split()))
it = iter(data)
t = next(it)
out = []
for _ in range(t):
    n = next(it)
    a = [next(it) for _ in range(n)]
    out.append(str(solve_one(a)))
print("\n".join(out))
