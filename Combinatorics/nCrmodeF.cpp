#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
const ll MX = 2e6;
ll fac[MX + 5], inv[MX + 5];
ll bixpo(ll base, ll p) {
	ll ans = 1LL;
	while (p) {
		if (p & 1) {
			ans *= base;
			ans %= mod;
			p--;
		} else {
			base *= base;
			base %= mod;
			p /= 2;
		}
	}
	return ans % mod;
}
void pre() {
	fac[0] = 1;
	for (ll i = 1; i <= MX; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
	for (ll i = 0; i <= MX; i++) {
		inv[i] = bixpo(fac[i], mod - 2);
	}
}
ll nCr(ll N, ll R) {
	if (R == 0)return 1;
	if (R > N)return 0;
	ll a = fac[N];
	ll b = inv[R];
	ll c = inv[N - R];
	ll ans = (a * b) % mod;
	ans = (ans * c) % mod;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	pre();
	ll n, m;
	cin >> n >> m;
	cout << nCr(n + m - 1, n - 1) << '\n';
}