#include <bits/stdc++.h>
using namespace std;

int main()
{
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
}