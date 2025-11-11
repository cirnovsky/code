
// brute_check.cpp
#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> solve_fast(const vector<int>& a) {
    int n = a.size();
    vector<int> ev;
    for (int x : a) if (x%2==0) ev.push_back(x);
    if (ev.size() >= 2) return {ev[0], ev[1]};
    if (ev.size() == 1) {
        int y = ev[0];
        for (int i = 0; i < n; ++i) {
            if (a[i] >= y) break;
            if (((y % a[i]) % 2) == 0) return {a[i], y};
        }
    }
    for (int i = 0; i+1 < n; ++i) {
        if (((a[i+1] % a[i]) % 2) == 0) return {a[i], a[i+1]};
    }
    return {-1,-1};
}

pair<long long,long long> solve_bruteforce(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (((a[j] % a[i]) % 2) == 0)
                return {a[i], a[j]};
    return {-1,-1};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // generate random tests or run manual cases
    mt19937 rng(123);
    for (int iter=0; iter<100000; ++iter) {
        int n = uniform_int_distribution<int>(2,8)(rng);
        set<int> s;
        while ((int)s.size() < n) s.insert(uniform_int_distribution<int>(1,100)(rng));
        vector<int> a(s.begin(), s.end());
        auto f = solve_fast(a);
        auto b = solve_bruteforce(a);
        if (f != b) {
            cerr << "Mismatch on test:\n";
            cerr << a.size() << "\n";
            for (int x : a) cerr << x << " ";
            cerr << "\nfast: " << f.first << " " << f.second << "\nbrute: " << b.first << " " << b.second << "\n";
            return 0;
        }
    }
    cerr << "No mismatch found in random tests.\n";
    return 0;
}
