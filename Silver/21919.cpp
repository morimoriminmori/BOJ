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
#define uniq(x) sort(all(x));x.erase(unique(all(x)), x.end())
#define F first
#define S second
#define mp make_pair
#define MAX 1000002
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884L
#define EPS 1e-9
#define loop while(1)
#define vi vector<ll>
#define i128 __int128
#define vpi vector<pii>
#define vvi vector<vector<ll>>
#define ld long double

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll lcm_list(const vi& v) {
    ll res = v[0];
    for (ll i = 1; i < v.size(); ++i) {
        res = lcm(res, v[i]);
    }
    return res;
}

vi sieve(int n) {
    vi is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i <= n; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = 0;
    }
    return is_prime;
}

ll n,x;
vi arr;

void __main() {
  vi is_prime = sieve(1010101);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> x;
    if (is_prime[x])arr.pb(x);
  }

  if (arr.empty())cout<<-1;
  else cout<<lcm_list(arr);

}
