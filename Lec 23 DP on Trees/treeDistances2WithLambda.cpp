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
 
int32_t main()
{
    fastio;
 
    int n;
    cin >> n;
 
    vvi adj(n + 1); // 1-based indexing trees
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
 
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi cnt(n + 1, 0);
    vi ans(n + 1, 0);
    vi subAns(n + 1, 0);
 
    auto add = [&](int node, int child)
    {
        cnt[node] += cnt[child];
        subAns[node] += subAns[child] + cnt[child];
    };
 
    auto subtract = [&](int node, int child)
    {
        cnt[node] -= cnt[child];
        subAns[node] -= subAns[child] + cnt[child];
    };
 
    auto changeRoot = [&](int node, int child)
    {
        subtract(node, child);
        add(child, node);
    };
 
    function<void(int, int)> dfs = [&](int node, int parent) -> void
    {
        subAns[node] = 0;
        cnt[node] = 1;
        for (auto child : adj[node])
        {
            if (child == parent)
                continue;
            dfs(child, node);
            add(node, child);
        }
    };
 
    function<void(int, int)> reRoot = [&](int node, int parent) -> void
    {
        // initialize ans node
        ans[node] = subAns[node];
        for (int child : adj[node])
        {
            if (child == parent)
                continue;
            changeRoot(node, child);
            reRoot(child, node);
            changeRoot(child, node); // backtrack
        }
    };
    dfs(1, 0);
    reRoot(1, 0);
    loop(i, 1, n + 1) cout << ans[i] << " ";
    cout << endl;
}