#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// #define LC_HACK
// #ifdef LC_HACK
// const auto __ = []()
// {
//     struct ___
//     {
//         static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
//     };
//     std::atexit(&___::_);
//     return 0;
// }();
// #endif

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
// #define MOD 1000000007
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

using ll = long long;
using ull = unsigned long long;
typedef unsigned int uint;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B)
{
    return (ull)rng() % B;
}

const uint MOD = 1000000007;
template <uint mod = MOD>
struct mint
{ // 1000000007  1000000009
    uint x;

    mint() : x(0) {}
    mint(ll _x)
    {
        _x %= mod;
        if (_x < 0)
            _x += mod;
        x = _x;
    }

    mint &operator+=(const mint &a)
    {
        x += a.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint &a)
    {
        x += mod - a.x;
        if (x >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint &a)
    {
        x = (ull)x * a.x % mod;
        return *this;
    }
    mint pow(ll pw) const
    {
        mint res = 1;
        mint cur = *this;
        while (pw)
        {
            if (pw & 1)
                res *= cur;
            cur *= cur;
            pw >>= 1;
        }
        return res;
    }
    mint inv() const
    {
        assert(x != 0);
        uint t = x;
        uint res = 1;
        while (t != 1)
        {
            uint z = mod / t;
            res = (ull)res * (mod - z) % mod;
            t = mod - t * z;
        }
        return res;
    }
    mint &operator/=(const mint &a)
    {
        return *this *= a.inv();
    }
    mint operator+(const mint &a) const
    {
        return mint(*this) += a;
    }
    mint operator-(const mint &a) const
    {
        return mint(*this) -= a;
    }
    mint operator*(const mint &a) const
    {
        return mint(*this) *= a;
    }
    mint operator/(const mint &a) const
    {
        return mint(*this) /= a;
    }

    bool sqrt(mint &res) const
    {
        if (mod == 2 || x == 0)
        {
            res = *this;
            return true;
        }
        if (pow((mod - 1) / 2) != 1)
            return false;
        if (mod % 4 == 3)
        {
            res = pow((mod + 1) / 4);
            return true;
        }
        int pw = (mod - 1) / 2;
        int K = 30;
        while ((1 << K) > pw)
            K--;
        while (true)
        {
            mint t = myRand(mod);
            mint a = 0, b = 0, c = 1;
            for (int k = K; k >= 0; k--)
            {
                a = b * b;
                b = b * c * 2;
                c = c * c + a * *this;
                if (((pw >> k) & 1) == 0)
                    continue;
                a = b;
                b = b * t + c;
                c = c * t + a * *this;
            }
            if (b == 0)
                continue;
            c -= 1;
            c *= mint() - b.inv();
            if (c * c == *this)
            {
                res = c;
                return true;
            }
        }
        assert(false);
    }

    bool operator==(const mint &a) const
    {
        return x == a.x;
    }
    bool operator!=(const mint &a) const
    {
        return x != a.x;
    }
    bool operator<(const mint &a) const
    {
        return x < a.x;
    }
};
using Mint = mint<>;

class Solution
{
public:
    int countAnagrams(string s)
    {
        fastio;
        istringstream iss(s);
        string word;
        vector<string> words;
        int mx=0;
        while (iss >> word) words.pb(word),mx=max(mx,sz(word));\
        vector<Mint> fact(mx+1,1);
        loop(i,1,mx+1) fact[i]=fact[i-1]*i;
        Mint ans=1;
        for(const auto &t:words){
            umpi mp;
            Mint curr=fact[sz(t)];
            for(const auto &c:t) mp[c]++;
            for(auto [ch,freq]:mp) curr/=fact[freq];
            ans*=curr;
        }
        return ans.x;
    }

};