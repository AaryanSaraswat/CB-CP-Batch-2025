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

int dp[20][4][2]; // {index, cnt , isTight}

int f(int index,int cnt,bool isTight,string &s){
    if(index==sz(s)) return 1;
    if(dp[index][cnt][isTight]!=-1) return dp[index][cnt][isTight];
    int ans=0;
    int limit = isTight? s[index]-'0' : 9;
    for(int digit=0;digit<=limit;digit++){
        int newTight = isTight && (digit==(s[index]-'0'));
        if(digit>0 and cnt>=3)  continue;
        ans=(ans+f(index+1,digit==0?cnt: cnt+1,newTight,s));  
    }
    return dp[index][cnt][isTight] = ans;
}

int ff(string s){
    memset(dp,-1,sizeof(dp));
    return f(0,0,1,s);
}

void solve(){
    int l,r;
    cin>>l>>r;
    cout<<ff(to_string(r))- ff(to_string(l-1))<<endl;
}

int32_t main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
