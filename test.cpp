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
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        unordered_map<char,int> freq;
        
        int flag = 1;
        
        for(char a : s){
            if(freq.find(a)==freq.end()){
                freq.insert({a,1});
            }else{
                freq[a]++;
            }
        }
        
        
        unordered_map<char,int>::iterator it = freq.begin();
        
        int prevF = (*it).second;
        
        it++;
        
        
        
        if(freq.size()!=3){
            flag= 0;
        }else
        for(it = it; it!=freq.end(); it++){
            if((*it).second!=prevF){
                flag = 0;
                break;
            }
        }
        
        char pChar = s[0];
        
        for(int i = 0; i < s.length(); i++){
            if(i%prevF!=0&&i!=0){
                if(s[i]!=pChar){
                    flag = 0;
                    break;
                }
            }
            pChar = s[i];
        }
        if(flag){
            cout<<"OK";
        }else{
            cout<<"Not OK";
        }
        cout<<endl;
    }
}