#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 3e5 + 9;

struct Trie {
	static const ll B = 31;
	struct node {
		node* nxt[2];
		ll sz;
		node() {
			nxt[0] = nxt[1] = NULL;
			sz = 0;
		}
	}*root;
	Trie() {
		root = new node();
	}
	void insert(ll val) {
		node* cur = root;
		cur -> sz++;
		for (ll i = B - 1; i >= 0; i--) {
			ll b = val >> i & 1;
			if (cur -> nxt[b] == NULL) cur -> nxt[b] = new node();
			cur = cur -> nxt[b];
			cur -> sz++;
		}
	}
	ll query(ll x, ll k) { // number of values s.t. val ^ x < k
		node* cur = root;
		ll ans = 0;
		for (ll i = B - 1; i >= 0; i--) {
			if (cur == NULL) break;
			ll b1 = x >> i & 1, b2 = k >> i & 1;
			if (b2 == 1) {
				if (cur -> nxt[b1]) ans += cur -> nxt[b1] -> sz;
				cur = cur -> nxt[!b1];
			} else cur = cur -> nxt[b1];
		}
		return ans;
	}
	ll get_max(ll x) { // returns maximum of val ^ x
		node* cur = root;
		ll ans = 0;
		for (ll i = B - 1; i >= 0; i--) {
			ll k = x >> i & 1;
			if (cur -> nxt[!k]) cur = cur -> nxt[!k], ans <<= 1, ans++;
			else cur = cur -> nxt[k], ans <<= 1;
		}
		return ans;
	}
	ll get_min(ll x) { // returns minimum of val ^ x
		node* cur = root;
		ll ans = 0;
		for (ll i = B - 1; i >= 0; i--) {
			ll k = x >> i & 1;
			if (cur -> nxt[k]) cur = cur -> nxt[k], ans <<= 1;
			else cur = cur -> nxt[!k], ans <<= 1, ans++;
		}
		return ans;
	}
	void del(node* cur) {
		for (ll i = 0; i < 2; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
		delete(cur);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	for (ll tc = 1; tc <= t; tc++) {
		cout << "Case " << tc << ": ";
		int n;
		cin >> n;
		int cur = 0;
		ll mx = 0, mn = INT32_MAX;
		Trie tr;
		tr.insert(cur);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cur ^= x;
			mx = max(mx, tr.get_max(cur));
			mn = min(mn, tr.get_min(cur));
			// ans -= t.query(cur, k);
			tr.insert(cur);
		}
		tr.del(tr.root);
		cout << mx << " " << mn << '\n';
	}
}
