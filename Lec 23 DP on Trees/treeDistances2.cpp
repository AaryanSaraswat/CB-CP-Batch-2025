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
vi adj[maxn + 1];
int ans[maxn + 1] = {0}, cnt[maxn + 1] = {0}, finalAns[maxn + 1]={0};

void dfs(int node, int parent)
{
    ans[node] = 0;
    cnt[node] = 1;
    for (auto ch : adj[node])
    {
        if (ch == parent) continue;
        dfs(ch, node);
        ans[node] += (ans[ch] + cnt[ch]);
        cnt[node] += cnt[ch];
    }
}

void add(int node, int ch)
{
    cnt[node] += cnt[ch];
    ans[node] += (ans[ch] + cnt[ch]);
}

void remove(int node, int ch)
{
    cnt[node] -= cnt[ch];
    ans[node] -= (ans[ch] + cnt[ch]);
}

void changeRoot(int node, int child)
{
    remove(node, child);
    add(child, node);
};

void reroot(int node, int parent)
{ 
    finalAns[node] = ans[node];
    for (auto ch : adj[node])
    {
        if (ch == parent) continue;
        changeRoot(node, ch);
        reroot(ch, node);
        changeRoot(ch, node);
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int v;  cin >> v;
        int u; cin >> u;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);
    reroot(1, 0);
    loop(i, 1, n + 1) cout << finalAns[i] << " ";
}

int32_t main()
{
    fastio;

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
