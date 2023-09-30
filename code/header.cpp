#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, \
  tree_order_statistics_node_update> orderedTree;
// usage: find_by_order, order_of_key
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().
  time_since_epoch().count());
// usage: rng()