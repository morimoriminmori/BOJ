#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
void __main();
const long long INF = 1e18;
int main(){
  fastio;
  __main();
  return 0;
}
#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define mp make_pair
#define setbits(x) __builtin_popcountll(x)
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep1(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i > b; i--)
#define per1(i, a, b) for (int i = a; i >= b; i--)
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define lowerbound(x, y) lower_bound(all(x), y) - x.begin()
#define upperbound(x, y) upper_bound(all(x), y) - x.begin()
#define setbits(x) __builtin_popcountll(x)
#define poly vector<ll>
#define poly2 vector<pii>
#define MAX 1010101
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884L
#define EPS 1e-9
#define func(x) [](auto& x) -> decltype(auto)
#define getbit(x, i) (((x) >> (i)) & 1)
#define setbit(x, i) ((x) | (1LL << (i)))
#define clearbit(x, i) ((x) & ~(1LL << (i)))
#define togglebit(x, i) ((x) ^ (1LL << (i)))
#define isbit(x, i) (((x) >> (i)) & 1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) / __gcd(a, b) * (b))
#define allmin(x) *min_element(all(x))
#define allmax(x) *max_element(all(x))
#define allsum(x) accumulate(all(x), 0LL)
#define allprod(x) accumulate(all(x), 1LL, multiplies<ll>())
#define allsort(x) sort(all(x))
#define allrev(x) reverse(all(x))
#define allunique(x) x.erase(unique(all(x)), x.end())
#define allcount(x, y) count(all(x), y)
#define allfind(x, y) find(all(x), y)
#define allfind_if(x, y) find_if(all(x), y)
#define allfind_if_not(x, y) find_if_not(all(x), y)
#define allbinary_search(x, y) binary_search(all(x), y)
#define alllower_bound(x, y) lower_bound(all(x), y)
#define allupper_bound(x, y) upper_bound(all(x), y)
#define allequal(x, y) equal(all(x), all(y))
#define alllexicographical_compare(x, y) lexicographical_compare(all(x), all(y))
#define str string
#define pq priority_queue
#define pqg priority_queue<ll, vector<ll>, greater<ll>>
#define pqg2 priority_queue<pii, vector<pii>, greater<pii>>
#define loop while(1)
#define initing(x,y) for (int i = 0; i < 101010; i++) x[i] = y;
////////////////////////////////////
ll tree[MAX];
ll arr[MAX];

void add(ll target, ll value) {
	if (target <= 0 || target >= MAX) return;
	for (int i=target; i < MAX; i += (i & -i)) {
		tree[i] += value;
	}
}

ll sum(ll target) {
	if (target <= 0) return 0;
	if (target >= MAX) target = MAX - 1;
	ll ret = 0;
	for (int i = target; i > 0; i -= (i & -i)) {
		ret += tree[i];
	}
	return ret;
}


void update(ll target, ll value) {
	add(target,value);
}

ll query(ll start, ll end) {
    if (start > end) swap(start, end);
	return sum(end) - sum(start - 1);
}

void update2(ll target, ll value) {
	ll current = query(target, target);
	add(target, value - current);
}

//////// 2d segtree

int tree2d[1026][1026];

void add2d(int x, int y, int value) {
	for (int i = x; i < 1026; i += (i & -i)) {
		for (int j = y; j < 1026; j += (j & -j)) {
			tree2d[i][j] += value;
		}
	}
}

int sum2d(int x, int y) {
	int ret = 0;

	for (int i = x; i > 0; i -= (i & -i)) {
		for (int j = y; j > 0; j -= (j & -j)) {
			ret += tree2d[i][j];
		}
	}

	return ret;
}

int query2d(int x1, int y1, int x2, int y2) {
	return sum2d(x2, y2) - sum2d(x1 - 1, y2) - sum2d(x2, y1 - 1) + sum2d(x1 - 1, y1 - 1);
}

void update2d(int x, int y, int value) {
	add2d(x, y, value);
}

void update2d2(int x, int y, int value) {
	int current = query2d(x, y, x, y);
	add2d(x, y, value - current);
}

void __main() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> tmp = v;
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());

    for (int i = 0; i < n; i++) {
        v[i] = lower_bound(all(tmp), v[i]) - tmp.begin() + 1; // 1-based
    }

    fill(tree, tree + MAX, 0);
    ll ret = 0;
    for (int i = n - 1; i >= 0; i--) {
        ret += sum(v[i] - 1);
        add(v[i], 1);
    }

    cout << ret << endl;
}
