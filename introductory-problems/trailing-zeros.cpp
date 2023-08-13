#include <iostream>
#include <cmath>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    int pow_five = log(n)/log(5);
    int num = 5, ans = 0;
    while (num <= n) {
        ans += n/num;
        num *= 5;
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}