#include <bits/stdc++.h>
using namespace std;

int     counter = 0;

int main(){
    for (int i = 1; i <= 5000; i ++){
        int a = i % 10;
        int b = i %100 / 10;
        int c = i / 100 % 10;
        int d = i / 1000;

        if (a+b+c+d == 13 and i % 11 == 0){
            cout << i << " ";
            counter ++;
        }
    }
    cout << endl;
    cout << counter << endl;

    return 0;
}