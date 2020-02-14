#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (i + j == 12)
            {
                cout << i << " " << j << endl;
            }
        }
    }
}