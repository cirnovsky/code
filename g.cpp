#include <iostream>
#include <vector>
#include <numeric>     // For std::iota
#include <algorithm>   // For std::shuffle
#include <random>      // For std::mt19937
#include <chrono>      // For seeding
#include <set>         // To ensure unique ranges
#include <utility>     // For std::pair

// Use the same high-quality RNG setup as your template
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

/**
 * @brief Generates a random 64-bit integer in the range [l, r] (inclusive).
 */
long long rng(long long l, long long r) {
    std::uniform_int_distribution<long long> dist(l, r);
    return dist(rnd);
}

int main() {
    // Standard fast I/O
    std::cin.tie(nullptr)->sync_with_stdio(0);

    // Number of test cases
    int t = rng(1, 5);
    std::cout << t << "\n";

    while (t--) {
        // Generate N and Q, respecting problem constraints
        // Using smaller values for faster duipai
        int n = rng(4, 10);
        int q = rng(1, n*n/2);
        std::cout << n << " " << q << "\n";

        // Generate Q unique ranges
        std::set<std::pair<int, int>> ranges;
        while (ranges.size() < q) {
            // Problem constraints are 1-based [l, r]
            int l = rng(1, n);
            int r = rng(l, n); // Ensure l <= r
            ranges.insert({l, r});
        }

        // Print the ranges
        for (const auto& [l, r] : ranges) {
            std::cout << l << " " << r << "\n";
        }

        // Generate the permutation p (your 'cnm')
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0); // Fills with 0, 1, 2, ..., n-1
        std::shuffle(p.begin(), p.end(), rnd); // Shuffles the vector

        // Print the permutation on a single line
        for (int i = 0; i < n; ++i) {
            std::cout << p[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }

    return 0;
}
