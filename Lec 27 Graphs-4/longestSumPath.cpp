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

vi topoSort(vector<vp> &adj,vi &ind,int n){
    vi order;
    
    queue<int> q;
    loop(i,0,n) if(ind[i]==0) q.push(i);

    while(!q.empty()){
        auto node = q.front();q.pop();
        order.pb(node);
        for(auto [ch,_]:adj[node]){
            if(--ind[ch]==0) q.push(ch);
        }
    }
    return order;
}

void solve(){
    int n; cin>>n; // no fo nodes
    // vvi adj(n+2,vi());
    vector<vp> adj(n+2);
    vi ind(n+2,-1);
    int m; cin>>m; // no of edges
    loop(i,0,m){
        int u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w});
        ind[v]++;
    }
    

    vi dp(n,0);
    vi order = topoSort(adj,ind,n);
    
    loopD(i,n-1,0){
        auto node = order[i];
        for(auto [ch,w]:adj[node]){
            dp[node] = max(dp[ch]+w,dp[node]);
        }
    }

    int q; cin>>q;

    while (q--)
    {
        int node; cin>>node;
        cout<<dp[node]<<endl; // dp[node] -> longest sum path
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
