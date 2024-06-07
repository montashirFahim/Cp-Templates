#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>  using orderedSet =
    tree<T, null_type, less<T>,   /// greater<T> for sorting decreasingly
    rb_tree_tag, tree_order_statistics_node_update>;

const ll MAX_N = 1e5 + 10, mod = 2e9 + 63, base1 = 1e9 + 21, base2 = 1e9 + 181;
ll pw1[MAX_N], pw2[MAX_N];

void pw_calc() {
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		pw1[i] = (pw1[i - 1] * base1) % mod;
		pw2[i] = (pw2[i - 1] * base2) % mod;
	}
}

class Hash {
	ll slen;
	string s;
	vector<pair<ll, ll> >t1, t2;
public:
	Hash() {}
	Hash(string _s) {
		s = _s;
		slen = s.size();
		s = "#" + s;
		t1.resize(4 * slen + 5, {0, 0});
		t2.resize(4 * slen + 5, {0, 0});
	}
	void init() {
		build(1, 1, slen);
	}
	pair<ll, ll>merge1(pair<ll, ll>a, pair<ll, ll>b) {
		ll x = ((a.first * pw1[b.second]) % mod + b.first) % mod;
		ll y = a.second + b.second;
		return {x, y};
	}
	pair<ll, ll>merge2(pair<ll, ll>a, pair<ll, ll>b) {
		ll x = ((a.first * pw2[b.second]) % mod + b.first) % mod;
		ll y = a.second + b.second;
		return {x, y};
	}
	void build(ll node, ll st, ll en) {
		if (st == en) {
			t1[node] = {s[en], 1};
			t2[node] = {s[en], 1};
			return;
		}
		ll mid = (st + en) >> 1;
		build(2 * node, st, mid);
		build(2 * node + 1, mid + 1, en);
		t1[node] = merge1(t1[2 * node], t1[2 * node + 1]);
		t2[node] = merge2(t2[2 * node], t2[2 * node + 1]);
	}
	void update(ll node, ll st, ll en, ll i, char v) {
		if (st == en) {
			t1[node] = {v, ((ll)v == 0) ? 0 : 1};
			t2[node] = {v, ((ll)v == 0) ? 0 : 1};
			return;
		}
		ll mid = (st + en) >> 1;
		if (i <= mid)update(2 * node, st, mid, i, v);
		else update(2 * node + 1, mid + 1, en, i, v);
		t1[node] = merge1(t1[2 * node], t1[2 * node + 1]);
		t2[node] = merge2(t2[2 * node], t2[2 * node + 1]);
	}
	pair<ll, ll> query1(ll node, ll st, ll en, ll l, ll r) {
		if (en < l || st > r)return {0, 0};
		if (l <= st && en <= r) {
			return t1[node];
		}
		ll mid = (st + en) >> 1;
		pair<ll, ll>x = query1(2 * node, st, mid, l, r);
		pair<ll, ll>y = query1(2 * node + 1, mid + 1, en, l, r);
		return merge1(x, y);
	}
	pair<ll, ll> query2(ll node, ll st, ll en, ll l, ll r) {
		if (en < l || st > r)return {0, 0};
		if (l <= st && en <= r) {
			return t2[node];
		}
		ll mid = (st + en) >> 1;
		pair<ll, ll>x = query2(2 * node, st, mid, l, r);
		pair<ll, ll>y = query2(2 * node + 1, mid + 1, en, l, r);
		return merge2(x, y);
	}
	inline ll get_hash(ll l, ll r) {
		if (l > r)return 0LL;
		ll hs1 = query1(1, 1, slen, l, r).first;
		ll hs2 = query2(1, 1, slen, l, r).first;
		ll hs = (hs1 << 32) | hs2;
		return hs;
	}
	inline void update(ll i, char x) {
		update(1, 1, slen, i, x);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	pw_calc();
	string s;
	cin >> s;
	ll n = s.size();
	Hash h1(s);
	reverse(s.begin(), s.end());
	Hash h2(s);
	h1.init(); h2.init();
	orderedSet<ll>os;
	for (ll i = 1; i <= n; i++)os.insert(i);
	ll q;
	cin >> q;
	ll cnt = 0;
	for (ll qu = 1; qu <= q; qu++) {
		char x;
		cin >> x;
		if (x == 'C') {
			ll l, r;
			cin >> l >> r;
			ll i = *os.find_by_order(l - 1);
			ll j = *os.find_by_order(r - 1);
			ll f_h = h1.get_hash(i, j);
			ll r_h = h2.get_hash(n - j + 1, n - i + 1);
			if (f_h == r_h)cout << "Yes!\n";
			else cout << "No!\n";
		} else if (x == 'U') {
			ll i; char c;
			cin >> i >> c;
			i = *os.find_by_order(i - 1);
			assert(i <= n);
			h1.update(i, c);
			h2.update(n - i + 1, c);
		} else {
			ll i;
			cin >> i;
			i = *os.find_by_order(i - 1);
			h1.update(i, (char) 0);
			h2.update(n - i + 1, (char) 0);
			os.erase(i);
		}
	}
}
//https://toph.co/p/palindrome-query-i