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

vvi adj,radj;
vi vis;

void dfs(int node,vi &order, vvi &g){
    vis[node] =1;
    for(auto ch:g[node]){
        if(!vis[ch]) dfs(ch,order,g);
    }
    // out time hai
    order.push_back(node);
}

void solve(){
    int n; cin>>n;
    vi a(n+1); loop(i,1,n+1) cin>>a[i];
    int m; cin>>m;
    adj.resize(n+1,vi());
    radj.resize(n+1,vi());
    vis.resize(n+1,0);

    loop(i,0,m){
        int u,v; cin>>u>>v;
        // u-> v
        adj[u].push_back(v);
        // u <- v reverse graph
        radj[v].push_back(u);
    }

    vi order;
    loop(i,1,n+1) if(!vis[i]) dfs(i,order,adj);

    reverse(all(order));

    vis.clear();
    vis.resize(n+1,0);
    int cost = 0, ways = 1;
    for(auto node:order){
        // node -> kis kis ko visit kar parha h in radj -> SSC
        if(!vis[node]){
            vi component;
            dfs(node,component,radj);
            int mx = 1e18, cnt = 0;
            for (auto &i : component) mx = min(mx, a[i]);
            for (auto &i : component) cnt += (a[i] == mx);
            cost += mx;
            ways = (ways * (cnt % MOD)) % MOD;
        }
    }
    
    cout << cost << " " << ways << endl;
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