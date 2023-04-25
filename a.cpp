#include <bits/stdc++.h>
#define debug(x) std::cout << x << "\n" 
std::map<std::string, int> mp;

using i64 = long long;

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int a[1000], ans = 0, n;

bool st[1000];

bool check(std::string & t) {
	if (atoi(t.substr(0, 4).c_str()) != 2023) return false;
	
	int mm = atoi(t.substr(4, 2).c_str());
	int dd = atoi(t.substr(6, 2).c_str());
	
	if (dd > 0 && dd <= day[mm]) {
		if (!mp[t]) {
			mp[t] ++;
			ans ++;
		}
		return true;
	} else return false;
}

std::string b = "20230000";

void dfs(int j, std::string now) {
	if (j == 8) {
		check(now); 
		return;
	}
	
	for (int i = 1; i <= n; i ++) {
		if (!st[i]) {
			if (j <= 3 && a[i] == b[j] - '0') {
				st[i] = true;
				now.push_back(a[i] + '0');
				dfs(j + 1, now);
				now.pop_back();
				st[i] = false;
			} else if (j > 3) {
				if (j == 4) {
					
				}
				st[i] = true;
				now.push_back(a[i] + '0');
				dfs(j + 1, now);
				now.pop_back();
				st[i] = false; 
			}
		} 
	}
}

int main() {
	std::cin >> n;
	
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 2) {
			st[i] = true;
			dfs(1, "2");
			st[i] = false;
		}
	}
	
	std::cout << ans;
}
