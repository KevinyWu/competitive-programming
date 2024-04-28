#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int a, b, c; cin >> a >> b >> c;
        int A = 0, B = 0, C = 0, res = 1e9;
        for (int i = 1; i < 2*a; i++) {
            for (int j = i; j < 2*b; j += i) {
                int cur1 = (c/j)*j;
                int cur2 = (c/j)*j + j;
                int rtn1 = abs(a-i) + abs(b-j) + abs(c-cur1);
                int rtn2 = abs(a-i) + abs(b-j) + abs(c-cur2);
                if (min(rtn1, rtn2) < res) {
                    if (rtn1 < rtn2) {res = rtn1; A = i; B = j; C = cur1;}
                    else {res = rtn2; A = i; B = j; C = cur2;}
                }
            }
        }
        cout << res << "\n";
        cout << A << " " << B << " " << C << "\n";
    }

    return 0;
}
