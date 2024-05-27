#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
const int MX = 100005;

ll a[MX], st[35][MX];

ll f(ll x, ll y) {
	return __gcd(x, y);
}

void build(ll n, ll k) {
	//must initialize k
	for (ll i = 0; i < n; i++)st[0][i] = a[i];
	for (ll i = 1; i <= k; i++) {
		for (ll j = 0; j + (1 << i) <= n; j++) {
			st[i][j] = f(st[i - 1][j], st[i - 1][j + (1LL << (i - 1))]);
		}
	}
}

ll query(ll l, ll r, ll k) {
	ll g = 0;
	for (ll i = k; i >= 0; i--) {
		if ((1 << i) <= r - l + 1) {
			g = f(g, st[i][l]);
			l += (1LL << i);
		}
	}
	return g;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//sparse table
	ll n;
	cin >> n;
	ll k = 0;
	while ((1LL << k) < n) {
		k++;
	}

	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}

	build(n, k);

	return 0;
}

