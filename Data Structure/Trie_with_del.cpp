#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
const int MX = 31 * 500005;

int num, B = 30;
int cnt[MX], trie[MX][2];

void init() {
	num = 0;
	memset(trie, -1, sizeof(trie));
}
void insert(int val) {
	int node = 0;
	cnt[node]++;
	for (int i = B; i >= 0; i--) {
		int k = val >> i & 1;
		if (trie[node][k] == -1) {
			trie[node][k] = ++num;
		}
		node = trie[node][k];
		cnt[node]++;
	}
}
void del(int val) {
	int node = 0;
	cnt[node]--;
	for (int i = B; i >= 0; i--) {
		int k = val >> i & 1;
		if (trie[node][k] == -1) {
			break;
		}
		int prev = node;
		node = trie[node][k];
		cnt[node]--;
		if (cnt[node] == 0) {
			trie[prev][k] = -1;
		}
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	init();
	//becareful about input format if operation 3 will not be done when set is empty then no need to add 0
	insert(0);
	map<int, int>mp;
	for (int i = 0; i < q; i++) {
		assert(num <= MX);
		char x;
		cin >> x;
		if (x == '+') {
			int val;
			cin >> val;
			if (mp.find(val) == mp.end()) {
				insert(val);
			}
			mp[val]++;
		} else if (x == '-') {
			int val;
			cin >> val;
			mp[val]--;
			if (mp[val] == 0) {
				mp.erase(val);
				del(val);
			}
		} else if (x == '?') {
			int val;
			cin >> val;
			cout << get_max(val) << "\n";
		}
	}
}
