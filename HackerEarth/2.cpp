#include <bits/stdc++.h>
using namespace std;

long long int getInt(int arr[],int size){
    long long int sum = 0;
    for(int i = 0; i < size/2; i++){
        arr[size-i-1] = arr[i];
    }

    // string s = "";

    int power = 0;

    bool start = false;

    for(int i = size-1; i >= 0; i--){
        // sum+=arr[i]*pow(10,10-i-1);
        if(arr[i]!=0||start){
            sum+=arr[i]*pow(10,power);
            power++;
            start = true;
        }
    }

    // for(int i = 0; i <= 9; i++){
    //     cout<<arr[i];
    // }

    // cout<<endl;

    // cout<<"return sum"<<endl;

    // cout<<sum<<endl;

    // long long int num = stoll(s);
    // cout<<s<<endl;

    // cout<<num<<endl;

    return sum;
}

long int binarySearch(vector<long long int> a, long long int value){
    long start = 0,end = a.size()-1;

    while(start<end){
        long int mid = (start+end)/2;

        if(a[mid] == value)
            return mid;
        else if(a[mid] > value)
            end = mid-1;
        else
            start = mid+1;
    }

    return start;
}

int main()
{
    // int t;
    // cin>>t;

    int i,j,k,l,m;

    int arr[18]={0};
    int arr1[17]={0};

    vector<long long int> a;

    for(i = 0; i <=9; i++){
        arr[0] = i;
        for(j = 0; j <=9; j++){
            arr[1] = j;
            for(k = 0; k <=9; k++){
                arr[2] = k;
                for(l = 0; l <= 9; l++){
                    arr[3] = l;
                    for(m = 1; m <=9; m++){
                        for(int s = 0; s <= 9; s++){
                            for(int o = 0; o <=9; o++){
                                for(int p = 0; p <= 9; p++){
                                    for(int q = 0; q <= 9; q++){
                                        // for(int r= 0; r <=9; r++){
                                        //     //fsf
                                        // }
                                    }
                                }
                            }
                        }
                        // arr[4] = m;
                        // long long int num = getInt(arr,10);
                        // a.push_back(num);
                    }
                }
            }
        }
    }

    // for(i = 0; i <=9; i++){
    //     arr1[0] = i;
    //     for(j = 0; j <=9; j++){
    //         arr1[1] = j;
    //         for(k = 0; k <=9; k++){
    //             arr1[2] = k;
    //             for(l = 0; l <= 9; l++){
    //                 arr1[3] = l;
    //                 for(m = 0; m <=9; m++){
    //                     arr1[4] = m;
    //                     for(int s = 0; s <=9; s++){
    //                         arr1[5] = s;

    //                         long long int num = getInt(arr1,11);
    //                         a.push_back(num);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    // for(i = 1; i <= 9; i++){
    //     a.push_back(i);
    // }

    // sort(a.begin(),a.end());

    // for(i = 0; i < t; i++){
    //     long int x,k;
    //     cin>>x>>k;

    //     long int index = binarySearch(a,x);
    //     bool res = a[index]==x;
    //     // cout<<"Index "<<index<<" "<<res<<endl;
    //     if(a[index]<x)
    //         index++;
    //     cout<<a[index+k-1]<<endl;
    // }

    // cout<<a[0]<<" "<<a[1]<<endl;

    // for(i = 1; i <= 32; i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
}