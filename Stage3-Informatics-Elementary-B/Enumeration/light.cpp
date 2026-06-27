#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[7][8]{0};
    int b[7][8]{0};
    int c[7][8]{0};
    
    for (int i = 1; i <= 5; i ++ )
        for (int j = 1; j <= 6; j ++)
            cin >> a[i][j];

    for (int i = 0; i < 64; i ++){
        memcpy(b, a, sizeof(a));

        for (int j = 0; j < 6; j ++)
            c[1][j+1] = (i >> j) & 1;

        for (int j = 1; j <= 6; j ++){
            b[1][j] = b[1][j] ^ c[1][j - 1] ^ c[1][j] ^ c[1][j + 1];
            b[2][j] = b[2][j] ^ c[1][j];
        }
            
        for (int j = 2; j <= 5; j ++){
            for (int k = 1; k <= 6; k ++)
                c[j][k] = b[j-1][k];
            for (int k = 1; k <= 6; k ++){
                b[j][k] = b[j][k] ^ c[j][k-1] ^ c[j][k] ^ c[j][k+1];
                b[j+1][k] = b[j+1][k] ^ c[j][k];
            }
        }

        bool flag = true;
        for (int j = 1; j <= 6; j ++)
                if (b[5][j])
                    flag = false;

        if (flag){
            for (int j = 1; j <= 5; j ++){
                for (int k = 1; k <= 6; k ++)
                    cout << c[j][k] << " ";
                cout << endl;
            }
        }
    }
        return 0;
}
