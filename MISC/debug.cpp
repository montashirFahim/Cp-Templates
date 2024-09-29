#include <bits/stdc++.h>
 
using namespace std;
 
#define ll              long long
#define l1(i, n)        for (ll i = 1; i <= n; i++)
#define l0(i, n)        for (ll i = 0; i < n; i++)
#define pb              push_back
#define xx              first
#define yy              second
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define ms(a, b)        memset(a, b, sizeof(a));
#define cases(tc)       cout<<"Case #"<<tc<<": "
#define nl              cout<<"\n";
#define pi              acos(-1)
#define mod             1000000007
#define inf             1000000000000000001
#define maxn            200001




#define Gene template< class
#define Rics printer& operator,
Gene c > struct rge {c b, e;};
Gene c > rge<c> range(c i, c j) { return {i, j};}
struct printer {
    ~printer() {cerr << endl;}
    Gene c > Rics(c x) { cerr << boolalpha << x; return *this;}
    Rics(string x) {cerr << x; return *this;}
    Gene c, class d > Rics(pair<c, d> x) { return *this, "(", x.first, ", ", x.second, ")";}
    Gene ... d, Gene ... > class c > Rics(c<d...> x) { return *this, range(begin(x), end(x));}
    Gene c > Rics(rge<c> x) {*this, "["; for (auto it = x.b; it != x.e; ++it)*this, (it == x.b ? "" : ", "), *it; return *this, "]";
    }
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
    }
    return 0;
}
