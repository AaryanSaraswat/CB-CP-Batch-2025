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


struct DSU{
    vi p,rank,size;
    int components=0;
    DSU(int n):p(n,0),rank(n,0),components(n),size(n,1){ iota(all(p),0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool inSameSet(int u,int v){ return find(u)==find(v); }
    void join(int u,int v){ if(!inSameSet(u,v)){ u=find(u),v=find(v); components--; if(rank[u]>rank[v]) p[v]=u; else{ p[u]=v; rank[v]+=(rank[u]==rank[v]);} } }
    void joinBySz(int u,int v){ if(!inSameSet(u,v)){ u=find(u),v=find(v); components--; if (size[u] < size[v]) swap(u, v); p[v] = u, size[u] += size[v]; } }
    int noOfConnectedComponents(){ return components; }
    int getSize(int x) { return size[find(x)]; }
};

void solve(){
    
    int n; cin>>n;
    int m; cin>>m;

    // vector<vp> adj(n+1);

    vvi arr; // {w,u,v}

    loop(i,0,m){
        int u,v,w; cin>>u>>v,w;
        arr.pb({w,u,v});
    }   
    DSU d(n+1);
    sort(all(arr)); // m*logm

    int ans = 0;
    
    // no of edges < n-1

    // dsu no of components > 1

    // process all nodes

    int noOfEdges = 0,i=0;
    while (noOfEdges<n-1 and i<m) // n-1
    {
        auto a = arr[i];
        int w= a[0], u=a[1], v=a[2];
        if(d.inSameSet(u,v)) continue;
        ans+=w;
        d.join(u,v);
        noOfEdges++;
    }
    cout<<ans<<endl; // tc -> n + m*logm
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
