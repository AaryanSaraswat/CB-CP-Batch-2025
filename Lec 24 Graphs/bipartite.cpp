#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define loopD(i, a, n) for (lli i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(a) ((int)a.size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define endl '\n'
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define fi first
#define si second
#define v(a) vector<int>(a)
#define vv(a) vector<vector<int>>(a)
#define present(c, x) ((c).find(x) != (c).end())
#define set_bits __builtin_popcountll
#define MOD 1000000007
#define int long long

typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umpi;
typedef map<int, int> mpi;
typedef vector<pii> vp;
typedef vector<lli> vll;
typedef vector<vll> vvll;

bool isBipartite = 1;

void dfs(int node,vi &color,vvi &adj,int currColor){
    color[node]=currColor;
    for(auto ch:adj[node]){
        if(color[ch]==-1) dfs(ch,color,adj,1-currColor);
        else if(color[node]==color[ch]){
            isBipartite=0;
            return;
        }
    }
}   

void bfs(int n,vi &color,vvi &adj){
    queue<int> q;
    loop(node,0,n){
        if(color[node]==-1){
            // level by level process kardo
            q.push(node);
            color[node]=0;
            while(!q.empty()){
                auto currNode = q.front(); q.pop();
                for(auto ch:adj[currNode]){
                    if(color[ch]==-1){
                        color[ch] = 1 - color[currNode];
                        q.push(ch);
                    }
                    else if(color[currNode]==color[ch]){
                        isBipartite=0;
                        return;
                    }
                }
            }
        }
    }
}

void solve(){
    int n; cin>>n; // no fo nodes
    vvi adj(n+1,vi());
    vi color(n+1,-1);
    int m; cin>>m; // no of edges
    loop(i,0,m){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    loop(node,0,n){
        if(color[node]==-1) dfs(node,color,adj,0);
    }
}

int32_t main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        
    }
    return 0;
}
