#include <bits/stdc++.h>
using namespace std;

int	main(){
	int n;
	cin >> n;
	
	for (int a = 2; a <= n; a ++)
		for (int b = 2; b < a; b++)
			for (int c = b; c < a; c ++){
				double dd = cbrt(a*a*a - b*b*b - c*c*c);
				int d=int(dd);
				if (d >= c && a*a*a == b*b*b + c*c*c + d*d*d)
					cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
 				if (d+1>=c and a*a*a == b*b*b + c*c*c + (d+1)*(d+1)*(d+1))
					cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d+1 << ")" << endl;
			}
	return 0;
}
