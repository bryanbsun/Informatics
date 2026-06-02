#include <bits/stdc++.h>

using namespace std;

int     pol(){
    string s;
    cin >> s;
    if (isdigit(s[0]))
        return stoi(s);
    else
        if (s == "+") return pol() + pol();
        else if (s == "-") return pol() - pol();
        else if (s == "*") return pol() * pol();
        else if (s == "/") return pol() / pol();
}

int     main(){
    cout << pol() << endl;
    return 0;
}
