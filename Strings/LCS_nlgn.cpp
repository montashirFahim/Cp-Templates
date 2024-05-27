#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll MAX_N = 1e6 + 5, mod = 2e9 + 63, base1 = 1e9 + 21, base2 = 1e9 + 181;

ll pw1[MAX_N], pw2[MAX_N];

void pw_calc() {
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		pw1[i] = (pw1[i - 1] * base1) % mod;
		pw2[i] = (pw2[i - 1] * base2) % mod;
	}
}

struct Hash {
	ll slen;
	string s;
	vector<ll>h1, h2;

	Hash(string _s) {
		slen = _s.size();
		s = "#" + _s;
		h1.resize(slen + 1);
		h2.resize(slen + 1);
	}

	void init() {
		h1[0] = h2[0] = 0;
		for (int i = 1; i <= slen; i++) {
			h1[i] = (h1[i - 1] * base1 + s[i]) % mod;
			h2[i] = (h2[i - 1] * base2 + s[i]) % mod;
		}
	}

	inline ll get_hash(int l, int r) {
		ll hsh1 = (h1[r] - h1[l - 1] * pw1[r - l + 1]) % mod;
		if (hsh1 < 0) hsh1 += mod;
		ll hsh2 = (h2[r] - h2[l - 1] * pw2[r - l + 1]) % mod;
		if (hsh2 < 0) hsh2 += mod;
		return (hsh1 << 32) | hsh2;
	}

	inline ll get_hash() {
		return get_hash(1, slen);
	}

	inline ll hashOne(int l, int r) {
		ll hsh1 = (h1[r] - h1[l - 1] * pw1[r - l + 1]) % mod;
		if (hsh1 < 0) hsh1 += mod;
		return hsh1;
	}

	inline ll hashTwo(int l, int r) {
		ll hsh2 = (h2[r] - h2[l - 1] * pw2[r - l + 1]) % mod;
		if (hsh2 < 0) hsh2 += mod;
		return hsh2;
	}
};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	pw_calc();
	string a, b;
	cin >> a >> b;
	Hash h1(a), h2(b);
	h1.init(), h2.init();
	ll n = a.size(), m = b.size();
	ll ans = 0, st = -1, en = -1, lo = 0, hi = min(n, m) + 1;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		map<ll, ll>mp;
		for (ll i = 1; i <= n - mid + 1; i++) {
			mp[h1.get_hash(i, i + mid - 1)] = 1;
		}
		ll ok = 0, str = -1;
		for (ll i = 1; i <= m - mid + 1; i++) {
			ll hs = h2.get_hash(i, i + mid - 1);
			if (mp.find(hs) != mp.end()) {
				ok = 1;
				str = i;
				break;
			}
		}
		if (ok == 1) {
			if (ans < mid) {
				ans = mid;
				st = str;
				en = str + mid - 1;
			}
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << '\n';
	// for (ll i = st - 1; i < en; i++)cout << b[i];
	// cout << "\n";
}