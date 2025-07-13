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

static int dp[20][(1<<18)];

void solve(){
    int n,m,k; cin>>n>>m>>k;
    vi a(n); loop(i,0,n) cin>>a[i];

    map<pii,int> rules;
    while(k--){
        int x,y,c; cin>>x>>y>>c;
        rules[{x-1,y-1}]=c;
    }

    memset(dp,-1,sizeof(dp));
    auto f=[&](auto &&self, int prevDish, int mask){
        int cntDishesEaten = set_bits(mask); // updated this as it was giving mle so reduced a state using state optimization
        // cntDishesEaten = setbit/ eaten dishes in mask
        if(cntDishesEaten>=m) return 0ll; // base case
        
        if(dp[prevDish][mask]!=-1) return dp[prevDish][mask];

        int satisfaction = 0;
        for(int dish=0;dish<n;dish++){
            if(mask&(1<<(dish))) continue;
            int extra= rules[{prevDish,dish}];
            satisfaction=max(satisfaction,self(self,dish,mask|(1<<(dish)))+a[dish]+extra);
        }
        return dp[prevDish][mask] = satisfaction;
    };

    cout<<f(f,n+1,0)<<endl;
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
