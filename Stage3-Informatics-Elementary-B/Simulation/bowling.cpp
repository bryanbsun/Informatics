#include <bits/stdc++.h>
using namespace std;

int s[11][4]{0}, n, f=1, t=1;

void    print(){
    for (int j = 1; j <= 3; j ++){
        for (int i = 1; i <= 10; i ++)
            if (s[i][j])
                printf("%3d", s[i][j]);
            else 
                printf("   ");
        printf("\n");
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> s[f][t];
        if (t == 3){
            f ++;
            t = 1;
        }else if (t == 2 && f < 10){
            f ++;
            t = 1;
        }else if (t == 2 && f == 10 && s[f][t-1] + s[f][t] < 10){
            f ++;
            t = 1;
        }else if (t == 1 && f < 10 && s[f][t] == 10){
            f ++;
            t = 1;
        }else{
            t ++;
        }

        if (f>10){
            int total = 0;
            for (int i = 1; i <= 10; i ++)
                total += s[i][1] + s[i][2] + s[i][3];

            for (int i = 1; i <= 9; i ++)
                if (s[i][1] == 10){
                    total += s[i+1][1] + s[i+1][2];
                    if (s[i+1][1] == 10)
                        total += s[i+2][1];
                }
                else if (s[i][1] + s[i][2] == 10)
                    total += s[i+1][1];

            cout << total << endl;

//            print();
            memset(s,0,sizeof(s));
            f = t = 1;

        }
    } 

    return 0;
}
