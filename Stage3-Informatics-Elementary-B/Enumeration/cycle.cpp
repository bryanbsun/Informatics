#include <bits/stdc++.h>
using namespace std;

int     main(){
    int p,e,i,d;

    cin >> p >> e >> i >> d;

    for (int dd = 0; dd < 32767; dd ++)
        if ((d+dd - p) % 23 == 0 && (d + dd - e) % 28 == 0 && (d + dd - i) % 33 == 0){
            cout << dd << endl;
            return 0;
        }

    return 0;
}
