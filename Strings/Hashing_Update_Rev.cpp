#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll MAX_N = 2e5 + 10, mod = 2e9 + 63, base1 = 1e9 + 21, base2 = 1e9 + 181;
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
	vector<ll>t1, t2;
public:
	Hash() {}
	Hash(string _s) {
		s = _s;
		slen = s.size();
		s = "#" + s;
		t1.resize(4 * slen + 5, 0);
		t2.resize(4 * slen + 5, 0);
	}
	void init() {
		build(1, 1, slen);
	}
	void build(ll node, ll st, ll en) {
		if (st == en) {
			t1[node] = s[en];
			t2[node] = s[en];
			return;
		}
		ll mid = (st + en) >> 1;
		build(2 * node, st, mid);
		build(2 * node + 1, mid + 1, en);
		t1[node] = ((t1[node * 2] * pw1[en - mid]) % mod + t1[2 * node + 1]) % mod;
		t2[node] = ((t2[node * 2] * pw2[en - mid]) % mod + t2[2 * node + 1]) % mod;
	}
	void update(ll node, ll st, ll en, ll i, ll v) {
		if (st == en) {
			t1[node] = v;
			t2[node] = v;
			return;
		}
		ll mid = (st + en) >> 1;
		if (i <= mid)update(2 * node, st, mid, i, v);
		else update(2 * node + 1, mid + 1, en, i, v);
		t1[node] = ((t1[node * 2] * pw1[en - mid]) % mod + t1[2 * node + 1]) % mod;
		t2[node] = ((t2[node * 2] * pw2[en - mid]) % mod + t2[2 * node + 1]) % mod;
	}
	pair<ll, ll> query1(ll node, ll st, ll en, ll l, ll r) {
		if (en < l || st > r)return {0, 0};
		if (l <= st && en <= r) {
			return {t1[node], en - st + 1};
		}
		ll mid = (st + en) >> 1;
		pair<ll, ll>x = query1(2 * node, st, mid, l, r);
		pair<ll, ll>y = query1(2 * node + 1, mid + 1, en, l, r);
		ll a = ((x.first * pw1[y.second]) % mod + y.first) % mod;
		ll b = x.second + y.second;
		return {a, b};
	}
	pair<ll, ll> query2(ll node, ll st, ll en, ll l, ll r) {
		if (en < l || st > r)return {0, 0};
		if (l <= st && en <= r) {
			return {t2[node], en - st + 1};
		}
		ll mid = (st + en) >> 1;
		pair<ll, ll>x = query2(2 * node, st, mid, l, r);
		pair<ll, ll>y = query2(2 * node + 1, mid + 1, en, l, r);
		ll a = ((x.first * pw2[y.second]) % mod + y.first) % mod;
		ll b = x.second + y.second;
		return {a, b};
	}
	inline ll get_hash(ll l, ll r) {
		if (l > r)return 0LL;
		ll hs1 = query1(1, 1, slen, l, r).first;
		ll hs2 = query2(1, 1, slen, l, r).first;
		ll hs = (hs1 << 32) | hs2;
		return hs;
	}
	inline void update(ll i, char x) {
		update(1, 1, slen, i, (ll)x);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	pw_calc();
	ll n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	Hash h1(s);
	reverse(s.begin(), s.end());
	Hash h2(s);
	h1.init(); h2.init();
	for (ll i = 0; i < m; i++) {
		ll a;
		cin >> a;
		if (a == 1) {
			ll k;
			char x;
			cin >> k >> x;
			h1.update(k, x);
			h2.update(n - k + 1, x);
		} else {
			ll l, r;
			cin >> l >> r;
			ll hs1 = h1.get_hash(l, r);
			ll hs2 = h2.get_hash(n - r + 1, n - l + 1);
			if (hs1 == hs2)cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
