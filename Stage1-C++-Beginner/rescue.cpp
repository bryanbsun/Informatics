#include <bits/stdc++.h>
using namespace std;
int     n, p;
float   x, y, total = 0.0;

int     main(){
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> x >> y >> p;
        total += sqrt(x*x + y*y)/50 * 2 + 1 * p + 0.5 * p;
    }

    cout << ceil(total) << endl;

    return 0;
}