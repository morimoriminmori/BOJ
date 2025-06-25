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

vi is_prime = sieve(7400000),x;

void init() {
    for (int i=0;i<=1010101;i++) {
        if (is_prime[i])x.push_back(i);
    }
}

void solve(int k) {
    int cnt=0;
    for (int i=k/2; i>=2; i--) {
        int j = k - i;
        if (is_prime[i] && is_prime[j]) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int t;

void __main() {
    loop {
        cin >> t;
        if (t==0)break;
        solve(t);
    }
}