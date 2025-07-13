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
    unordered_map<int, int> dp;
    vi a(n); for(auto &i:a) cin>>i,dp[i]=0;

    int len=0,lastIdx=0;

   loop(i,0,n){
        int el=a[i];
        int prevEl=el-1;
        dp[el]=max(dp[prevEl]+1,dp[el]);
        if(len<dp[el]){
            len=dp[el];
            lastIdx=i;
        }
    }
    vi ans;
    int el=a[lastIdx];
    loopD(i,lastIdx,0){
        if(a[i]==el){
            ans.pb(i); 
            el--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<len<<endl;
    for(auto i:ans)cout<<i+1<<" ";
    cout<<endl;
    
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
