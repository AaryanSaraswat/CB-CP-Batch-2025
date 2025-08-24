// https://cses.fi/problemset/task/1682

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
 
void solve()
{
    int n,m; cin>>n>>m;
    vi vis(n+1,0);
    
    auto dfs=[&](auto &&self,int node,vvi const &adj,vi &order) -> void
    {
        vis[node]=1;
        for(auto ch:adj[node]) if(!vis[ch]) self(self,ch,adj,order);
        order.pb(node);
    };
 
    vvi adj(n+1,vi());
    vvi tadj(n+1,vi());
 
    loop(i,0,m)
    {
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        tadj[v].pb(u);
    }
    
    vi order;
    loop(i,1,n+1) if(!vis[i]) dfs(dfs,i,adj,order);
    vis.clear();
    vis.resize(n+1,0);
    reverse(all(order));
    vi component;
    vvi scc;
 
    for(auto node:order)
    {
        if(!vis[node])
        {
            dfs(dfs,node,tadj,component);
            scc.pb(component);
            component.clear();
        }
    }
 
    if(sz(scc)<2){
        YES
        return;
    }
    NO
    cout<<scc[1][0]<<" "<< scc[0][0]<<endl;
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
