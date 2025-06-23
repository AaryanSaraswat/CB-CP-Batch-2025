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
    int n,m; cin>>n>>m;
    vector<string> grid(n);
    for(auto &s:grid) cin>>s;

    // dp[i][j] -> no of ways to reach cell i,j
    // transition dp[i][j] = dp[i-1][j] + dp[i][j-1]
    // base case dp[1][1]=1;
    // final ans dp[n][m]

    vvi dp(n+1,vi(m+1,0));
    dp[1][1] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // blocked hai to compute na karein
            if(grid[i-1][j-1]=='#') continue;
            if (i==1 && j==1) continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;

            // op2 compute karte time acees mat karna
            // if(grid[i-2][j-1]!='#') dp[i][j]+=dp[i-1][j];
            // if(grid[i-1][j-2]!='#') dp[i][j]+=dp[i][j-1];
        }
    }

    // final ans
    cout<<dp[n][m]<<endl;
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
