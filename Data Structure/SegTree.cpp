#include<bits/stdc++.h>
using namespace std;
#define ll long long int

template <class T> class SumSegmentTree {
private:
	const T DEFAULT = 0;
	vector<T> segtree;
	int len;

public:
	SumSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
		}
	}
	T range_sum(int start, int end) {
		T sum = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { sum += segtree[start++]; }
			if (end % 2 == 1) { sum += segtree[--end]; }
		}
		return sum;
	}
};

template <class T> class MinSegmentTree {
private:
	const T DEFAULT = INT64_MAX;
	vector<T> segtree;
	int len;

public:
	MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
	/** Sets the value at ind to val. */
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
		}
	}
	/** @return the minimum element in the range [start, end) */
	T range_min(int start, int end) {
		T min = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { min = std::min(min, segtree[start++]); }
			if (end % 2 == 1) { min = std::min(min, segtree[--end]); }
		}
		return min;
	}
};

template <class T> class MaxSegmentTree {
private:
	const T DEFAULT = 0;
	vector<T> segtree;
	int len;

public:
	MaxSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}
	/** Sets the value at ind to val. */
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = std::max(segtree[ind], segtree[ind ^ 1]);
		}
	}
	/** @return the maximum element in the range [start, end) */
	T range_max(int start, int end) {
		T max = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) {max = std::max(max, segtree[start++]); }
			if (end % 2 == 1) { max = std::max(max, segtree[--end]); }
		}
		return max;
	}
};


int main() {
	ll n, q;
	cin >> n >> q;
	SumSegmentTree<ll>s1(n);
	MaxSegmentTree<ll>s2(n);
	MinSegmentTree<ll>s3(n);
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		s1.set(i, x);
		s2.set(i, x);
		s3.set(i, x);
	}
	while (q--) {

	}
	return 0;
}
