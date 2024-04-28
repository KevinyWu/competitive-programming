#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    if (n%4 == 2 || n%4 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (n%4 == 0) {
        cout << n/2 << '\n';
        for (int i = 1; i <= n/4; i++) {
            cout << i << ' ' << n - i + 1 << ' ';
        }
        cout << '\n' << n/2 << '\n';
        for (int i = n/4 + 1; i <= n/2; i++) {
            cout << i << ' ' << n - i + 1 << ' ';
        }
    }
    else {
        cout << n/2 + 1 << '\n';
        cout << 1 << ' ' << 2 << ' ';
        for (int i = 4; i <= n; i++) {
            if (i%4 == 0 || i%4 == 3) {
                cout << i << ' ';
            }
        }
        cout << '\n' << n/2 << '\n';
        cout << 3 << ' ';
        for (int i = 4; i <= n; i++) {
            if (i%4 == 1 || i%4 == 2) {
                cout << i << ' ';
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}