#include <bits/stdc++.h>
using namespace std;

int k;
int d[3], p[2];
    
int main(){


    cin >> k;

    for (int i = 0; i < k; i ++){
        for (int j = 0; j < 2; j ++){
            for (int k = 0; k < 3; k ++){
                cin >> d[k];
                if (d[k] == 1) d[k] = 7;
            }

            if (d[0] == d[2] && d[0] == d[1])	p[j] = d[0] * 1000;
            else if (d[0] == d[1])		p[j] = d[0] * 100 + d[2];
            else if (d[1] == d[2])		p[j] = d[1] * 100 + d[0];
            else if (d[0] == d[2])		p[j] = d[0] * 100 + d[1];
            else		                p[j] = d[0] + d[1] + d[2];
        }

        if (p[0] > p[1])            cout << "XiaoMing" << endl;
        else if (p[0] < p[1])       cout << "XiaoWang" << endl;
        else		            cout << "Draw" << endl;
    }

    return 0;
}
