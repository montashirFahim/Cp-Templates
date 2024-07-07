#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int MX = 200005;

vector<ll>g[MX];
ll dis1[MX], dis2[MX];

void dfs1(ll node, ll par) {
	for (ll child : g[node]) {
		if (child != par) {
			dis1[child] = dis1[node] + 1;
			dfs1(child, node);
		}
	}
}

void dfs2(ll node, ll par) {
	for (ll child : g[node]) {
		if (child != par) {
			dis2[child] = dis2[node] + 1;
			dfs2(child, node);
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1; i < n; i++) {
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(dis1, 0, sizeof(dis1[0]) * (n + 2));
	dfs1(1, -1);
	ll node = max_element(dis1 + 1, dis1 + n + 1) - dis1;
	memset(dis2, 0, sizeof(dis2[0]) * (n + 2));
	dfs2(node, -1);
	node = max_element(dis2 + 1, dis2 + n + 1) - dis2;
	memset(dis1, 0, sizeof(dis1[0]) * (n + 2));
	dfs1(node, -1);
	for (ll i = 1; i <= n; i++) {
		cout << max(dis1[i], dis2[i]) << " ";
	}
	cout << '\n';

	return 0;
}