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
    
    // dp[n][k] -> n items mein se k profit lane k liye min weight kitna chaiye
    // transition 
    // dp[n][k] -> dp[i-1][k-val]+wt , dp[i-1][k] {min}
    // base case dp[i][0] = 0 dp[0][i] = 1e9 
    // final ans dp[n][i] -> jhn bhi wt mere avail se kam hoga vo (i->0 maxProfit)
    
    int n,wt; cin>>n>>wt;
    vi weight(n),val(n);
    loop(i,0,n) cin>>weight[i]>>val[i];
    lli maxProfit=accumulate(all(val),0); // sum of all values
    
    vector<vector<int>> dp(n+1,vector<int>(maxProfit+1,0));

    // base case 
    loop(i,0,maxProfit+1) dp[0][i]=1e18;
    loop(i,0,n+1) dp[i][0]=0;

    // dp fill karni h 
    for(int i=1;i<=n;i++){
        for(int x=1;x<=maxProfit;x++){
            // trnsition 
            int elWeight = weight[i-1];
            int elVal = val[i-1];
            
            int pick=1e18,skip=1e19;
            if(x-elVal>=0 and dp[i-1][x-elVal]!=1e18)
                pick=dp[i-1][x-elVal]+elWeight; // pick
            skip=dp[i-1][x]; // skip kardo
            
            dp[i][x]=min(pick,skip); 
        }
    }

    // final ans
    int ans=0;
    for(int profit=maxProfit;profit>=0;profit--){
        if(dp[n][profit]<=wt) {
            ans=profit;
            break;
        }
    }
    cout<<ans<<endl;
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
