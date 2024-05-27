#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
const ll maxn = 2e6 + 5;
ll cnt, par[maxn], rnk[maxn], sz[maxn];

void make_set(ll a) {
	par[a] = a;
	rnk[a] = 1;
	sz[a] = 1;
}

ll find(ll a) {
	if (a == par[a]) return a;
	return par[a] = find(par[a]);
}

void merge(ll a, ll b) {
	ll p1 = find(a);
	ll p2 = find(b);
	if (p1 == p2) {
		return;
	}
	if (p1 > p2) swap(p1, p2);
	par[p1] = p2;
	sz[p2] += sz[p1];
	if (rnk[p1] == rnk[p2]) rnk[p2]++;
	cnt--;
}

bool same(ll a, ll b) {
	return (par[a] == par[b]);
}

ll count() {
	return cnt;
}

ll get_size(ll a) {
	return sz[par[a]];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		make_set(i);
	}

}


