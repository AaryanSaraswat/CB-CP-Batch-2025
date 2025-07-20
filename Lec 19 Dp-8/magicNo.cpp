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

int dp[2010][2010][2][2]; // {index, modVal , isTight, isTigh2}

int f(int index,int modVal,bool isTight,bool isTight2,string &a,string &b,int d,int m){
    if(index==sz(a)+1) return modVal==0;
    if(dp[index][modVal][isTight][isTight2]!=-1) return dp[index][modVal][isTight][isTight2];
    int ans=0;
    int low = isTight2? a[index-1]-'0' : 0;
    int limit = isTight? b[index-1]-'0' : 9;
    for(int digit=low;digit<=limit;digit++){
        int newTight = isTight && (digit==limit);
        int newTight2 = isTight2 && (digit==low);
        if(((index&1) and digit!=d) or (index%2==0 and digit==d)) 
            ans=(ans+f(index+1,(modVal*10+digit)%m,newTight,newTight2,a,b,d,m))%MOD;  
    }
    return dp[index][modVal][isTight][isTight2] = ans;
}


void solve(){
    int m,d; cin>>m>>d;
    string a,b; cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<< f(1,0,1,1,a,b,d,m)<<endl;
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
