#include <iostream>
#include <set>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}