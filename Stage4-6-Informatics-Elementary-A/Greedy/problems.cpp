#include <bits/stdc++.h>
using namespace std;

long long minutes(string s){
    int year = stoi(s.substr(0,4));
    int month = stoi(s.substr(5,2));
    int day = stoi(s.substr(8,2));
    int hour = stoi(s.substr(11,2));
    int minute = stoi(s.substr(14,2));

    int leap = 0;
    for (int i = 1; i < year; i ++)
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
            leap ++;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        if (month > 2)
            leap ++;

    int doy;
    switch (month){
        case 1: doy = 0; break;
        case 2: doy = 31; break;
        case 3: doy = 59; break;
        case 4: doy = 90; break;
        case 5: doy = 120; break;
        case 6: doy = 151; break;
        case 7: doy = 181; break;
        case 8: doy = 212; break;
        case 9: doy = 243; break;
        case 10: doy = 273; break;
        case 11: doy = 304; break;
        case 12: doy = 334; break;
    }

    return (((year-1) * 365 + leap) + doy + day - 1) * 1440 + (hour-1) * 60 + minute; 
}

string t1, t2;
int n;
int t[10010];
int ans;

int main(){
    cin >> t1 >> t2 >> n;
    for (int i = 0; i < n; i ++)
        cin >> t[i];

    sort(t, t+n);

    long long total = t[0];
    long long duration = minutes(t2) - minutes(t1);
    while(ans < n && total <= duration){
        ans ++;
        total += t[ans];
    }

    cout << ans << endl;

    return 0;
}
