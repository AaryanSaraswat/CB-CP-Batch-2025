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
 
const int maxn = 4 * 1e5 + 10;
vi adj[maxn];
int idx = 0, flat[maxn], a[maxn], value[maxn];
unordered_map<int, pii> mp; // node -->{first occurence, last occurence}
 
class seegTree
{
    vi tree;
 
public:
    seegTree(int n)
    {
        tree.resize(4 * n + 1);
    }
 
    void build(int start, int end, int index)
    {
        if (start == end)
        {
            tree[index] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }
 
    int query(int start, int end, int index, int l, int r)
    {
        if (l <= start and r >= end)
            return tree[index];
        if (end < l || start > r)
            return 0;
        int mid = (start + end) / 2;
        return query(start, mid, index * 2, l, r) + query(mid + 1, end, index * 2 + 1, l, r);
    }
 
    void update(int start, int end, int index, int pos, int val)
    {
        if (start == end)
        {
            tree[index] = val;
            value[pos] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (pos <= mid)
            update(start, mid, 2 * index, pos, val);
        else
            update(mid + 1, end, 2 * index + 1, pos, val);
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }
};
 
void dfs(int node, int parent)
{
    // entering the node
    mp[node].fi = idx;
    flat[idx] = node;
    idx++;
    for (auto ch : adj[node])
    {
        if (ch == parent)
            continue;
        dfs(ch, node);
    }
    // leaving the node
    mp[node].si = idx;
    flat[idx] = node;
    idx++;
}
 
void solve()
{
    int n, q;
    cin >> n >> q;
    loop(i, 1, n + 1) cin >> value[i];
    loop(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    dfs(1, 0);
 
    loop(i, 0, idx)
    {
        if (mp[flat[i]].fi == i)
            a[i] = value[flat[i]];
        else
            a[i] = -value[flat[i]];
    }
 
    seegTree st(2 * n);
    st.build(0, 2 * n - 1, 1);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos, val;
            cin >> pos >> val;
            st.update(0, 2 * n - 1, 1, mp[pos].fi, val);
            st.update(0, 2 * n - 1, 1, mp[pos].si, -val);
        }
        else
        {
            int node;
            cin >> node;
            cout << st.query(0, 2 * n - 1, 1, 0, mp[node].fi) << endl;
        }
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