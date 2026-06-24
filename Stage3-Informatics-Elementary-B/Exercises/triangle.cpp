#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[21][21];

int main(){
    cin >> n >> s;

    for (int j = 1; j <= n; j ++)
        for (int i = 1; i <= j; i ++){
            a[i][j] = (s-1)%9 + 1;
            s ++;
        }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++)
            if (a[i][j])
                cout << setw(4) << a[i][j];
            else 
                cout << setw(4) << " ";
        cout << endl;
    }

    return 0;

}
