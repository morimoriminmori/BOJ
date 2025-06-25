#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int parent[1010101];

int Find(int x) {
  if (parent[x]==x)return x;
  return parent[x]=Find(parent[x]);
}

void Union(int x, int y){
  x = Find(x);
  y = Find(y);
  if (x>y){
    parent[x]=y;
  } else {
    parent[y]=x;
  }
}

int main() 
{
    fastio;
    
    for (int i=0;i<1010101;i++) {
      parent[i]=i;
    }
    
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;i++) {
      int cmd,a,b;
      cin >> cmd >> a >> b;
      if (cmd==0) {
        Union(a,b);
      } else {
        if (Find(a)==Find(b)){
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    }
    
    return 0;
}
