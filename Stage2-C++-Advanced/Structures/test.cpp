#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    if (a % 2 == 0)
        return true;
    else {
        return false;
    }
}

int main(){
    int a[10]{3,1,4,1,5,9,2,6,5,3};

/*    for (int i = 0; i < n; i ++)
        for (int j = n - 1; j > i; j --)
            if (a[j] < a[j-1])
                swap(a[j], a[j-1]);
*/
    sort(a, a+10, cmp);

    for (int i = 0; i < 10; i ++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
