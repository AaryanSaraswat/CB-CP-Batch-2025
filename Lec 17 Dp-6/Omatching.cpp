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
// #define MOD 1000000007
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

const int mod=1e9+7;
static int dp[21][(1<<21)+1];

void solve(){
    int n; cin>>n;
    vvi compatability(n,vi(n));
    for(auto &r:compatability) for(auto &i:r) cin>>i;

    // lambda functions
    function<int(int,int)> ff=[&](int currMan,int mask)->int{
        //logic
    };

    memset(dp,-1,sizeof(dp)); 
    
    // lambda function with auto keyword
    // self is used only in recursive functions
    auto f=[&](auto &&self,int currMan,int mask)->int{
        if(currMan==n) return 1;
        if(dp[currMan][mask]!=-1) return dp[currMan][mask]; // check before calculate
        int noOfWays=0;
        for(int w=0;w<n;w++){
            if(compatability[currMan][w]==1 and ((mask&(1<<w))==0)){
                noOfWays=(noOfWays+self(self,currMan+1,(mask|(1<<w))))%mod;
            }
        }
        return dp[currMan][mask]=noOfWays; // store before return
    };

    cout<<f(f,0,0)<<endl;
}

int32_t main()
{
//     fastio;

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    solve();
    return 0;
}
