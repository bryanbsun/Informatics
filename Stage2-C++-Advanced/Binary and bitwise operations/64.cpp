#include <bits/stdc++.h>
using namespace std;

int     main(){
    string s;
    
    cin >> s;

    int n = s.size();
    int z = 0, zn = 0;
    for (int i = n-1; i >= 0; i --){
        if (s[i] == '0')
            z ++;
        if (s[i] == '1')
            zn = z;
    }
    
    if (zn >= 6) 
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
