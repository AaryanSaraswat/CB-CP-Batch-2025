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

const int maxn = 2e5;
vi adj[maxn+1];
int ans[maxn+1]={0},cnt[maxn+1]={0};

void dfs(int node,int parent){
    ans[node]=0;
    cnt[node]=1;
    for(auto ch:adj[node]){
        if(ch==parent) continue;
        dfs(ch,node);
        ans[node]+=(ans[ch]+cnt[ch]);
        cnt[node]+=cnt[ch];
    }
}

void solve(){
    int n; cin>>n;
    for(int u=2;u<=n;u++){
        int v; cin>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,0);

    // for(int node=1;node<=n;node++) 
    cout<<ans[1]<<" ";

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
