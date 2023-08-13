#include <iostream>
#include <cmath>
#define ll long long
using namespace std;


// we want to always move the largest plate from col1 to col3
// to do this, we need to move all other plates from col1 to col2 first
// this is just the game with n-1 plates, and col2 and col3 swapped!
// after moving the largest plate, we have the game with n-1 plates, col2 and col1 swapped
void solve_hanoi(int n, int col1, int col2, int col3) {
    if (n == 0) {
        return;
    }
    solve_hanoi(n-1, col1, col3, col2);
    cout << col1 << ' ' << col3 << '\n';
    solve_hanoi(n-1, col2, col1, col3);
}


void solve() {
    int n; cin >> n;
    cout << pow(2, n) - 1 << '\n';
    solve_hanoi(n, 1, 2, 3);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}