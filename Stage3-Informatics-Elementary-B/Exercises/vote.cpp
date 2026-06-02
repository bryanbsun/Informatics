#include <bits/stdc++.h>
using namespace std;

long long va, vb;
//long long na, nb;
long long a, b;
int n;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a >> b;
        if (a >= va && b >= vb){
            va = a;
            vb = b;
        }else{
            long long t = max(ceil((double)va/a),ceil((double)vb/b));
            va = a * t;
            vb = b * t;
        }
/*        int na = a, nb = b;
        while (na < va || nb < vb){
            na += a;
            nb += b;
        }
*/
    }

    cout << va+vb << endl;

    return 0;
}
