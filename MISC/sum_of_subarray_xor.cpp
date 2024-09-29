#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll ans = 0, Xor = 0;
	vector<ll>a(n + 1, 0), p(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		Xor ^= a[i];
		p[i] = Xor;
	}
	vector<ll>oneCnt(32, 0), zeroCnt(32, 0);
	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j < 32; j++) {
			if (p[i] & (1LL << j))oneCnt[j]++;
			else zeroCnt[j]++;
		}
	}
	for (ll i = 0; i < 32; i++) {
		ll x = oneCnt[i], y = zeroCnt[i], z = 1LL << i;
		ans += (x * y * z);
	}
	cout << ans << "\n";
}
