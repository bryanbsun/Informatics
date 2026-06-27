#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v, f;
}t[110];
int n,k;
int degree[110];

int     main(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> t[i].v >> t[i].f;
        degree[t[i].f]++;
    }

    cin >> k;
    int x;
    for (int i = 0; i < k; i ++){
        cin >> x;
        cout << degree[x] << endl;
    }

    return 0;
}