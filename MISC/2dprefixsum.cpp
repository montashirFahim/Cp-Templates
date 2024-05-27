#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vecto<ll> >v(n + 1, m + 1);
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cin >> v[i][j];
            }
        }
        vector<vector<ll> >p(n + 1, vector<ll>(m + 1, 0));
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                p[i][j] = v[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            }
        }
        //from (a,b) to (c,d)
        ll a, b, c, d;
        cout << p[c][d] - p[a - 1][d] - p[c][b - 1] + p[a - 1][b - 1] << "\n";
    }
}