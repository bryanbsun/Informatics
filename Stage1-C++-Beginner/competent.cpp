#include <bits/stdc++.h>
using namespace std;
int n, x, counter = 0;

int main(){
    cin >> n;

    for (int i = 0; i < n; i ++){
        cin >> x;
        int a = x % 10;
        int b = x / 10 % 10;
        int c = x / 100 % 10;
        int d = x / 1000;

        if (a - b - c - d > 0)
            counter ++;
    }

    cout << counter << endl;
    return 0;
}