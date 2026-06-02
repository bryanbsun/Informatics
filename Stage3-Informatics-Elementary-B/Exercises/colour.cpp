#include <bits/stdc++.h>
using namespace std;

int	main(){
	int w, h, n;
	cin >> w >> h >> n;
	int l = 0, b = 0, r = w, t = h;
	for (int i = 0; i < n; i ++){
        int a, x, y;
        cin >> x >> y >> a;
		if (a == 1) 
			l = max(l, x);
		else if (a == 2)
			r = min(r, x);
		else if (a == 3)
			b = max(b, y);
		else if (a == 4)
			t = min(t, y);

//        cout << l << "," << b << "," << r << "," << t << endl;
	}
	
	cout << max(0, t-b) * max(0, r-l) << endl;
	
	return 0;
}

