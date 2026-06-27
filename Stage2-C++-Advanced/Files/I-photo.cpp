#include <bits/stdc++.h>
using namespace std;
int	main(){
	int n, fc, mc;
	string gender;
	float height, f[105], m[105];

	cin >> n;
	fc = mc = 0;
	for (int i = 0; i < n; i ++){
		cin >> gender >> height;
		if (gender == "male")
			m[mc++] = height;
		else
			f[fc++] = height;
	}
	sort(m, m+mc);
	sort(f, f+fc);

	for (int i = 0; i < mc; i ++) cout << fixed << setprecision(2) << m[i] << " ";
	for (int i = fc - 1; i >= 0; i --) cout << fixed << setprecision(2) << f[i] << " ";

	return 0;
}
