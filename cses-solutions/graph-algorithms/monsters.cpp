#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define ll long long
using namespace std;


int n, m;
char labyrinth[1001][1001];
int monster_dist[1001][1001];
queue<pair<int, int>> q;
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string moves_str = "RLDU";


void bfs() {
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> nxt = {cur.first + moves[i].first, cur.second + moves[i].second};
            // If out of bounds or on a wall or already visited, continue
            if (nxt.first < 0 || nxt.first >= n || 
                nxt.second < 0 || nxt.second >= m ||
                labyrinth[nxt.first][nxt.second] == '#' ||
                monster_dist[nxt.first][nxt.second] != INT_MAX) {
                continue;
            }
            // Update the distances
            monster_dist[nxt.first][nxt.second] = monster_dist[cur.first][cur.second] + 1;
            q.push(nxt);
        }
    }
}


void solve() {
    // Key idea: if a monster can get to a square in less moves than you,
    // then you can't get to that square
    // Use BFS to find the shortest distance from the monster to each square
    // Then use BFS from the starting position to find a possible path to a boundary
    cin >> n >> m;
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            cin >> labyrinth[i][j];
            monster_dist[i][j] = INT_MAX; // Set the initial distances to INF
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            }
            else if (labyrinth[i][j] == 'M') {
                q.push({i, j});
                monster_dist[i][j] = 0;
            }
        }
    }
    // BFS from each monster
    bfs();
    // BFS from the starting position
    // 'dist' keeps track of the shortest distance from the starting position to each square
    // 'visited' keeps track of the move that was made to get to each square
    vector<vector<int>> dist(n, vector<int>(m, -1)), visited(n, vector<int>(m, -1));
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        // If found a path to a boundary, print the path and return
        if (cur.first == 0 || cur.first == n - 1 || 
            cur.second == 0 || cur.second == m - 1) {
            cout << "YES\n";
            string path = "";
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
        // Otherwise, continue BFS
        for (int i = 0; i < 4; i++) {
            pair<int, int> nxt = {cur.first + moves[i].first, cur.second + moves[i].second};
            if (nxt.first < 0 || nxt.first >= n || 
                nxt.second < 0 || nxt.second >= m ||
                labyrinth[nxt.first][nxt.second] == '#' || 
                dist[nxt.first][nxt.second] != -1 ||
                monster_dist[nxt.first][nxt.second] <= dist[cur.first][cur.second] + 1) {
                continue;
            }
            // Update the distances and visited moves
            dist[nxt.first][nxt.second] = dist[cur.first][cur.second] + 1;
            visited[nxt.first][nxt.second] = i;
            q.push(nxt);
        }
    }
    cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}