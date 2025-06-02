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
    int n,q; cin>>n>>q;
    vector<string> a(n);
    for(auto &i:a) cin>>i;
    

    // 1 based 2d prefix sum
    vvi pre(n+1,vi(n+1,0));
    loop(i,1,n+1){
        loop(j,1,n+1){
            pre[i][j]=(a[i-1][j-1]=='*')+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    
    while (q--)
    {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        cout<<pre[x2][y2]-pre[x2][y1-1]-pre[x1-1][y2]+pre[x1-1][y1-1]<<endl;
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