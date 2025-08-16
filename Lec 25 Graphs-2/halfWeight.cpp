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


void solve(){
    int n; cin>>n;
    vector<vector<pii>> adj(n+1);
    int m; cin>>m;
    vvi edges;
    loop(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        edges.pb({u,v,w});
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    auto dijkstra=[&](int src)->vi{
        vi dist(n+1,1e18);
        priority_queue<pii,vector<pii>,greater<pii>> pq; // min-heap
        pq.push({0,src});
        dist[src] = 0;

        while(!pq.empty()){
            auto [d,node] = pq.top(); pq.pop();
            if( d!= dist[node]) continue;  // save iterations
            for(auto [ch,ew]: adj[node]){
                if(dist[node]+ ew < dist[ch]){
                    dist[ch] = dist[node] + ew ;
                    pq.push({dist[ch],ch});
                }
            }
        }
        return dist;
    };

    int src,des;
    cin>>src>>des;
    auto d1 = dijkstra(src);
    auto d2 = dijkstra(des);
    int ans  = d1[des];
    for(auto e:edges){
        int u=e[0], v=e[1], w=e[2];
        
        int newDistance  = d1[u] + w/2 + d2[v];
        ans=min(ans,newDistance);
        
        newDistance  = d1[v] + w/2 + d2[u];
        ans=min(ans,newDistance);
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
