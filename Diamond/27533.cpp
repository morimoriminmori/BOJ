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
#define ull unsigned ll
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

ll modexp(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int n,m,L;
vi fact,inv;
void __main() {
    cin >> n >> m;
    L = n + m - 4;
    if ( L < 0 ) {
        cout << 0;
        return;
    }
    fact.resize(L+1, 1);
    inv.resize(L+1, 1);
    for (int i = 1; i <= L; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv[L] = modexp(fact[L], MOD - 2);
    for (int i = L; i > 0; i--) {
        inv[i - 1] = inv[i] * i % MOD;
    }

    auto comb = [&](int n, int k) -> ll {
        if (k < 0 || k > n) return 0;
        return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
    };

    ll A = comb(L, m - 2), B = comb(L, m - 1), C = comb(L, n - 1);
    cout << (((A * A % MOD - (B * C % MOD)) % MOD + MOD) % MOD) * 2 % MOD;
}