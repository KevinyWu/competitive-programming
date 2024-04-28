#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6;
int children[N];
vector<int> tree[N];
vector<int> used(N, 0);
map<int,int> dist;
 
 
void addEdge(int a, int b)
{
    tree[a].push_back(b);
    tree[b].push_back(a);
}
 

void dfs(int v, int d) {
        used[v] = 1;
        for (int vert : tree[v])
        {
            if(used[vert] != 1)
            {
                dist[vert] = d;
                dfs(vert, d+1);
            }
        }
    }
 

void numberOfNodes(int s, int e) { 
        vector<int>::iterator u; 
        children[s] = 1; 
        for (u = tree[s].begin(); u != tree[s].end(); u++) { 
            if (*u == e) {continue;} 
            numberOfNodes(*u, s); 
            children[s] += children[*u]; 
        } 
    }
 

int main()
{
    ios::sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        addEdge(a,b);
    }
    
    dist[1] = 0;
    dfs(1,1);
    numberOfNodes(1,0);
    
    vector<int> rtn;
    for (int i = 1; i <= n; i++){rtn.push_back(dist[i]-children[i]+1);}
    sort(rtn.begin(), rtn.end(), greater<>());
    ll sum = 0;
    for (int i = 0; i < k; i++) {sum += rtn[i];}
    
    cout << sum << "\n";
    
    return 0;
}