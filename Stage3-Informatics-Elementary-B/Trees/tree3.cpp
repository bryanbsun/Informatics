#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    int f;
}t[110];

int n, k, sum[110];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> t[i].v >> t[i].f;
        sum[t[i].f] += t[i].v;
    }

    int x;
    cin >> k;
    for (int i = 0; i < k; i ++){
        cin >> x;
        cout << sum[x] << endl;
    }
    
    return 0;
}