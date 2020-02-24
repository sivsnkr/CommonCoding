#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        long int n,x,y;
        cin>>n>>x>>y;
        long int bestp,worstp;
        bestp = min(x,y);
        if(bestp>1)
        	bestp--;

        worstp = x+y-1;
        if(worstp>n)
        	worstp = n;

        cout<<bestp<<" "<<worstp<<endl;
    }
}