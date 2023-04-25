#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <utility>
//#define ff first
//#define ss second
//#define PII std::pair<int, int>
#define INF 0x3f3f3f3f
using i64 = long long;

const int N = 5e5 + 10;

int a[N], st[N];

struct node {
	int l, r;
}b[N];

struct diy {
	int ff, ss;
};

bool operator<(diy a, diy b) {
	if (a.ff == b.ff) {
		return a.ss > b.ss;
	} else {
		return a.ff > b.ff;
	}
}

std::priority_queue<diy> q1;

int n, k, tot;

int main() {
	
	std::cin >> n >> k;
	
	tot = n;
	
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		
		b[i].l = i - 1, b[i].r = i + 1;
		
		q1.push({a[i], i});
		
		st[i] = 1;
	}
	
	while (tot > n - k) {
		diy t = q1.top(); q1.pop();
		int val = t.ff, i = t.ss;
		
		if (st[i] != 1) {
			st[i] --;
			continue;
		} else {
			tot --;
			
			
			st[i] = 0;
			
			b[b[i].r].l = b[i].l;
			
			b[b[i].l].r = b[i].r;
			
			if (b[i].l >= 1) {
				st[b[i].l] ++;
				a[b[i].l] += val;
				q1.push({a[b[i].l], b[i].l});
			}
			
			if (b[i].r <= n) {
				st[b[i].r] ++;
				a[b[i].r] += val;
				
				q1.push({a[b[i].r], b[i].r});
			}
		}
	}
	
	bool ok = false;
	
	for (int i = 1; i <= n; i ++) {
		if (st[i]) {
			if (ok) {
				std::cout << " " << a[i];
			} else std::cout << a[i];
			ok = true;
		}
	}
}
