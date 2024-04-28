#include <iostream>
#define ll long long
using namespace std;


void solve() {
    ll k; cin >> k;
    ll cur = 9;
    ll num_digits = 1;
    // find how many digits in k
    while (k > cur * num_digits) {
        k -= cur * num_digits;
        num_digits++;
        cur *= 10;
    }
    // find what number the digit is in
    ll num = cur/9 + (k - 1)/num_digits;
    // find the index of the digit in the number
    ll ind_in_num = (k - 1)%num_digits;
    string str = to_string(num);
    cout << str[ind_in_num] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}