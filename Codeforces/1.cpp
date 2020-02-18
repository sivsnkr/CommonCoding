#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n;
       long int x;
       cin>>n>>x;

       vector<long int> fp(n);

       int i;
       for(i = 0; i < n; i++){
        cin>>fp[i];
       }

       sort(fp.begin(),fp.end(),[](long int a, long int b)->bool{
        return a>b;
       });

       long long int sum = 0;

       int counter = 0;


       for(i = 0; i <  n;i++){
        sum+=fp[i];
        counter++;
        if(sum>=x){
            break;
        }
       }

       if(counter == 1){
        if(sum!=x){
            counter++;
        }
       }

       cout<<counter<<endl;
    }
}