#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f

using i64 = long long;

const int N = 10;

/*
2
3
0 100 10
10 10 10
0 2 20
3
0 10 20
10 10 20
20 10 20
*/

struct node {
	int t, d, l;
} arr[N];

bool cmp(node a, node b) {
	if (a.t + a.d == b.t + b.d) {
		return a.t < b.t; 
	} else return a.t + a.d < b.t + b.d;
} 

void solve() {
	int n;
	
	std::cin >> n;
	
	bool ok = true;
	
	for (int i = 1; i <= n; i ++) {
		std::cin >> arr[i].t >> arr[i].d >> arr[i].l;
	}
	
	std::sort(arr + 1, arr + 1 + n, cmp);
	
	int tm = arr[1].t;
	
	for (int i = 1; i <= n; i ++) {
		if (tm < arr[i].t) tm = arr[i].t;
		else if (tm > arr[i].t + arr[i].d) {
			ok = false;
			break;
		}
		
		
		tm += arr[i].l;
	
//		std::cout << tm << "\n";
//		std::cout << arr[i].t << " " << arr[i].d << " " << arr[i].l << "\n";
	}
	
	puts(ok?"YES":"NO");
}

int main(){
	int _;
	
	std::cin >> _;
	
	while (_ --) {
		solve();
	}
	
	return 0;
}
