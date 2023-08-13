#include <iostream>
#define ll long long
using namespace std;


void solve() {
    ll n; cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll num = (i*i * (i*i - 1))/2;
        if (i == 1) {
            cout << 0 << "\n";
        }
        else if (i == 2) {
            cout << 6 << "\n";
        }

        else {
            cout << num - 4 * (i - 1) * (i - 2) << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}