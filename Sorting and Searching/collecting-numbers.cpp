#include <iostream>
#define ll long long
using namespace std;

void solve() {
    int n; cin >> n;
    int a[n], ans = 1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x-1] = i;
    }
    // count the number of adjacent decreases in the index array
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i-1]) {
            ans++;
        }
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}