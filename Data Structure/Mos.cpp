#include <bits/stdc++.h>
using namespace std;

#define block 320
#define ll long long
ll ara[100009], ans[100009], answer = 0, cnt[100009];

struct query {
	ll l, r, i;
} qry[100009];

bool compare(query a, query b) {
	ll tmp = a.l / block;
	if (tmp != b.l / block) {
		return a.l < b.l;
	}
	if ( tmp & 1)
		return a.r < b.r;
	return a.r > b.r;
}

inline void del(ll indx) {
	cnt[ ara[indx] ]--;
	if (cnt[ ara[indx] ] == 0)
		answer--;
}

inline void add(ll indx) {
	cnt[ ara[indx] ]++;
	if (cnt[ ara[indx] ] == 1)
		answer++;
}

int main() {
	ll t, caseno = 0;
	cin >> t;
	while (t--) {
		ll n, q;
		cin >> n >> q;
		answer = 0;
		for (ll i = 0; i < n; i++)cin >> ara[i];
		for (ll i = 0; i < q; i++) {
			cin >> qry[i].l >> qry[i].r;
			qry[i].l--;
			qry[i].r--;
			qry[i].i = i;
		}
		sort(qry, qry + q, compare);
		ll curl = 0, curr = 0;
		for (ll i = 0; i < q; i++) {
			while (curl < qry[i].l) {
				del(curl);
				curl++;
			}
			while (curl > qry[i].l) {
				add(curl - 1);
				curl--;
			}
			while (curr <= qry[i].r) {
				add(curr);
				curr++;
			}
			while (curr > qry[i].r + 1) {
				del(curr - 1);
				curr--;
			}
			ans[ qry[i].i ] = answer;
		}

		cout << ++caseno << ": ";
		for (ll i = 0; i < q; i++)cout << ans[i] << "\n";

		for (ll i = 0; i <= 100000; i++)
			cnt[i] = 0;

	}

	return 0;
}
