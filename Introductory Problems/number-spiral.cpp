#include <iostream>
#define ll long long
using namespace std;


void solve() {
    ll y, x; cin >> y >> x;
    ll mx = max(x, y);
    if (mx == y) {
        if (y%2 == 1) {
            cout << (mx-1)*(mx-1) + x;
        }
        else {
            cout << mx*mx - x + 1;
        }
    }
    else {
        if (x%2 == 0) {
            cout << (mx-1)*(mx-1) + y;
        }
        else {
            cout << mx*mx - y + 1;
        }
    }
    cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}