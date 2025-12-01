#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rd(x) cin >> x

void solve() {
    int n, q;
    rd(n); rd(q);
    string s;
    rd(s);
    
    int before_xv = 0,
        pair_c = 0,
        single = 0,
        after_i = 0,
        sandwich = 0; // NEW: Track I?(X/V)
        
    int base = 0;
    
    // 1. Parse string and calculate Base / Slots
    for (int i = n; i-- > 0; ) {
        if (s[i] == 'X')
            base += 10;
        else if (s[i] == 'V')
            base += 5;
        else if (s[i] == 'I') {
            if (i + 1 < n && (s[i + 1] == 'X' || s[i + 1] == 'V'))
                base--;
            else
                base++;
        }
        
        // Check for ? followed by X or V
        if ((s[i] == 'X' || s[i] == 'V') && i > 0 && s[i - 1] == '?') {
            before_xv++;
            // FIX 1: Check if this ? is sandwiched: I ? (X/V)
            if (i > 1 && s[i - 2] == 'I') {
                sandwich++;
            }
            s[i - 1] = '.'; // Consume the ?
        }
        else if (s[i] == '?') {
            if (i > 0 && s[i - 1] == '?') {
                pair_c++; 
                s[i] = s[i - 1] = '.';
            }
            else if (i > 0 && s[i - 1] == 'I') {
                after_i++; 
                s[i] = '.';
            }
            else {
                single++; 
                s[i] = '.';
            }
        }
    }

    // 2. Process Queries
    while (q--) {
        int X, V, I;
        rd(X); rd(V); rd(I);
        int X_ = X, V_ = V;
        
        // Save state
        int _bx = before_xv, _pc = pair_c, _si = single, _ai = after_i;

        // Step A: Fill before_xv ( ?(X/V) )
        // Priority: Use I (makes -1). Else use V/X.
        int neg_one = min(I, before_xv); 
        I -= neg_one;
        before_xv -= neg_one; 
        // Remaining 'before_xv' must be filled with X or V. 
        // These are the ones that might trigger the sandwich penalty.
        int forced_xv_in_before = before_xv; 

        // Step B: Fill pair_c ( ?? )
        int neg_one2 = min(min(I, X + V), pair_c);
        I -= neg_one2;
        X += min(0, V - neg_one2);
        V = max(0, V - neg_one2);
        pair_c -= neg_one2;

        // Move unused slots to 'single'
        single += forced_xv_in_before + pair_c * 2; 

        // Step C: Fill after_i ( I? )
        // Priority: Use I (makes II -> +2). Else use X/V (makes IX -> +8 or IV -> +3)
        // Note: Using X/V here flips the previous I from +1 to -1.
        int neg_two = min(after_i, X + V); // Count of I? filled with X or V
        after_i -= neg_two;
        X += min(0, V - neg_two);
        V = max(0, V - neg_two);

        single += after_i;

        // Step D: Fill single ( ? )
        int pos_one = min(single, I);
        single -= pos_one;
        I -= pos_one;

        X += min(0, V - single);
        V = max(0, V - single);

        // FIX 2: Calculate sandwich correction.
        // We filled 'neg_one' slots with I. The rest (forced_xv_in_before) used X/V.
        // If we use X/V in a sandwich slot, the previous I flips (-2 cost).
        // We prioritize matching the forced X/Vs to sandwich slots to minimize the sum.
        int sandwich_correction = min(forced_xv_in_before, sandwich) * 2;

        cout << base 
             - neg_one 
             - neg_one2 
             - 2 * neg_two          // Fix for after_i filled with X/V
             - sandwich_correction  // Fix for I?(X/V) filled with X/V
             + pos_one 
             + 5 * (V_ - V) 
             + 10 * (X_ - X) << "\n";

        // Restore state
        before_xv = _bx; pair_c = _pc; single = _si; after_i = _ai;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
