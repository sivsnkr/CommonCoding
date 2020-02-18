#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<long double> x(n);

    int i;
    for(i = 0; i < n; i++){
        cin>> x[i];
    }

    long double sum = 0;

    for(i = 0; i < n; i++){
        sum += (float(n-1)/2)*sin(2*x[i]);
    }
    printf("%.2Lf\n", sum);
}