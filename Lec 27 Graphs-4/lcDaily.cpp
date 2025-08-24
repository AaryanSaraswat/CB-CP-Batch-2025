#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define loopD(i, a, n) for (lli i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(a) ((int)a.size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
// #define endl '\n'
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define fi first
#define si second
#define v(a) vector<int>(a)
#define vv(a) vector<vector<int>>(a)
#define pansent(c, x) ((c).find(x) != (c).end())
#define set_bits __builtin_popcountll
#define MOD 1000000007
// #define int long long

typedef long long lli;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umpi;
typedef map<int, int> mpi;
typedef vector<pii> vp;
typedef vector<lli> vll;
typedef vector<vll> vvll;

static int dp[32][32][32][32][4];
class Solution {
    public:
    int minimumSum(vector<vector<int>>& grid) {
        lli n=sz(grid),m=sz(grid[0]);

        auto f = [&](int i1, int j1, int i2, int j2, int k) {
            lli rmn=n,rmx=0,clmn=m,clmx=0;
            loop(i,i1,i2+1) loop(j,j1,j2+1) if(grid[i][j]==1) rmn=min(rmn,i),rmx=max(rmx,i),clmn=min(clmn,j),clmx=max(clmx,j);
            if (rmn == n) return 0ll; 
            return (rmx-rmn+1)*(clmx-clmn+1);
        };

        auto f2 = [&](auto &&self, int i1, int j1, int i2, int j2, int k) {
            if(dp[i1][i2][j1][j2][k]!=-1) return dp[i1][i2][j1][j2][k];
            int ans = 1e9;
            
            if (k == 1) ans = f(i1, j1, i2, j2, k);
            else if (k == 2) { // try 1 vertical + 1 horz cut
                loop(i,i1,i2) ans = min(ans, self(self,i1, j1, i, j2, 1) + self(self,i + 1, j1, i2, j2, 1));
                loop(j,j1,j2) ans = min(ans, self(self,i1, j1, i2, j, 1) + self(self,i1, j + 1, i2, j2, 1));
            } else if (k == 3) { // make 1 cut and find 2 rectangkles on both sides -> take min
                loop(i,i1,i2) { 
                    ans = min(ans, self(self,i1, j1, i, j2, 1) + self(self,i + 1, j1, i2, j2, 2));
                    ans = min(ans, self(self,i1, j1, i, j2, 2) + self(self,i + 1, j1, i2, j2, 1));
                }
                loop(j,j1,j2) {
                    ans = min(ans, self(self,i1, j1, i2, j, 1) + self(self,i1, j + 1, i2, j2, 2));
                    ans = min(ans, self(self,i1, j1, i2, j, 2) + self(self,i1, j + 1, i2, j2, 1));
                }
            }
            return  dp[i1][i2][j1][j2][k] = ans;
        };
        loop(i1,0,n+2) loop(i2,0,n+2) loop(j1,0,m+2) loop(j2,0,m+2) loop(k,0,4) dp[i1][i2][j1][j2][k]=-1;
        return f2(f2,0, 0, n - 1, m - 1, 3);
    }
};