ll a[N + 5];
struct segmenttree {
	ll seg[4 * N + 5];
	void build(int node, int l, int r) {
		if (r == l) {
			seg[node] = 1;
			return;
		}
		int mid = (r + l) / 2;
		build(2 * node, l, mid);
		build(2 * node + 1, mid + 1, r);
		seg[node] = seg[2 * node] + seg[2 * node + 1];
	}

	void update_point(int node, int st, int en, int pos) {
		if (st == en) {
			seg[node] = 0;
			return;
		}
		int mid = (st + en) / 2;
		if (pos <= mid)update_point(2 * node, st, mid, pos);
		else update_point(2 * node + 1, mid + 1, en, pos);
		seg[node] = seg[2 * node] + seg[2 * node + 1];
	}


	ll query(int node, int st, int en, int l, int r) {
		if (en < l || r < st)return 0;
		if (l <= st && en <= r)return seg[node];
		int mid = (st + en) / 2;
		return query(2 * node, st, mid, l, r) + query(2 * node + 1, mid + 1, en, l, r);
	}
};

