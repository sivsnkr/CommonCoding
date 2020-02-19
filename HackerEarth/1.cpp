#include<bits/stdc++.h>
using namespace std;

void kthPlaindrome(long int n, long int k, long  int sum, long int i,int s[]){
    while(1){
        long int res = 9*pow(10,ceil(float((i-1)/2)));
        if(sum+res < k)
            sum+=res;
        else
            break;
        i++;
    }

    s[0] = 1;
    int j;
    for(j = 1; j <= i-2; j++){
        s[j] = 0;
    }

    s[i-1] = 1;


    // cout<<"i "<<i<<endl;

    // for(j = 0; j < i; j++){
    //     cout<<s[j];
    // }

    // cout<<endl;

    k-=sum;

    // cout<<"Sum "<<sum<<endl;

    // cout<<"K "<<k<<endl;

    for(j = 0; j <= ceil(float(i)/2)-1; j++){
        if(j == 0){
            s[0] = ceil(float(k/pow(10,ceil(float(i)/2)-1)));            
            k-=(s[0]-1)*pow(10,ceil(float(i)/2)-1);
        }else{
            s[j] = k/pow(10,ceil(float(i)/2)-1-j)-1;
            k-=((s[j]+1)*pow(10,ceil(float(i)/2)-1-j));
        }
    }

    for(j = 0; j <= ceil(float(i)/2)-1; j++){
        s[i-j-1] = s[j];
    }
}

bool isPlain(long int n){
    string s = to_string(n);

    int size = s.length();
    for(int i = 0; i < size/2; i++){
        if(s[i]!=s[size-i-1]){
            return false;
        }
    }

    return true;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        long int x,k;
        cin>>x>>k;
        while(!isPlain(x)){
            x--;
            k++;
        }

        k+=(x-1);

        long int sum = 0;
        long int i = 1;
        // long int n = x;
        while(1){
            long int res = 9*pow(10,ceil(float((i-1)/2)));
            if(sum+res < k)
                sum+=res;
            else
                break;
            i++;
        }
        int s[i];

        kthPlaindrome(x,k,sum,i,s);

        int j;

        for(j = 0; j < i; j++){
            cout<<s[j];
        }
        cout<<endl;
    }
}