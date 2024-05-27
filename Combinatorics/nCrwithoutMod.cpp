#define ll long long int

//Way 1
ll nCr(ll n, ll k) {
	double res = 1;
	for (ll i = 1; i <= k; ++i)
		res = res * (n - k + i) / i;
	return (ll)(res + 0.01);
}

//Way 2
ll nCr(ll n, ll r)
{
	// p holds the value of n*(n-1)*(n-2)...,
	// k holds the value of r*(r-1)...
	ll p = 1, k = 1;
	// C(n, r) == C(n, n-r),
	// choosing the smaller value
	if (n - r < r)
		r = n - r;
	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;
			// gcd of p, k
			ll m = __gcd(p, k);
			// dividing by gcd, to simplify
			// product division by their gcd
			// saves from the overflow
			p /= m;
			k /= m;
			n--;
			r--;
		}
		// k should be simplified to 1
		// as C(n, r) is a natural number
		// (denominator should be 1 ) .
	}
	else
		p = 1;
	// if our approach is correct p = ans and k =1
	return p;
}