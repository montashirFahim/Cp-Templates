#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>  using orderedSet =
  tree<T, null_type, less<T>,   /// greater<T> for sorting decreasingly
  rb_tree_tag, tree_order_statistics_node_update>;
//declare ordered_set setname
//setname.find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn)
//setname.order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

