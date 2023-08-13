#include <iostream>
#define ll long long
using namespace std;


const int n = 7;
bool visited[n][n] = {false};
string reserved_moves;

// recursively find the number of paths
int move(int r, int c, int step) {
    // if you end up at the final location, return 1 if the number of steps is n^2 - 1
    if (r == n - 1 && c == 0) {
        return (step == n*n - 1);
    }
    // if path hits a wall or occupied space and can turn 90 degrees to either side
    // then the grid splits into two part both with unvisited blocks, so return 0
    if (((r == n - 1 || r == 0 || (visited[r-1][c] && visited[r+1][c])) &&
         c >= 1 && c < n - 1 && !visited[r][c-1] && !visited[r][c+1]) ||
        ((c == n - 1 || c == 0 || (visited[r][c-1] && visited[r][c+1])) &&
         r >= 1 && r < n - 1 && !visited[r-1][c] && !visited[r+1][c])) {
        return 0;
    }

    int ans = 0;
    visited[r][c] = true;
    if (reserved_moves[step] != '?') {
        if (reserved_moves[step] == 'D' && r + 1 < n && !visited[r+1][c]) {
            ans += move(r + 1, c, step + 1);
        }
        if (reserved_moves[step] == 'U' && r - 1 >= 0 && !visited[r-1][c]) {
            ans += move(r - 1, c, step + 1);
        }
        if (reserved_moves[step] == 'L' && c - 1 >= 0 && !visited[r][c-1]) {
            ans += move(r, c - 1, step + 1);
        }
        if (reserved_moves[step] == 'R' && c + 1 < n && !visited[r][c+1]) {
            ans += move(r, c + 1, step + 1);
        }
    }
    else {
        if (r + 1 < n && !visited[r+1][c]) {
            ans += move(r + 1, c, step + 1);
        }
        if (r - 1 >= 0 && !visited[r-1][c]) {
            ans += move(r - 1, c, step + 1);
        }
        if (c - 1 >= 0 && !visited[r][c-1]) {
            ans += move(r, c - 1, step + 1);
        }
        if (c + 1 < n && !visited[r][c+1]) {
            ans += move(r, c + 1, step + 1);
        }
    }
    visited[r][c] = false;
    return ans;
}


void solve() {
    string s; cin >> s;
    reserved_moves = s;
    int ans = move(0, 0, 0);
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}