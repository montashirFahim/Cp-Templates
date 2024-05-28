#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a[N], h[N], csum[N];

ll p(ll base, ll pow) {
	ll ans = 1LL;
	while (pow) {
		if (pow & 1) {
			ans *= base; ans %= mod; pow--;
		} else {
			base *= base; base %= mod; pow /= 2;
		}
	}
	return ans % mod;
}
template <class T> class BIT {
private:
	int size;
	vector<T> bit;
	vector<T> arr;
public:
	BIT() {}
	BIT(int _size) {
		size = _size;
		bit.resize(size + 2);
		arr.resize(size + 2);
	}
	//1 based indexed
	/** Sets the value at index ind to val. */
	void set(int ind, T val) {
		ll x = val - arr[ind];
		x %= mod;
		if (x < 0)x += mod;
		add(ind, x);
	}
	/** Adds val to the element at index ind. */
	void add(int ind, T val) {
		arr[ind] += val;
		for (; ind <= size; ind += (ind & -ind)) { bit[ind] += val; bit[ind] %= mod; }
	}
	T query(int ind) {
		T total = 0;
		for (; ind >= 1; ind -= (ind & -ind)) { total += bit[ind]; total %= mod; }
		return total % mod;
	}
	//returns sum from l to r
	T query(int l, int r) {
		ll val = query(r) - query(l - 1);
		val %= mod;
		if (val < 0)val += mod;
		return val;
	}
};


int main() {
	ll n, q;
	cin >> n >> q;
	iota(h, h + n + 1, 0);
	shuffle(h + 1, h + n + 1, rng);
	for (ll i = 1; i <= n; i++)h[i] = p(2, h[i]);
	for (ll i = 1; i <= n; i++)csum[i] = (csum[i - 1] + h[i]) % mod;
	BIT<ll>bt(n);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		bt.add(i, h[a[i]]);
	}
	while (q--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll m = (c - b + 1);
			ll hs = csum[m];
			if (bt.query(b, c) == hs)cout << "YES\n";
			else cout << "NO\n";
		} else {
			bt.set(b, h[c]);
		}
	}
	return 0;
}