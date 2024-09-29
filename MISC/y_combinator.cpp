#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

int main() {
    int T; //read T
    while (T--) {
        int n; //read n
        vector<vector<int>> adj(n) //read adj
        auto dfs = y_combinator([&](const auto & self, int u, int par)->void{
            for (auto &x : adj[u]) {
                if (x == par)
                    continue;
                self(x, u);
            }
        });
        dfs(0, -1);
    }
    return 0;
}
