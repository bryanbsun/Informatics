#include <bits/stdc++.h>
using namespace std;

int     main(){
    for (int i = 100; i < 1000; i ++)
        if (i == (i*i) % 1000)
            cout << i << " ";
    cout << endl;
    return 0;
}