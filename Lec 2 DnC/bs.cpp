#include <bits/stdc++.h>
using namespace std;

bool f(int x){
    //predicate function 
    // or condition check
}

int main()
{
    int st,en,ans=0;
    while(st<=en){
        int mid=(st+en)/2; // or st+(en-st)/e;
        if(f(mid)){
            ans=mid;
            st=mid+1;
        }
        else en=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}