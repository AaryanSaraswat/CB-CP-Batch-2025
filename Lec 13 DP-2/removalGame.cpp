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
 
const int N = 5005;
const int inf = 1e15;
 
int dp[N][N]={0}, sum[N][N]={0};

 
int32_t main()
{
    fastio;
    int n; cin >> n;
 
    vi a(n);
    for (auto &i : a) cin >> i;
 
    loop(i, 0, n) // sum pre compute between every i and j
    {
        int curr = 0;
        loop(j, i, n)
        {
            curr += a[j];
            sum[i][j] = curr;
        }
    }

    // dp[i][j] -> max score btwn i and j any player can get
 
    loopD(i, n - 1, 0)
    {
        loop(j, 0, n)
        {
            if (i > j) continue;
            if (i == j) dp[i][j] = a[i]; // base case
            else  dp[i][j] = max((a[i] + sum[i + 1][j] - dp[i+1][j]),
                               (a[j] + sum[i][j - 1] - dp[i][j-1])); // transition
        }
    }
    
    // final ans
    cout << dp[0][n - 1] << endl;
}