#include <iostream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using i64 = long long;

const int N = 1e5 + 10;

int a[N], dp[N];

/*
	以a[i]结尾的接龙序列 的最少删除数量 
*/

bool check(int a, int b) {
	int t = b % 10;
	while (b) {
		t = b % 10;
		b /= 10;
	}
	
//	std::cout << t << "\n";
	
	if (a % 10 == t) return true;
	return false;
} 

int main() {
	int n;
	std::cin >> n;
	
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	
	int ans = 1; 
	
	for (int i = 1; i <= n; i ++) {
		dp[i] = 1;
		for (int j = 1; j < i; j ++) {
			if (check(a[j], a[i])) { 
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
		ans = std::max(ans, dp[i]);
	} 
	
	std::cout << n - ans;
}
