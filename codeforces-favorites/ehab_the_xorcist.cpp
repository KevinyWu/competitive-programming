#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll u, v; cin >> u >> v;
    if (u == v) {
        if (!u) {cout << 0 << "\n";}
        else {cout << 1 << "\n" << u << "\n";}
    }
    else if (u > v || u%2 != v%2) {
        cout << -1 << "\n";
    }
    else {
        ll x = (v-u)/2;
        if (x&u) {cout << 3 << "\n" << u << " " << x << " " << x << "\n";}
        else {cout << 2 << "\n" << u+x << " " << x << "\n";}
    }
    return 0;
}
