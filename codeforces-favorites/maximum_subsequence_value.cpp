#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    ll a[n];
    ll ans = 0;
    for (int i = 0; i < n; i++) {cin >> a[i];}
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                ans = max(ans, (a[i]|a[j]|a[k]));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
