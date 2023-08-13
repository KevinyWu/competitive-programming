#include <iostream>
#include <vector>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int start, end; cin >> start >> end;
        v[i] = {end, start};
    }
    // sort by earliest end time
    sort(v.begin(), v.end());
    // greedily take the available movie with earliest end time
    int ans = 0, minend = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].second >= minend) {
            ans++;
            minend = v[i].first;
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