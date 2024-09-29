#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll MX = 1e5 + 5;
const ll INF = -1e14;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> adj(n + 1);
	vector<vector<ll>> edges;
	for (ll i = 0; i < m; i++) {
		ll x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		edges.push_back({x, y, w});
	}
	vector<ll> dist(n + 1, 0);
	dist[1] = 0;
	for (ll i = 0; i < n; i++) {
		for (auto &edge : edges) {
			ll u = edge[0];
			ll v = edge[1];
			ll w = edge[2];
			if (dist[u] != LLONG_MAX) {
				dist[v] = min(dist[v], dist[u] + w);
			}
		}
	}
	bool f = true;
	vector<ll> par(n + 1, -1);
	for (ll i = 0; i < n; i++) {
		for (auto &edge : edges) {
			ll u = edge[0];
			ll v = edge[1];
			ll w = edge[2];
			if (dist[u] != LLONG_MAX) {
				ll z = dist[v];
				dist[v] = min(dist[v], dist[u] + w);
				if (dist[v] != z) {
					f = false;
					par[v] = u;
				}
			}
		}
	}
	if (f) {
		cout << "NO\n";
	}
	else {
		ll x = 0;
		for (ll i = 1; i <= n; i++) {
			if (par[i] != -1) {
				x = i;
				break;
			}
		}
		vector<ll> cycle;
		unordered_set<ll> st;
		while (st.find(x) == st.end()) {
			cycle.push_back(x);
			st.insert(x);
			x = par[x];
		}
		cycle.push_back(x);
		reverse(cycle.begin(), cycle.end());
		cout << "YES\n";
		unordered_set<ll> final;
		for (auto &i : cycle) {
			cout << i << " ";
			if (final.find(i) != final.end()) {
				break;
			}
			final.insert(i);
		}
	}
}
