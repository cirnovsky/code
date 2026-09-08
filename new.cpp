#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define all(a) begin(a), end(a)
template<class T> bool chmin(T& a, T b) { if(a <= b) return 0; a = b; return 1; }
template<class T> bool chmax(T& a, T b) { if(a >= b) return 0; a = b; return 1; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<int> cnt(1 << 10);
    rep(i, 0, N) {
        int bit = 0;
        rep(j, 0, 6) {
            int a;
            cin >> a;
            bit |= 1 << a;
        }
        rep(j, 1, 1 << 10) if(j & bit) cnt[j]++;
    }
    string S;
    for(int d = 1; ; d++) {
        vector<pair<int16_t, int16_t>> cond;
        rep(bit, 1, 1 << 10) cond.emplace_back(bit, cnt[bit]);
        auto nx_cond = [&](vector<pair<int16_t, int16_t>> cond, int c) -> vector<pair<int16_t, int16_t>> {
            c = 1 << c;
            for(auto& [key, val] : cond) if(key & c) if(val-- == 0) return {{1023, -1}};
            return cond;
        };
        auto dfs = [&](bool first, int16_t d, vector<pair<int16_t, int16_t>> cond, auto dfs) -> void {
            erase_if(cond, [&](pair<int16_t, int16_t> x) { return x.second >= d; });
            if(cond.empty()) return;
            if(d == 0) {
                cout << S;
                if(--K == 0) {
                    cout << endl;
                    exit(0);
                }
                else cout << ' ';
#ifdef DEBUG
                flush(cout);
#endif
                return;
            }
            int bit = 1023;
            if(ranges::min(views::values(cond)) == d - 1) {
                bit = 0;
                for (auto x: cond | views::keys) bit |= x;
            }
            rep(c, first, 10) if(bit & 1 << c) {
                S.push_back(48 + c);
                dfs(0, d - 1, nx_cond(cond, c), dfs);
                S.pop_back();
            }
        };
        dfs(1, d, cond, dfs);
    }
}
