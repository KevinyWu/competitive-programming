#include <iostream>
#include <stack>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // keep a stack of previous values
    stack<pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
        if (stk.empty()) {
            cout << 0 << ' ';
        }
        else {
            // remove values from the stack until you reach a smaller element
            // if a future element is larger than the current,
            // the current is a nearer smallest element than anything removed from the stack 
            // if a future element is smaller than the current,
            // the elements removed will not be small enough for the future element
            while (!stk.empty() && stk.top().first >= a[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                cout << 0 << ' ';
            }
            else {
                cout << stk.top().second<< ' ';
            }
        }
        // add current value
        stk.push({a[i], i + 1});
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}