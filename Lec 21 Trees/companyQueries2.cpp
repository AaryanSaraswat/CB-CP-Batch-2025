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

int dp[100010][18], level[100010];

void dfs(int node,int parent,vvi &adj, int lvl){
    level[node] = lvl;
    dp[node][0]= parent;
    loop(x,1,18){
        dp[node][x] = dp[dp[node][x-1]][x-1];
    }
    for(auto ch:adj[node]){
        if(ch==parent) continue;
        dfs(ch,node,adj,lvl+1);
    }
}

int kthPar(int node,int k){
    int par = node;
    for(int bit=17;bit>=0;bit--){
        if(k&(1<<bit)) par = dp[par][bit];
    }
    return par;
}

int lca(int u,int v){
    // same level par lana hai
    if(level[u]>level[v]) swap(u,v);
    int k  = level[v] - level[u];
    v = kthPar(v,k);

    // check if nodes are same 
    if(u==v) return u;

    // parents par iterate and move on diff parents
    loopD(x,17,0){
        if(dp[u][x]!=dp[v][x]) u = dp[u][x] , v= dp[v][x];
    }

    // return lca
    return dp[u][0]; // dp[v][0]
}

void solve(){
    int n; cin>>n;
    int q; cin>>q;

    vvi adj(n+1,vi());

    for(int u=2;u<=n;u++){ // n-1 edges
        int v; cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, 0, sizeof(dp));

    // Start DFS from root node (assuming node 1 is the root)
    dfs(1, 0, adj,1);

    while (q--) {
        int a,b; cin>>a>>b;
        cout<<lca(a,b)<<endl;
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
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
