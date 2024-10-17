#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MX = 1000005;

int f[MX], ar[MX];
int block_size, cnt;
struct Query {int l, r, idx;};

bool comp(Query a, Query b) {
	int block_a = a.l / block_size;
	int block_b = b.l / block_size;
	if (block_a == block_b) { return a.r < b.r; }
	return block_a < block_b;
}
void remove(int idx) {
	f[ar[idx]]--;
	if (f[ar[idx]] == 0) {cnt--; }
}
void add(int idx) {
	f[ar[idx]]++;
	if (f[ar[idx]] == 1) {cnt++; }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int q;
	cin >> q;
	vector<Query>queries;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		queries.push_back({--l, --r, i});
	}
	cnt = 0;
	block_size = sqrt(n);
	sort(queries.begin(), queries.end(), comp);
	int ml = -1, mr = -1;
	vector<int>ans(q);
	for (int i = 0; i < q; i++) {
		int left = queries[i].l;
		int right = queries[i].r;
		while (ml < left) {remove(ml++);}
		while (ml > left) {add(--ml);}
		while (mr < right) {add(++mr);}
		while (mr > right) {remove(mr--);}
		ans[queries[i].idx] = cnt;
	}
	for (int &x : ans)cout << x << "\n";
}