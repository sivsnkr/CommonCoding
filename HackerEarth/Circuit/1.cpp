#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        vector<int> numbers(n);
        int j;
        for(j = 0; j < n; j++)
        {
            cin>>numbers[j];
        }

        sort(numbers.begin(),numbers.end());

        int min = INT_MAX;

        for(j = 0; j < n-1; j++)
        {
            int res = numbers[j]^numbers[j+1];
            if(res < min)
            {
                min = res;
            }
        }

        cout<<min<<endl;
    }
}