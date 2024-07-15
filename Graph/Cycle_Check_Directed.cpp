#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 100005;

vector<int>g[N];
vector<int>cycle;
int vis[N], par[N];

int dfs(int v, int p) {
	// cout << v << endl;
	vis[v] = 1;
	for (int u : g[v]) {
		if (!vis[u]) {
			par[u] = v;
			if (dfs(u, v))return 1;
		} else {
			if (vis[u] == 1) {
				int st = u, en = v;
				cycle.push_back(st);
				for (int node = en; node != 0 && node != st; node = par[node]) {
					cycle.push_back(node);
				}
				cycle.push_back(st);
				reverse(cycle.begin(), cycle.end());
				return 1;
			}
		}
	}
	vis[v] = 2;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (dfs(i, 0)) {
				cout << cycle.size() << "\n";
				for (int x : cycle)cout << x << " ";
				cout << "\n";
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
