#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i;
    set<int> notShake;
    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int no;
            cin >> no;
            notShake.insert(no);
        }
    }
}