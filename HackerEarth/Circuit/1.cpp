#include <bits/stdc++.h>
using namespace std;

int main()
{
<<<<<<< HEAD
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
=======
    long int e = 100000000;
    time_t cur1 = time(NULL);
    cout << "time1 " << cur1 << endl;
    for (int i = 0; i < e; i++)
    {
        // just loop
    }
    time_t cur2 = time(NULL);
    int dif = (cur2 - cur1);
    cout << dif << endl;
>>>>>>> f897f82e589c56bc1b59d0cdaa0a9355c1b60465
}