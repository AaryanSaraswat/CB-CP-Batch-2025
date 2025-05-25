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

vi fact, inv_fact;

int power(int a, int b)
{
    if (b == 0)
        return 1;

    int halfPow = power(a, b / 2);
    if (b & 1) // odd hai to
        return halfPow * halfPow * a;
    return halfPow * halfPow;
}

lli power(lli a, lli b, lli m)
{
    if (b == 0)
        return 1;
    if (a > m)
        a %= m;
    lli halfPow = power(a, b / 2, m);
    lli result = halfPow * halfPow % m;
    if (b & 1) // if b is odd
        result = result * a % m;
    return result;
}

int nCr(int n, int r)
{
    if (r < 0 or r > n)
        return 0;
    return ((fact[n] * inv_fact[n - r]) % MOD * inv_fact[r]) % MOD;
}

int nCr(int n, int r)
{
    lli res = 1;
    for (int i = 1; i <= r; i++)
    {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int32_t main()
{
    int n = 1e4, r = 5;
    // cin >> n >> r;

    fact.resize(n + 1), inv_fact.resize(n);

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    inv_fact[n] = power(fact[n], MOD - 2, MOD);

    for (int i = n - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;

    cout << nCr(n, r) << endl; // 70
}
