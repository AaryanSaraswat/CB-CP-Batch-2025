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

void bfs(int n,vi &color,vvi &adj){
    queue<int> q;
    loop(node,1,n+1){
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
                    else isBipartite &= (color[currNode]!=color[ch]);
                }
            }
        }
    }
}

void solve(){
    int n; cin>>n; // no fo nodes
    vvi adj(n+2,vi());
    vi color(n+2,-1);
    int m; cin>>m; // no of edges
    loop(i,0,m){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs(n,color,adj);
    if(!isBipartite) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    loop(node,1,n+1) cout<<color[node]+1<<" ";
    cout<<endl;
}

int32_t main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
