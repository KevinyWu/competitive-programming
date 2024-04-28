#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int a, b; cin >> a >> b;
    int num = min(a, b) - abs(a - b);
    if (num%3 == 0 && num >= 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}