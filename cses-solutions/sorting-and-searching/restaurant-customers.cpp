#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v(2*n);
    // put start and end times in one list
    for (int i = 0; i < n; ++i) {
        int start, end; cin >> start >> end;
        v[2 * i] = {start, 1};
        v[2 * i + 1] = {end, -1};
    }
    sort(v.begin(), v.end());
    int ans = 1, cur = 1;
    // by index i, if there are m starts and i - m ends, there are m - (i - m) people
    // this is just finding the largest prefix array sum
    for (int i = 1; i < 2 * n; ++i) {
        cur += v[i].second;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}