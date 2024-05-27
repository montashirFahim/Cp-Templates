#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 10000000;
vector<int> lp(N + 1);
vector<int> pr;
void sieve() {
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}
}

ll NOD(ll n) {
	ll sum = 1LL;
	for (ll i = 0; pr[i]*pr[i] <= n; i++) {
		if (n % pr[i] == 0) {
			ll p = 1LL;
			while (n % pr[i] == 0) {
				n /= pr[i];
				p += 1;
			}
			sum *= p;
		}
	}
	if (n > 1) {
		sum *= 2LL;
	}
	return sum;
}

ll SOD(ll n) {
	ll sum = 1LL;
	for (ll i = 0; pr[i]*pr[i] <= n; i++) {
		if (n % pr[i] == 0) {
			ll p = 1LL;
			while (n % pr[i] == 0) {
				n /= pr[i];
				p *= pr[i];
			}
			p *= pr[i];
			sum *= ((p - 1) / (pr[i] - 1));
		}
	}
	if (n > 1) {
		sum *= ((n * n - 1) / (n - 1));
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll tc;
	cin >> tc;
	// sieve();
	//NOD/SOD with preprocess
	vector<ll>d(1000005, 0);
	for (ll i = 1; i <= 1000000; i++) {
		for (ll j = i; j <= 1000000; j += i) {
			//SOD
			d[j] += i;
			//NOD
			// d[j] += 1;
		}
	}
	while (tc--) {

	}
}
