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

void solve()
{
    // state   hint -> think of just 1 bit\

    // r1 -> a1 1
    // r2 -> a2 1
    // r3 -> a3 1
    // xor ->   1

    // 0th bit

    // modify grid
    // if ith bit is set -> 1
    // if ith bit is not set -> 0
    // 7 7 7
    // 7 7 10

    // 1 1 1
    // 1 1 0

    // can we choose nos in such a way that final cnt of 1 is odd
    // int t= (a&(1<<bits));

    // states
    //  dp[i][0] -> is it possible to have odd no of ones till ith row
    //  dp[i][1] -> is it possible to have even no of ones till ith row

    // base case 1 1 0 1 1
    //  dp[0][1] -> 

    // transition
    //  dp[i][0] ->  1(element) -> dp[i-1][1](true) -> true
    //           ->  0(element) -> dp[i-1][0](true) -> true

    // dp[i][1] ->  1(element) -> dp[i-1][0](true) -> true
    //          ->  0(element) -> dp[i-1][1](true) -> true

    // nth row tak odd no of 1s lana possible hai ya nahi? dp[n][0] -> 1 (final ans)

    // time complexity -> n*m*2*1*10
    // space -> (n*m(grid) + n*2(dp))*10(for every bit)


    // no of 1s + nos of 0s -> total no of elements in a row(m)

    // ip
    int n, m;
    cin >> n >> m;
    vvi grid(n, vi(m, 0));
    for (auto &r : grid)
        for (auto &i : r)
            cin >> i;

    for (int bit = 0; bit < 10; bit++)
    {
        vector<int> noOfOnes(n);
        vp pos(n,{-1,-1}); // row -> {index of el jiski bit set h, idx of el jiski bit not set h}
        loop(i,0,n)
        {
            loop(j,0,m)
            {
                int no=grid[i][j];
                int mask  = (1<<bit);
                int currBit = (no&mask);
                if(currBit){
                    noOfOnes[i]++;
                    pos[i].fi=j;
                }else{
                    pos[i].si=j;
                }
            }
        }

        bool dp[n][2]={0};

        // base case
        if(noOfOnes[0]<m) dp[0][1]=1;
        if(noOfOnes[0]>0) dp[0][0]=1;

        for(int i=1;i<n;i++){
            dp[i][0] = (noOfOnes[i]>0 and dp[i-1][1])|(noOfOnes[i]<m and dp[i-1][0]);
            dp[i][1] = (noOfOnes[i]>1 and dp[i-1][0]) | (noOfOnes[i]<m and dp[i-1][1]);
        }

        if(dp[n-1][0]){
            // ans exist karta hai
            // do ans construction 
            // n-1th -> odd no of ones 
        }
    }
    // kisi ki bhi bit ke liye ans nahi mila
    // mana karna 
    
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
