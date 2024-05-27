const int MX = 200005;

vector<ll>vis(MX, 0);
vector<pair<ll, ll> >g[MX];
vector<ll>dis(MX, INT64_MAX);

void dijkstra(ll s) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, s});
	dis[s] = 0;
	while (!pq.empty()) {
		ll u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto e : g[u]) {
			ll v = e.first;
			ll w = e.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
}
