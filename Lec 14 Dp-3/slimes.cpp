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
    vi a(n); for(auto &i:a) cin>>i;

    vvi dp(n,vi(n,1e18));
    vvi sum(n,vi(n,0));
    loop(i, 0, n) // sum pre compute between every i and j
    {
        int curr = 0;
        loop(j, i, n)
        {
            curr += a[j];
            sum[i][j] = curr;
        }
    }

    // dp[l][r] -> min cost to combine slimes between l and r
    // dp[l][r] = min(dp[l][k]+dp[k+1][r]+sum(l,r)) (k->l,r-1)

    // base case for single element cost will be 0
    loop(i,0,n) dp[i][i]=0;

    for(int l=n-1;l>=0;l--){
        for(int r=l+1;r<n;r++){
           for(int k=l;k<r;k++){
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+sum[l][r]);
           }
        }
    }

    // final ans dp[0][n-1]
    cout<<dp[0][n-1]<<endl;
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
