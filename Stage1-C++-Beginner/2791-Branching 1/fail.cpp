#include <bits/stdc++.h>
using namespace std;

int     main(){
    int m, e;
    cin >> m >> e;

    bool fm, fe;
    fm = m < 60;
    fe = e < 60;

    if (fm != fe)
        cout << 1;
    else    
        cout << 0;
        
    return 0;
}