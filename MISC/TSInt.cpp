
ll  lo = l - 1, hi = n;
while (hi - lo > 1) {
	ll mid = (hi + lo) >> 1;
	if (f(mid, l, u) > f(mid + 1, l, u))
		hi = mid;
	else
		lo = mid;
}
//lo+1 is the answer

