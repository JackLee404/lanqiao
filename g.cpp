#include <iostream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using i64 = long long;

const int N = 1e5 + 10;

int a[N], b[N], cnt1, cnt2;

int main() {
	int k;
	std::string s;
	
	char c1, c2;
	
	std::cin >> k;
	
	std::cin >> s >> c1 >> c2;
	
	int j = 0;
	
	for (int i = 0; i < (int) s.size(); i ++) {
		if (s[i] == c1) {
			a[++ cnt1] = i;
		} else if (s[i] == c2) {
			b[++ cnt2] = i;
		}
	} 
	
	i64 ans = 0;
	
	for (int i = 1; i <= cnt1; i ++) {
		int l = 1, r = cnt2;
		while (l < r) {
			int mid = l + r >> 1;
			if (b[mid] - a[i] + 1 >= k) r = mid;
			else l = mid + 1;
		}
		
		if (b[l] - a[i] + 1 >= k)
			ans += (cnt2 - l + 1);
	}
	
	std::cout << ans;
	
	return 0;
} 
