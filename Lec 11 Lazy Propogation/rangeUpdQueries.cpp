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
 
vi tree,a,lazy;
 
void build(int l,int r,int index){
    if(l==r){
        tree[index]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,2*index);
    build(mid+1,r,2*index+1);
    tree[index]=max(tree[2*index],tree[2*index+1]);
}
 
void update(int l, int r, int index, int lq, int rq, int val) {
    if (lazy[index] != 0) { // lazy ki value hai to resolve karo
        tree[index] += lazy[index];
        if (l != r) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        } 
        lazy[index] = 0;
    }
 
    if (r < lq || l > rq) return; // no overlap
 
    if (lq <= l && r <= rq) { // complete overlap
        tree[index] += val;
        if (l != r) {
            lazy[2 * index] += val;
            lazy[2 * index + 1] += val;
        }
        return;
    }

    // partial overlap
    int mid = (l + r) / 2;
    update(l, mid, 2 * index, lq, rq, val);
    update(mid + 1, r, 2 * index + 1, lq, rq, val);
    tree[index] = max(tree[2 * index], tree[2 * index + 1]);
}
 
int query(int l, int r, int index, int pos) {
    if (lazy[index] != 0) { // lazy use karlo
        tree[index] += lazy[index];
        if (l != r) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
 
    if (l == r) return tree[index]; // leaf node
    

    // check karna hai ki left jau ya right
    int mid = (l + r) / 2;
    if (pos <= mid) return query(l, mid, 2 * index, pos);
    else return query(mid + 1, r, 2 * index + 1, pos);
}
 
void solve(){
    int n,q; cin>>n>>q;
    a.resize(n), tree.resize(4*n),lazy.resize(4*n,0);
    for(auto &i:a) cin>>i;
    build(0,n-1,1);
    while (q--)
    {
        int type; cin>>type;
        if(type==1){
            int l,r,x; cin>>l>>r>>x;
            update(0,n-1,1,l-1,r-1,x);
        }
        else{
            int idx; cin>>idx;
            cout<<query(0,n-1,1,idx-1)<<endl;
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