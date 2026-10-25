#include <bits/stdc++.h>
using namespace std;
int a[10];

bool cmp(int a, int b){
//    int a1 = a%10 + a/10, b1 = b%10+b/10;
//    return (b1 < a1);
    return(a%2 > b%2);
}

int main(){
    for (int i = 0; i < 10; i ++)
        cin >> a[i];
    sort(a, a + 10, cmp);
    for (int i = 0; i < 10; i ++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}