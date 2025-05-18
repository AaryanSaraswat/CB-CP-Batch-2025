#include <bits/stdc++.h>
using namespace std;

#define int long long

int power(int a, int b)
{

    if (b == 1)
        return a;

    int halfpower = power(a, b / 2);
    if (b & 1) return halfpower * halfpower * a;
    return halfpower * halfpower;
}

const int MOD = 1e9 + 7;

int powermod(int a, int b)
{

    if (b == 1) return a;
    a%=MOD;
    int halfpower = powermod(a, b / 2); 
    if (b & 1) return (((halfpower % MOD) * (halfpower % MOD)) % MOD * (a % MOD)) % MOD;
    return (halfpower * halfpower) % MOD;
}

int main()
{

    return 0;
}