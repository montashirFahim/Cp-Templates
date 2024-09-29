#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll MX = sqrt(1e9);

vector<ll>marked(MX + 5, 1), pr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll l, r;
	cin >> l >> r;
	marked[0] = marked[1] = 0;
	for (ll i = 2; i <= MX; i++) {
		if (marked[i]) {
			for (ll j = 2 * i; j <= MX; j += i)
				marked[j] = 0;
		}
	}
	for (ll i = 2; i <= MX; i++)if (marked[i])pr.push_back(i);
	vector<ll>nums(r - l + 1), pf(r - l + 1, 0);
	iota(nums.begin(), nums.end(), l);
	for (ll x : pr) {
		if (x * x > r)break;
		for (ll i = ((l + x - 1) / x) * x; i <= r; i += x) {
			ll idx = i - l;
			while (nums[idx] % x == 0) {
				nums[idx] /= x;
				pf[idx]++;
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i < r - l + 1; i++) {
		if (nums[i] > 1)pf[i]++;
		assert(pf[i] < 33);
		if (marked[pf[i]])ans++;
	}
	cout << ans << "\n";
}