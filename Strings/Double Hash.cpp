#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll MAX_N = 1e5 + 10, mod = 2e9 + 63, base1 = 1e9 + 21, base2 = 1e9 + 181;
ll pw1[MAX_N], pw2[MAX_N];

void pw_calc() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        pw1[i] = (pw1[i - 1] * base1) % mod;
        pw2[i] = (pw2[i - 1] * base2) % mod;
    }
}

struct Hash {
    ll slen;
    string s;
    vector<ll>h1, h2;

    Hash() {

    }

    Hash(string _s) {
        s = _s;
        slen = s.size();
        s = "#" + s;
        h1.resize(slen + 5);
        h2.resize(slen + 5);
    }

    void init() {
        h1[0] = h2[0] = 0;
        for (int i = 1; i <= slen; i++) {
            h1[i] = (h1[i - 1] * base1 + s[i]) % mod;
            h2[i] = (h2[i - 1] * base2 + s[i]) % mod;
        }
    }

    inline ll get_hash(int l, int r) {
        if (l > r)return 0LL;
        assert(l <= r);
        ll hsh1 = (h1[r] - h1[l - 1] * pw1[r - l + 1]) % mod;
        if (hsh1 < 0) hsh1 += mod;
        ll hsh2 = (h2[r] - h2[l - 1] * pw2[r - l + 1]) % mod;
        if (hsh2 < 0) hsh2 += mod;
        return (hsh1 << 32) | hsh2;
    }

    inline ll get_hash() {
        int l = 1, r = slen;
        if (l > r)return 0LL;
        assert(l <= r);
        ll hsh1 = (h1[r] - h1[l - 1] * pw1[r - l + 1]) % mod;
        if (hsh1 < 0) hsh1 += mod;
        ll hsh2 = (h2[r] - h2[l - 1] * pw2[r - l + 1]) % mod;
        if (hsh2 < 0) hsh2 += mod;
        return (hsh1 << 32) | hsh2;
    }
    inline ll hashOne(int l, int r) {
        if (l > r)return 0LL;
        // assert(l <= r);
        ll hsh1 = (h1[r] - h1[l - 1] * pw1[r - l + 1]) % mod;
        if (hsh1 < 0) hsh1 += mod;
        return hsh1;
    }

    inline ll hashTwo(int l, int r) {
        ll hsh2 = (h2[r] - h2[l - 1] * pw2[r - l + 1]) % mod;
        if (hsh2 < 0) hsh2 += mod;
        return hsh2;
    }
};

int main() {
    pw_calc();

}