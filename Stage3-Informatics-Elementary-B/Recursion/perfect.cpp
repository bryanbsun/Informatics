#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	for (int a = 1; a <= n; a ++)
		for (int b = 1; b <= a; b++)
			for (int c = b; c <= a; c ++){
				double dd = cbrt(a*a*a - b*b*b - c*c*c);
				int d=int(dd);
				if (d>=c and a*a*a == b*b*b + c*c*c + d*d*d)
					cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
            }
	return 0;
}
