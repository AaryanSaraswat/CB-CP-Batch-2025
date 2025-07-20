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

double dp[310][310][310];

void solve()
{
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    loop(i, 0, n)
    {
        int el;
        cin >> el;
        if (el == 1)
            c1++;
        else if (el == 2)
            c2++;
        else if(el==3)
            c3++;
    }

    auto f = [&](auto &&self, int c1, int c2, int c3) -> double
    {
        if (c1 < 0 or c2 < 0 or c3 < 0)  return 0;
        if (c1 == 0 and c2 == 0 and c3 == 0)  return dp[c1][c2][c3] = 0;
        if (dp[c1][c2][c3] > -1) return dp[c1][c2][c3];
        double ans = n + c1 * self(self, c1 - 1, c2, c3) + c2 * self(self, c1 + 1, c2 - 1, c3) + c3 * self(self, c1, c2 + 1, c3 - 1);
        return dp[c1][c2][c3] = ans / (c1 + c2 + c3);
    };

    memset(dp, -1, sizeof(dp));
    cout << fixed << setprecision(10) << f(f, c1, c2, c3) << endl;
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
