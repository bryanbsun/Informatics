#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    return a>b;
}

int main(){
    int a[8]{3,1,4,1,5,9,2,6};

    sort(a, a+8, comp);
    
    for (int i = 0; i < 8; i ++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
