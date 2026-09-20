#include <bits/stdc++.h>
using namespace std;

int     main(){
    for (int i = 10000; i < 100000; i ++){
        int d1 = i%10;
        int d2 = i/10%10;
        int d3 = i/100%10;
        int d4 = i/1000%10;
        int d5 = i/10000;

        if (d1 && d2 && d3 && d4 && d5)
            if (d1+d3+d5 == d2+d4)
                if (d1*d3*d5 == d2*d4)
                    cout << i << endl;
    }
    return 0;
}
