#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from, char via, char to){
        if (n>0){
                hanoi(n-1,from, to, via)           ;
                cout << from << " to " << to << endl;
                hanoi(n-1,via,from,to);
        }
}
int main(){
        int n;
        cin >> n;
        hanoi(n, 'A', 'B', 'C');
        return 0;
}

