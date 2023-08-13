#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;


void solve() {
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        // store original index in the second element
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    // store customers in a min heap by earliest end time
    // second element of pair is the room they are in
    priority_queue<pair<int, int>> pq;
    int rooms_needed = 0, last_room = 1, ans[n];
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            // no min heap in C++, so store by negative end time
            pq.push({-v[i].first.second, last_room});
            ans[v[i].second] = last_room;
            last_room++;
        }
        else {
            // get earliest end time
            pair<int, int> min_end = pq.top();
            // if end time is early enough, new customer takes the old room
            if (-min_end.first < v[i].first.first) {
                pq.pop();
                pq.push({-v[i].first.second, min_end.second});
                ans[v[i].second] = min_end.second;
            }
            // otherwise open a new room
            else {
                pq.push({-v[i].first.second, last_room});
                ans[v[i].second] = last_room;
                last_room++;
            }
        }
        // update the max amount of rooms needed
        rooms_needed = max(rooms_needed, int(pq.size()));
    }
    cout << rooms_needed << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}