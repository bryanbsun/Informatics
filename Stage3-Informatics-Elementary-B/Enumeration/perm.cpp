#include <bits/stdc++.h>
using namespace std;

int     main(){
    vector<string> a{"abc","def","ghi"};

    do{

        for (auto x:a)
            cout << x << " ";
        cout << endl;
    }while(next_permutation(a.begin(),a.end()));

    return 0;
}
