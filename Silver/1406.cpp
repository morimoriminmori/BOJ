#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int mx=1010101;
int s[mx],e[mx],notused=1;
char x[mx];
void print(){
  int cur=e[0];
  while(cur!=-1){
    cout << x[cur];
    cur=e[cur];
  }
  cout << "\n";
}

void insert(int addr,char num) {
  x[notused]=num;
  s[notused]=addr;
  e[notused]=e[addr];
  if(e[addr]!=-1)s[e[addr]]=notused;
  e[addr]=notused;
  notused+=1;
}

void erase(int addr) {
  e[s[addr]]=e[addr];
  if(s[addr]!=-1)s[e[addr]]=s[addr];
}

int main() 
{   
    fastio;
    memset(s,-1,sizeof(s));
    memset(e,-1,sizeof(e));
    
    string c;
    int q,cur=0;
    cin >> c >> q;
    
    for (auto ch : c){
      insert(cur,ch);
      cur+=1;
    }
    
    while (q--) {
      string cmd;
      cin >> cmd;
      
      if (cmd=="P") {
        char add;
        cin >> add;
        insert(cur,add);
        cur=e[cur];
      } else if (cmd=="L") {
        if (s[cur]!=-1){
          cur=s[cur];
        } 
      } else if (cmd=="D") {
        if (e[cur]!=-1){
          cur=e[cur];
        }
      } else {
        if (s[cur]!=-1){
          erase(cur);
          cur=s[cur];
        }
      }
    }
    print();
    
    return 0;
}
