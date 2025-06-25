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

ll a,b,cnt=1,ret=0,temp=0;
vi vec;
void __main() {
  cin >> a >> b;
  vec.resize(a);
  for (ll i=0;i<a;i++)cin>>vec[i];
  sort(all(vec));
  ll i;
  for (i=a-2;i>=0;i--) {
    if (vec[i]!=vec[i+1]) {
      ret=max(ret,min(a-i-1,cnt+b));
      cnt=1;
    } else {
      cnt+=1;
    }
  }
  ret=max(ret,min(a-i-1,cnt+b));
  cout << ret;
}
