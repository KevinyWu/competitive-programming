#include <iostream>
#define ll long long
using namespace std;


char board[8][8];
int diag1[15] = {0}, diag2[15] = {0}, row[8] = {0};
int ans = 0;

void place_queens(int c) {
    if (c == 8) {
        ans++;
    }
    for (int r = 0; r < 8; ++r) {
        // check if the current row and both diagonals are already attackable
        // if not, place a queen here and mark 1 on its row and diagonals
        if (board[r][c] != '*' && row[r] == 0 && diag1[r+c] == 0 && diag2[r-c+7] == 0) {
            row[r] = 1;
            diag1[r+c] = 1;
            diag2[r-c+7] = 1;
            place_queens(c+1);
            row[r] = 0;
            diag1[r+c] = 0;
            diag2[r-c+7] = 0;
        }
    }
}


void solve() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> board[i][j];
        }
    }
    place_queens(0);
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}