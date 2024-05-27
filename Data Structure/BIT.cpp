#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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
	void set(int ind, T val) { add(ind, val - arr[ind]); }
	/** Adds val to the element at index ind. */
	void add(int ind, T val) {
		arr[ind] += val;
		for (; ind <= size; ind += (ind & -ind)) { bit[ind] += val; }
	}
	//Range Update
	void range_add(int l, int r, int val) {
		add(l, val);
		add(r + 1, -val);
	}
	//Point Query
	T point_query(int idx) {
		T ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))
			ret += bit[idx];
		return ret;
	}
	/** @return The sum of all values in [1, ind]. */
	T query(int ind) {
		T total = 0;
		for (; ind >= 1; ind -= (ind & -ind)) { total += bit[ind]; }
		return total;
	}
	//returns sum from l to r
	T query(int l, int r) {
		return query(r) - query(l - 1);
	}
};


int main() {
	ll t;
	cin >> t;
	for (ll tc = 1; tc <= t; tc++) {
		cout << "Case " << tc << ":\n";
		ll n, q;
		string s;
		cin >> s;
		cin >> q;
		n = s.size();
		BIT<ll>bt(n);
		for (ll i = 1; i <= n; i++)bt.set(i, 0);
		while (q--) {
			char x;
			cin >> x;
			if (x == 'I') {
				ll a, b;
				cin >> a >> b;
				bt.range_add(a, b, 1);
			} else {
				ll in;
				cin >> in;
				ll val = s[in - 1] - '0';
				ll sum = bt.point_query(in);
				if (sum & 1)val ^= 1;
				cout << val << "\n";
			}
		}

	}
	return 0;
}
