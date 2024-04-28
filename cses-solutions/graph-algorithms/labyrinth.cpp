#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;


int n, m;
int visited[1001][1001]; 
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string moves_str = "RLDU";


void solve() {
    cin >> n >> m;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = -1; // Set to -1 by default
            char c; cin >> c;
            if (c == '#') {
                // Mark walls as visited (0-3 reserved for moves)
                visited[i][j] = 4;
            }
            if (c == 'A') {
                start = {i, j};
            }
            if (c == 'B') {
                end = {i, j};
            }
        }
    }
    // BFS through the grid, marking the direction we took to get to each vertext
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first + moves[i].first, cur.second + moves[i].second};
            if (next.first < 0 || next.first >= n ||
                next.second < 0 || next.second >= m ||
                visited[next.first][next.second] != -1) {
                continue;
            }
            visited[next.first][next.second] = i;
            q.push(next);
        }
    }
    // If we can reach the end, print the path
    if (visited[end.first][end.second] != -1) {
        cout << "YES\n";
        string path = "";
        pair<int, int> cur = end;
        while (cur != start) {
            int dir = visited[cur.first][cur.second];
            path += moves_str[dir];
            cur = {cur.first - moves[dir].first, cur.second - moves[dir].second};
        }
        reverse(path.begin(), path.end());
        cout << path.length() << '\n';
        cout << path << '\n';
        return;
    }
    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}