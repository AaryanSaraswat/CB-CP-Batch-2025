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

int dp[10010][110][2];

void solve()
{
    string k;
    int d;
    cin >> k >> d;

    memset(dp, -1, sizeof(dp));

    auto f = [&](auto &&self, int index, int isTight, int modSum) -> lli
    {
        if (index == sz(k))
        {
            if (modSum == 0) return 1;
            return 0;
        }

        if (dp[index][modSum][isTight] != -1) return dp[index][modSum][isTight];

        int ans = 0;
        int limit = isTight ? k[index] - '0' : 9;
        for (int digit = 0; digit <= limit; digit++)
        {
            bool newIsTight = isTight && ((k[index] - '0') == digit);
            ans = (ans + self(self, index + 1, newIsTight, (modSum + digit) % d)) % MOD;
        }
        return dp[index][modSum][isTight] = ans;
    };

    cout << (f(f, 0, 1, 0) - 1 + MOD) % MOD << endl;
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
