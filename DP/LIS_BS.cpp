#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll a[100005];

vector<ll> LIS(ll n) {
	//LIS ARRAY
	vector<ll>l(n + 1, 0);
	//BUILT SEQ
	vector<ll>s(n + 1, INT32_MAX);
	s[0] = INT32_MIN;
	for (ll i = 1; i <= n; i++) {
		ll lo = 0, hi = n, mid;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (s[mid] < a[i])lo = mid + 1;
			else hi = mid - 1;
		}
		//Update seq
		s[lo] = a[i];
		//Update lis value
		l[i] = lo;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++)cin >> a[i];
	vector<ll>v = LIS(n);
	// for (ll i = 1; i <= n; i++)cout << v[i] << " ";
	// cout << endl;
	ll lis = *max_element(v.begin() + 1, v.end());
	cout << lis << endl;
}

