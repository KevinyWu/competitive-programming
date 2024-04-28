#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    ll a[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}
    vector<ll> v;
    int ind = 0;
    while(v.size() < n) {
        v.push_back(a[ind]);
        ind += 2;
        ind %= n;
    }
    for (int i = 0; i < n/2 - 1; i++) {
        v.push_back(v[i]);
    }
    ll cur = 0;
    ll mn = 0;
    ll len = n/2;
    for (int i = 0; i < v.size(); i++) {
        if (i < len) {
            cur += v[i];
            mn = cur;
        }
        else {
            cur += v[i];
            cur -= v[i-len];
            mn = min(mn, cur);
        }
    }
    cout << sum-mn << "\n";
    return 0;
}