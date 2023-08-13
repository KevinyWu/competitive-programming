#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    // consider the numbers as 0, 1, ... n-1 so we can take mod n
    int cur = 1, count = 1, step = 2;
    vector<bool> used(n, false);
    // go until the last person
    while (count < n) {
        used[cur] = true;
        cout << cur + 1 << ' ';
        // after one circle increase step size
        if (cur + step > n-1) {
            cur += step;
            cur %= n;
            while (used[cur]) {
                cur++;
            }
            step *= 2;
        }
        else {
            cur += step;
        }
        count++;
    }
    // winner is deterministic
    // numberphile video: https://www.youtube.com/watch?v=uCsD3ZGzMgE
    int largest_power_of_two = log2(n);
    cout << 2 * (n - pow(2, largest_power_of_two)) + 1 << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}