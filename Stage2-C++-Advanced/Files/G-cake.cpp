#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    int m, n;
    int rows[100], cols[100];
    int rc = 0, cc = 0;
    
    memset(rows, 0, sizeof(int)*100);
    memset(cols, 0, sizeof(int)*100);
    
    cin >> m >> n;
    for (int i = 0; i < m; i ++){
        cin >> line;
        for (int j = 0; j < n; j ++)
            if (line[j] == 'S'){
                rows[i] = 1;
                cols[j] = 1;
            }
    }
    
    for (int i = 0; i < m; i ++) rc += (rows[i] == 0);
    for (int i = 0; i < n; i ++) cc += (cols[i] == 0);
    
    cout << rc * n + cc * m - rc * cc;
    
    return 0;
}