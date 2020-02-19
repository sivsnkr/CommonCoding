#include<bits/stdc++.h>
using namespace std;

void kthPlaindrome(long int n, long int k, long  int sum, long int i,int s[]){
    s[0] = 1;
    int j;
    for(j = 1; j <= i-2; j++){
        s[j] = 0;
    }

    s[i-1] = 1;

    k-=sum;

    // cout<<"sum "<<sum<<endl;

    // cout<<"k "<<k<<endl;

    for(j = 0; j <= ceil(float(i)/2)-1; j++){
        if(j == 0){
            s[0] = ceil(float(k)/pow(10,ceil(float(i)/2)-1));            
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

long long int decodePlainDrome(long long int n){
    string s = to_string(n);
    int length = s.length();

    long long int sum = 1;
    int i;
    for(i = 1; i < length; i++){
        sum+=9*pow(10,ceil(float((i-1)/2)));
    }

    int power = ceil(float(length)/2)-1;

    for(i = 0; i <= ceil(float(length)/2)-1; i++){
        int num = s[i]-48;        if(i == 0){
            sum+=(num-1)*pow(10,power);
        }else{
            sum+=(num+1)*pow(10,power);
        }
        power--;
    }

    return sum;
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

long long int giveNearstPlain(long long int x){
    string s = to_string(x);
    string t = "";
    int size = s.length();

    if(size == 2|| size == 1){
        while(!isPlain(x)){
            x--;
        }
        return x;
    }

    int i;
    t+=s[0];
    for(i = 1; i < s.length()-1; i++){
        t+=to_string(min(s[i]-48,s[size-i-1]-48));
    }

    t+=t[0];

    long long int num = stoll(t);

    if(num>x){
        num -= pow(10,size/2);
    }

    return num;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        long int x,k;
        cin>>x>>k;

        if(isPlain(x))
            k--;

        x = giveNearstPlain(x);
        // cout<<"x "<<x<<endl;
        long long int index = decodePlainDrome(x);

        // cout<<"INdex "<<index<<endl;
        k+=index;
        long int sum = 0;
        long int i = 1;
        while(1){
            long int res = 9*pow(10,ceil(float((i-1)/2)));
            if(sum+res < k)
                sum+=res;
            else
                break;
            i++;
        }


        int s[i];

        kthPlaindrome(1,k,sum,i,s);

        int j;

        for(j = 0; j < i; j++){
            cout<<s[j];
        }
        cout<<endl;
    }

    // cout<<s<<endl;
}