#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7, N = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {
	return uniform_int_distribution<ll>(l, r)(rng);
}

ll n, x[N], h[N];
vector<ll>g[2][N];

ll get(int id, int u, int par) {
	map<ll, ll>mp;
	vector<ll>childs;
	for (int child : g[id][u]) {
		if (child - par) {
			childs.push_back(get(id, child, u));
			mp[childs.back()]++;
			h[u] = max(h[child] + 1, h[u]);
		}
	}
	if (childs.empty())return 1LL;
	ll res = 1LL;
	for (ll val : childs)res = (res * (x[h[u]] + val)) % mod;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < N; i++) {
		x[i] = (rand(1, 1e9) * rand(1, 1e9)) % mod;
	}
	cin >> n;
	for (ll i = 1; i < n; i++) {
		ll u, v;
		cin >> u >> v;
		g[0][u].push_back(v);
		g[0][v].push_back(u);
	}
	for (ll i = 1; i < n; i++) {
		ll u, v;
		cin >> u >> v;
		g[1][u].push_back(v);
		g[1][v].push_back(u);
	}
	ll firstTree = get(0, 1, -1);
	ll secondTree = get(1, 1, -1);
	cout << (firstTree == secondTree ? "Isomorphic" : "Not Isomorphic") << "\n";
}
