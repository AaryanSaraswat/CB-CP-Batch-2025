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

int power(int a, int b, int m)
{
    if (b == 0)
        return 1;
    if(a>m) a %= m;
    int halfPow = power(a, b / 2, m);
    int result = halfPow * halfPow % m;
    if (b & 1) // if b is odd
        result = result * a % m;
    return result;
}

int main()
{
    cout << (4 - 9) % 4 << endl; // Expected 3 recieved -1
    cout << ((4 % 4) - (9 % 4) + 4) % 4 << endl;  // Expected 3 recieved 3

    cout<<power(15,7)<<endl;

    return 0;
}