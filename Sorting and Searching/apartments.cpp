#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n, m, k; cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b ,b + m);
    int j = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        while (b[j] < a[i] - k && j < m) {
            j++;
        }
        if (j == m) {
            break;
        }
        if (b[j] <= a[i] + k && b[j] >= a[i] - k) {
            j++;
            ans++;
            continue;
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