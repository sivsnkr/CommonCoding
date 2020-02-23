#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        int sum = 0;
        if(a>0){
            sum++;
            a--;
        }
        if(b>0){
            sum++;
            b--;
        }
        if(c>0){
            sum++;
            c--;
        }

        if(a>2&&b>2&&c>2)
            sum++;
        if(a>0&&max(max(a,b),c)>=2)
            a = max(max(a,b),c);

        if(a>0&&b>0){
            sum++;
            a--,b--;
        }
        if(a>0&&c>0){
            sum++;
            a--,c--;
        }
        if(b>0&&c>0){
            sum++;
            b--,c--;
        }

        cout<<sum<<endl;
    }
}