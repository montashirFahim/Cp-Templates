#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int MX = 200005;

ll a[MX], dp[MX], le[MX], tree[4 * MX];


void build(ll node, ll st, ll en) {
	if (st == en) {
		tree[node] = 0;
		return;
	}
	ll mid = (st + en) / 2;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, en);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
void update(ll node, ll st, ll en, ll in, ll val) {
	if (st == en) {
		tree[node] = val;
		return;
	}
	ll mid = (st + en) / 2;
	if (in <= mid)update(2 * node, st, mid, in, val);
	else update(2 * node + 1, mid + 1, en, in, val);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
ll query(ll node, ll st, ll en, ll l, ll r) {
	if (en < l || st > r)return INT64_MIN;
	if (l <= st && en <= r)return tree[node];
	ll mid = (st + en) / 2;
	return max(query(2 * node, st, mid, l, r), query(2 * node + 1, mid + 1, en, l, r));
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	map<ll, ll>mp;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]] = 1;
	}
	ll c_val = 1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		it->second = c_val++;
	}
	//dp[i]=lis using i in the sequence
	build(1, 1, n);
	for (ll i = 1; i <= n; i++) {
		ll q = query(1, 1, n, 1, mp[a[i]] - 1);
		if (q != INT64_MIN)update(1, 1, n, mp[a[i]], q + 1);
		else update(1, 1, n, mp[a[i]], 1);
	}
	cout << query(1, 1, n, 1, n) << '\n';
}
