#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int MX = 200005;


vector<ll>g[MX];
ll vis[MX], par[MX];
ll cycle_end, cycle_start;

bool dfs(ll node, ll p) {
	vis[node] = 1;
	for (ll child : g[node]) {
		if (child == p)continue;
		if (vis[child]) {
			cycle_start = child;
			cycle_end = node;
			return true;
		}
		par[child] = node;
		if (dfs(child, node))
			return true;
	}
	return false;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;

	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	cycle_start = -1;
	for (ll i = 1; i <= n; i++) {
		if (!vis[i] && dfs(i, i)) {
			break;
		}
	}

	if (cycle_start == -1) {
		cout << "IMPOSSIBLE\n";
	} else {
		// cout << cycle_start << " " << cycle_end << "\n";
		vector<ll>cycle;
		cycle.push_back(cycle_start);
		for (ll v = cycle_end; v != cycle_start; v = par[v]) {
			cycle.push_back(v);
		}
		cycle.push_back(cycle_start);
		cout << cycle.size() << "\n";
		for (ll v : cycle)cout << v << " ";
		cout << "\n";
	}

	return 0;
}
