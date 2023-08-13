#include <iostream>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll smallest[n+1]; // keep track of the smallest sum you cannot make with the first i coins
    smallest[0] = 1;
    for (int i = 0; i < n; ++i) {
        // if the (i+1)th coin is higher than smallest[i] (the smallest using first i coins),
        // then smallest[i] is still not achievable and we are done
        if (a[i] > smallest[i]) {
            cout << smallest[i] << '\n';
            return;
        }
        // otherwise we can make all sums up to a[i] + smallest[i]
        smallest[i+1] = a[i] + smallest[i];
    }
    cout << smallest[n] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}