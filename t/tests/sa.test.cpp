#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
#include "../sa.hpp"

int main() {
  static char str[1<<19];
  cin>>str;
  auto sa = SA(str);
  for(int i:sa)cout<<i<< " ";
  cout<<"\n";
}
