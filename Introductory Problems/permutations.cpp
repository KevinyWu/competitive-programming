#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }
    else if (n < 4) {
        cout << "NO SOLUTION";
        return;
    }
    int i = 0;
    while (i != n - (n%2 == 0)) {
        i += 2;
        if (i > n) {
            i = 1;
        }
        cout << i << ' ';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}