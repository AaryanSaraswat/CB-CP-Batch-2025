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
    vvi a; // ip lena baki h

    vvi pre(n,vi(m,0));


    // 0 based pre sum
    loop(i,0,n){
        loop(j,0,m){
            pre[i][j]=a[i][j];
            if(i-1>=0) pre[i][j]+=pre[i-1][j];
            if(j-1>=0) pre[i][j]+=pre[i][j-1];
            if(j-1>=0 and i-1>=0) pre[i][j]-=pre[i-1][j-1];
        }
    }

    // 1 based pre sum
    vvi pre1(n+1,vi(m+1,0));
    loop(i,1,n+1){
        loop(j,1,m+1){
            int a; cin>>a;
            pre[i][j]=a+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
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
    cin >> tc;
    while (tc--)
    {
        
    }
    return 0;
}
