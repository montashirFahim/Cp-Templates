#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Trie {
	//N is way big then don't use struct and trie and cnt declare as global array
	//Don't use as Class
	int num, B = 30;
	vector<vector<int> >trie;
	vector<int>cnt;
public:
	Trie() {}
	void init() {
		num = 0;
		cnt.clear(), trie.clear();
		trie.push_back(vector<int>(2)), cnt.push_back(0);
		trie.back()[0] = trie.back()[1] = -1;
	}
	void insert(int val) {
		int node = 0;
		cnt[node]++;
		for (int i = B; i >= 0; i--) {
			int k = val >> i & 1;
			if (trie[node][k] == -1) {
				trie.push_back(vector<int>(2)), cnt.push_back(0);
				trie.back()[0] = trie.back()[1] = -1;
				trie[node][k] = ++num;
			}
			node = trie[node][k];
			cnt[node]++;
		}
	}
	//number of subarray such that xor(a[i])<k
	ll query(int val, int k) {
		ll ans = 0;
		int node = 0;
		for (int i = B; i >= 0; i--) {
			if (node == -1)break;
			int b1 = val >> i & 1, b2 = k >> i & 1;
			if (b2 == 1) {
				if (trie[node][b1] != -1)ans += (ll)cnt[trie[node][b1]];
				node = trie[node][!b1];
			} else {
				node = trie[node][b1];
			}
		}
		return ans;
	}
	int get_max(int val) {
		int node = 0, ans = 0;
		for (int i = B; i >= 0; i--) {
			int k = val >> i & 1;
			if (trie[node][!k] != -1) {
				ans <<= 1; ans++;
				node = trie[node][!k];
			} else {
				ans <<= 1;
				node = trie[node][k];
			}
		}
		return ans;
	}
	int get_min(int val) {
		int node = 0, ans = 0;
		for (int i = B; i >= 0; i--) {
			int k = val >> i & 1;
			if (trie[node][k] != -1) {
				ans <<= 1;
				node = trie[node][k];
			} else {
				ans <<= 1; ans++;
				node = trie[node][!k];
			}
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, k;
		cin >> n >> k;
		int cur = 0;
		Trie tr;
		tr.init();
		tr.insert(0);
		int mx = 0, mn = 1e9 + 2;
		ll ans = (n * (n + 1)) / 2;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cur ^= x;
			mx = max(mx, tr.get_max(cur));
			mn = min(mn, tr.get_min(cur));
			ans -= tr.query(cur, k);
			tr.insert(cur);
		}
		cout << "Case " << tc << ": ";
		cout << ans << " " << mx << " " << mn << "\n";
	}
}
