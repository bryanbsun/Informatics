#include <bits/stdc++.h>
using namespace std;
int n, x, sum = 0;
int main(){
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> x;
        sum += x; // sum = sum + x;

    }
    cout << sum << " " << fixed << setprecision(5) << (float)sum/n << endl;
}