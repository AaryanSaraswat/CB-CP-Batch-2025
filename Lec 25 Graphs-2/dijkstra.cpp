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

vector<vector<pii>> adj;

vi dijkstra(int src,int n){
    vi dist(n+1,INT_MAX);
    vi parent(n+1,-1);
    // priority_queue<int, vector<int>, greater<int>> pq; // min -heap // {w,node}
    priority_queue<pii,vector<pii>,greater<pii>> pq; // min-heap
    pq.push({0,src});
    dist[src] = 0;

    while(!pq.empty()){
        auto [d,node] = pq.top(); pq.pop();
        if( d!= dist[node]) continue;  // save iterations
        for(auto [ch,ew]: adj[node]){
            if(dist[node]+ ew < dist[ch]){
                parent[ch]= node; // kuki m node se yhn aya hu
                dist[ch] = dist[node] + ew ;
                pq.push({dist[ch],ch});
            }
        }
    }

    int des; cin>>des;
    vi path;
    while(des!=-1){
        path.pb(des);
        des=parent[des];
    }
    reverse(all(path));
    for(auto &i:path) cout<<i<<" ";
    return dist;
}


vi dijkstraSet(int src,int n){
    vi dist(n+1,INT_MAX);
    set<pii> st;  // {w,node}
    st.insert({0,src});
    dist[src] = 0;

    while(!st.empty()){
        auto [d,node] = *st.begin(); st.erase(st.begin());
        for(auto [ch,ew]: adj[node]){
            if(dist[node]+ ew < dist[ch]){ // update 
                // old data erase
                st.erase({dist[ch],ch});
                dist[ch] = dist[node] + ew ; // update kardiya
                st.insert({dist[ch],ch});
            }
        }
    }
    return dist;
}

void solve(){
    int n; cin>>n;
    adj.assign(n+1,{});

    int m; cin>>m;
    loop(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        // adj[v].pb({u,w});
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
