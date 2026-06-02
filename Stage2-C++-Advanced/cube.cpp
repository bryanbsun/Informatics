#include <bits/stdc++.h>
using namespace std;

int main()
{
    // find all the quadruplets (a, b, c, d), where a3 = b3 + c3 + d3, where n >= a >= d >= c >= b > 1
   
    int n;
    cin >> n;
    int x = n + 1;
   
    for (int a = 2; a < x; a++) {
        for (int b = 2; b < x; b++) {
            for (int c = 2; c < x; c++) {
                for (int d = 2; d < x; d++) {
                    if (pow(a, 3) == pow(b, 3) + pow(c, 3) + pow(d, 3) && a >= d && d >= c && c >= b) {
                        cout << "Cube = " << a << ", Tripe = (" << b << "," << c << "," << d << ")" << "\n";
                    }
                }
            }
        }
    }
   
}
