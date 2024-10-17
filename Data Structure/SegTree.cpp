int a[MX], t[4 * MX];
void build(int node, int st, int en) {
    if (st == en) {
        t[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build((2 * node) + 1, mid + 1, en);
    t[node] = min(t[2 * node], t[(2 * node) + 1]);
}
void update(int node, int st, int en, int idx, int v) {
    if (st == en) {
        t[node] = v;
        return;
    }
    int mid = (st + en) / 2;
    if (idx <= mid)update(node * 2, st, mid, idx, v);
    else update((2 * node) + 1, mid + 1, en, idx, v);
    t[node] = min(t[2 * node], t[(2 * node) + 1]);
}
int query(int node, int st, int en, int l, int r) {
    if (r < st || en < l)return INT32_MAX;
    if (l <= st && en <= r)return t[node];
    int mid = (st + en) / 2;
    int a = query(2 * node, st, mid, l, r);
    int b = query((2 * node) + 1, mid + 1, en, l, r);
    return min(a, b);
}
