#include <bits/stdc++.h>
using namespace std;

int     main(){
    int n;
    cin >> n;

    int i;
    for (i = 2; i * i <= n; i ++)
        if (n%i == 0)
            break;
    if (i*i <= n)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    
    return 0;
}