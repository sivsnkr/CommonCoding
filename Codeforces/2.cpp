#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, s;
        cin >> n >> s;
        vector<long int> time(n);

        int i;
        for (i = 0; i < n; i++)
        {
            cin >> time[i];
        }

        long long int sum = 0;
        long int maxTime = 0;
        int skip = 0;
        int maxIndex = 0;
        for (i = 0; i < n; i++)
        {
            sum += time[i];
            if (time[i] >= maxTime && skip == 0)
            {
                maxTime = time[i];
                maxIndex = i;
            }

            if (sum > s && skip < 1)
            {
                sum -= maxTime;
                skip++;
            }
            else if (sum > s)
            {
                break;
            }
        }
        if (skip > 0)
            cout << maxIndex + 1 << endl;
        else
            cout << 0 << endl;
    }
}