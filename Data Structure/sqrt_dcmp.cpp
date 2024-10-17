#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MX = 1000005;

template <class T> class Sqrt {
	T n, sz;
	vector<T>a, b;
public:
	Sqrt(vector<T>v) {
		a = v;
		n = v.size();
		sz = (ll)ceil(sqrt(v.size()));
	}
	void init1() {
		b.resize(sz + 1, 0);
		for (int i = 0; i < n; i++)b[i / sz] += a[i];
	}
	void init2() {
		b.resize(sz + 1, INT64_MIN);
		for (int i = 0; i < n; i++)b[i / sz] = max(b[i / sz], a[i]);
	}
	void init3() {
		b.resize(sz + 1, INT64_MAX);
		for (int i = 0; i < n; i++)b[i / sz] = min(b[i / sz], a[i]);
	}
	void update1(T k, T v) {
		b[k / sz] -= a[k - 1];
		a[k - 1] = v;
		b[k / sz] += a[k - 1];
	}
	void update2(T k, T v) {
		a[k - 1] = v;
		T c_l = (k - 1) / sz;
		b[c_l] = INT64_MIN;
		for (int i = c_l * sz; i < min((c_l + 1) * sz, n); i++)b[c_l] = max(b[c_l], a[i]);
	}
	void update3(T k, T v) {
		a[k - 1] = v;
		T c_l = (k - 1) / sz;
		b[c_l] = INT64_MAX;
		for (int i = c_l * sz; i < min((c_l + 1) * sz, n); i++)b[c_l] = min(b[c_l], a[i]);
	}
	T query1(T l, T r) {
		T sum = 0;
		T c_l = (l - 1) / sz, c_r = (r - 1) / sz;
		if (c_l == c_r) {
			for (int i = l - 1; i < r; ++i)sum += a[i];
		} else {
			for (int i = l - 1, end = (c_l + 1) * sz - 1; i <= end; ++i)sum += a[i];
			for (int i = c_l + 1; i < c_r; ++i)sum += b[i];
			for (int i = c_r * sz; i < r; ++i)sum += a[i];
		}
		return sum;
	}
	T query2(T l, T r) {
		T mx = INT64_MIN;
		T c_l = (l - 1) / sz, c_r = (r - 1) / sz;
		if (c_l == c_r) {
			for (int i = l - 1; i < r; ++i)mx = max(mx, a[i]);
		} else {
			for (int i = l - 1, end = (c_l + 1) * sz - 1; i <= end; ++i)mx = max(mx, a[i]);
			for (int i = c_l + 1; i < c_r; ++i)mx = max(mx, b[i]);
			for (int i = c_r * sz; i < r; ++i)mx = max(mx, a[i]);
		}
		return mx;
	}
	T query3(T l, T r) {
		T mn = INT64_MAX;
		T c_l = (l - 1) / sz, c_r = (r - 1) / sz;
		if (c_l == c_r) {
			for (int i = l - 1; i < r; ++i)mn = min(mn, a[i]);
		} else {
			for (int i = l - 1, end = (c_l + 1) * sz - 1; i <= end; ++i)mn = min(mn, a[i]);
			for (int i = c_l + 1; i < c_r; ++i)mn = min(mn, b[i]);
			for (int i = c_r * sz; i < r; ++i)mn = min(mn, a[i]);
		}
		return mn;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<ll>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	Sqrt<ll>sq(v);
	sq.init3();
	for (int i = 0; i < q; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			v[b - 1] = c;
			sq.update3(b, c);
		} else {
			if (b == c)cout << v[b - 1] << "\n";
			else cout << sq.query3(b, c) << "\n";
		}
	}
}
