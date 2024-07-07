#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int n, dis[200005];
vector<int>g[200005];

void dfs(int node, int par) {
	for (int child : g[node]) {
		if (child == par)continue;
		dis[child] = dis[node] + 1;
		dfs(child, node);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	int node = max_element(dis + 1, dis + n + 1) - dis;
	memset(dis, 0, sizeof(dis[0]) * (n + 2));
	dfs(node, -1);
	cout << *max_element(dis + 1, dis + n + 1) << "\n";
}
