#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
#define ll long long
#define vi vector<ll>

int t, n;
vi x;

void init() {
  x.clear();
}

void __main() {
  cin >> t;
  while (t--) {
    cin >> n;
    init();
    x.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }

    for (int i = 1; i < n - 1; i++) {
      if (x[i] != x[i - 1] + 1 && x[i + 1] == x[i - 1] + 1) {
        cout << i + 1 << endl; 
        break;
      }
    }
  }
}

int main() {
  fastio;
  __main();
  return 0;
}
