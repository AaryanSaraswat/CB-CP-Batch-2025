#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    int dp[n+1]; 

    // smallest sub problem jiska ans pata h
    dp[0]=0;
    dp[1]=1;

    for(int k=2;k<=n;k++){
        // transition 
        dp[k]= dp[k-1] + dp[k-2];
    }

    // final ans
    cout<<dp[n]<<endl;

    return 0;
}