#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll ans = 0;
    int a, b, c, d; cin >> a >> b >> c >> d;
    for (int i = a+b; i < b+c+1; i++) {
        if (i <= c) {continue;}
        int xmin = max(a, i-c);
        int xmax = min(b, i-b);
        ll z = min(d, i) - c;
        if (i > d) {z += 1;}
        ans += z*(xmax - xmin + 1);
    }
    cout << ans << "\n";
    return 0;
}
