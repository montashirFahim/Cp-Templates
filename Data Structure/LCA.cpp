const ll INF = 1e18;
const int MAXN = 100005;
const int LG = 18;

vector<pair<ll, ll>> g[MAXN];
ll dep[MAXN], sz[MAXN];
ll par[MAXN][LG + 1], mx[MAXN][LG + 1], mn[MAXN][LG + 1];

void dfs(ll u, ll p) {
	sz[u] = 1;
	par[u][0] = p;
	for (int i = 1; i <= LG; i++) {
		par[u][i] = par[par[u][i - 1]][i - 1];
		mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
		mn[u][i] = min(mn[u][i - 1], mn[par[u][i - 1]][i - 1]);
	}
	for (auto x : g[u]) {
		ll v = x.first, w = x.second;
		if (v == p) continue;
		mx[v][0] = w;
		mn[v][0] = w;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
ll lca(ll u, ll v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (ll k = LG; k >= 0; k--) {
		if (dep[par[u][k]] >= dep[v]) {
			u = par[u][k];
		}
	}
	if (u == v) return u;
	for (ll k = LG; k >= 0; k--) {
		if (par[u][k] != par[v][k]) {u = par[u][k]; v = par[v][k];}
	}
	return par[u][0];
}
ll find_max(ll u, ll v) {
	if (dep[u] < dep[v]) swap(u, v);
	ll MX = 0;
	for (ll k = LG; k >= 0; k--) {
		if (dep[par[u][k]] >= dep[v]) {MX = max(MX, mx[u][k]); u = par[u][k];}
	}
	if (u == v) return MX;
	for (ll k = LG; k >= 0; k--) {
		if (par[u][k] != par[v][k]) {MX = max({MX, mx[u][k], mx[v][k]}); u = par[u][k]; v = par[v][k];}
	}
	return max({MX, mx[u][0], mx[v][0]});
}
ll find_min(ll u, ll v) {
	if (dep[u] < dep[v]) swap(u, v);
	ll MN = INF;
	for (ll k = LG; k >= 0; k--) {
		if (dep[par[u][k]] >= dep[v]) {MN = min(MN, mn[u][k]); u = par[u][k];}
	}
	if (u == v) return MN;
	for (ll k = LG; k >= 0; k--) {
		if (par[u][k] != par[v][k]) {MN = min({MN, mn[u][k], mn[v][k]}); u = par[u][k]; v = par[v][k];}
	}
	return min({MN, mn[u][0], mn[v][0]});
}
ll dist(ll u, ll v) {
	ll l = lca(u, v);
	return dep[u] + dep[v] - 2 * dep[l];
}
ll kth(ll u, ll k) {
	assert(k >= 0);
	for (ll i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
	return u;
}
ll go(ll u, ll v, ll k) {
	ll l = lca(u, v);
	ll d = dep[u] + dep[v] - (dep[l] << 1);
	assert(k <= d);
	if (dep[l] + k <= dep[u]) return kth(u, k);
	k -= dep[u] - dep[l];
	return kth(v, dep[v] - dep[l] - k);
}