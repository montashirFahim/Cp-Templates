const int N = 1e5;

ll n, dt[N];

struct Lazy_Seg_Tree {
	vector<ll>seg, lazy;
	Lazy_Seg_Tree(int n) {
		int k = 1;
		while (k < n)k *= 2;
		seg.resize(2 * k + 5);
		lazy.resize(2 * k + 5);
		fill(seg.begin(), seg.end(), 0);
		fill(lazy.begin(), lazy.end(), 0);
	}

	void build(ll st, ll en, ll nd) {
		if (st == en) {
			seg[nd] = dt[st];
			return;
		}
		ll mid = (st + en) / 2;
		build(st, mid, 2 * nd);
		build(mid + 1, en, 2 * nd + 1);
		seg[nd] = seg[2 * nd] + seg[2 * nd + 1];
	}

	void update(ll st, ll en, ll nd, ll l, ll r, ll val) {
		if (lazy[nd] != 0) {
			ll temp = lazy[nd];
			lazy[nd] = 0;
			seg[nd] += temp * (en - st + 1);
			if (st != en) {
				lazy[2 * nd] += temp;
				lazy[2 * nd + 1] += temp;
			}
		}
		if (st > r || en < l) {
			return;
		}
		if (st >= l && en <= r) {
			seg[nd] += val * (en - st + 1);
			if (st != en) {
				lazy[2 * nd] += val;
				lazy[2 * nd + 1] += val;
			}
			return;
		}
		ll mid = (st + en) / 2;
		update(st, mid, 2 * nd, l, r, val);
		update(mid + 1, en, 2 * nd + 1, l, r, val);
		seg[nd] = seg[2 * nd] + seg[2 * nd + 1];
	}

	ll query(ll st, ll en, ll nd, ll l, ll r) {
		if (lazy[nd] != 0) {
			ll temp = lazy[nd];
			lazy[nd] = 0;
			seg[nd] += temp * (en - st + 1);
			if (st != en) {
				lazy[2 * nd] += temp;
				lazy[2 * nd + 1] += temp;
			}
		}
		if (st > r || en < l) {
			return 0;
		}
		if (st >= l && en <= r) {
			return seg[nd];
		}
		ll mid = (st + en) / 2;
		return query(st, mid, 2 * nd, l, r) + query(mid + 1, en, 2 * nd + 1, l, r);
	}
};

