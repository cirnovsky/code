#include <stdio.h>
using namespace std;

void solve() {
	//equivalent to reverse colour then swap i,j
	//RBBR -> RBBR RRRR RRBB
	//BRBR BBRR -> need to be flipped
	//RBR results in RBR
	//BRR RBR
	//RBBR BRRB RBRB RRBB
	//RBR BRB RBB RBR
	//bipartite:
	//	only when i,j are on the same party will the colour of j be reverted
	//	for colour c, denote l1[c], r1[c], l2[c], r2[c]
	//	l1[c] = 

int main() {
	int t;
	scanf("%d", &t);
	while (t--) puts(solve() ? "YES" : "NO");
}
