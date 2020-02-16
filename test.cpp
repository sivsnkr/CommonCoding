/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    
    long long int left = numeric_limits<long long int>::max(),right = 0;
    while(t--){
        long long int l,r;
        cin>>l>>r;
        
        if(l < left){
            left = l;
        }
        
        if(r > right){
            right = r;
        }
    }
    
    cout<<left<<" "<<right<<endl;
}