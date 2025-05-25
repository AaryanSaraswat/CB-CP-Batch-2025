#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
        return 1;

    int halfPow = power(a, b / 2);
    if (b & 1) // odd hai to
        return halfPow * halfPow * a;
    return halfPow * halfPow;
}

long long power(long long a, long long b, long long m)
{
    if (b == 0)
        return 1;
    if (a > m)
        a %= m;
    long long halfPow = power(a, b / 2, m);
    long long result = halfPow * halfPow % m;
    if (b & 1) // if b is odd
        result = result * a % m;
    return result;
}

const int mod = 1e9 + 7;

int main()
{
    cout << ((4 % 4) - (9 % 4) + 4) % 4 << endl;  // Expected 3 recieved 3
    cout << ((10 % mod) * (power(3, mod - 2, mod) % mod) % mod) % mod << endl; // divison
    return 0;
}