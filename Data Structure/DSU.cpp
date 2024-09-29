#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

template <typename T>class DisjointSets {
public:
	set<T> p;
	vector<T> sz, par;
	vector<vector<T> >comp;
	DisjointSets(T size) {
		sz.resize(size + 5); par.resize(size + 5); comp.resize(size + 5);
		for (T i = 1; i <= size; i++) {sz[i] = 1; par[i] = i; comp[i].push_back(i); p.insert(i);}
	}
	T get_size(T u) {return sz[find(u)];}
	T find(T x) {return (par[x] == x ? x : par[x] = find(par[x]));}
	void unite(T x, T y) {
		T x_root = find(x);
		T y_root = find(y);
		if (x_root == y_root) { return; }
		if (sz[x_root] < sz[y_root]) { swap(x_root, y_root); }
		if (p.find(y_root) != p.end()) {p.erase(y_root);}
		for (T v : comp[y_root])comp[x_root].push_back(v);
		sz[x_root] += sz[y_root];
		par[y_root] = x_root;
		comp[y_root].clear();
	}
	bool connected(T x, T y) {return find(x) == find(y);}
};

