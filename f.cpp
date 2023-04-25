#include <iostream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using i64 = long long;

//const int N = 1e5 + 10;

int n, m;

char a[100][100];


void solve() {
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];
		}
	}
}

int main() {
	int _;
	
	std::cin >> _;
	
	while (_ --) {
		solve();
	}
}
