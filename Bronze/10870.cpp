#include <bits/stdc++.h>
using namespace std;

int fibonacii(int x) {
    if (x==0)return 0;
    if (x==1)return 1;
    return fibonacii(x-1) + fibonacii(x-2);
}

int main(){
    int n;
    cin >> n;
    cout << fibonacii(n);
}