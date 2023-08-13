#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> v(n+1, 0);
    for (int i = 0; i < n-1; ++i) {
        int x; cin >> x;
        v[x] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i] == 0) {
            cout << i;
            return;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}