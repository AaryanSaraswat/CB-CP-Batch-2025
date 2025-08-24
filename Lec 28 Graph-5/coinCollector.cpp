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

vi topoSort(vector<vi> &graph,vi &ind,int n){
    vi order;
    
    queue<int> q;
    loop(i,0,n) if(ind[i]==0) q.push(i);

    while(!q.empty()){
        auto node = q.front();q.pop();
        order.pb(node);
        for(auto ch:graph[node]){
            if(--ind[ch]==0) q.push(ch);
        }
    }
    return order;
}

void solve(){
    int n; cin>>n;
    int m; cin>>m;

    vi coins(n+1); loop(i,1,n+1) cin>>coins[i];

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

    vvi SCC;

    vis.clear();
    vis.resize(n+1,0);

    vi leader(n+1,0);

    vi coinSumForComponent(n+1,0);

    for(auto node:order){
        // node -> kis kis ko visit kar parha h in radj -> SSC
        if(!vis[node]){

            // node -> leader
            vi component;
            dfs(node,component,radj);
            int sum=0;
            for(auto ch:component) leader[ch]=node,sum+=coins[ch];
            coinSumForComponent[node] = sum;
            SCC.pb(component);
        }
    }


    vvi condensedGraph(n+1,vi());
    vi ind(n+1,0);

    loop(u,1,n+1){
        for(auto v:adj[u]){
            if(leader[u]==leader[v]) continue;
            // u-> v
            condensedGraph[leader[u]].push_back(leader[v]);
            ind[leader[v]]++;
        }
    }

    // condensed graph done 

    // dp[l] -> max coins i can get if a start from any node in the scc whose leader is l
    
    // topo sort
    order = topoSort(condensedGraph,ind,n);

    vi dp(n+1,0);

    int ans =0; 
    reverse(all(order));
    
    for(auto node:order){
        dp[node] = coinSumForComponent[node];
        for(auto ch:condensedGraph[node]){
            dp[node] = max(dp[node], dp[ch]+coinSumForComponent[node]);
        }
        ans=max(ans,dp[node]);
    }

    cout<<ans<<endl;
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
