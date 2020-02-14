#include <bits/stdc++.h>
using namespace std;

bool win(long int a, long int b, long int c, vector<long int> &loosePoints)
{
    long int d = c / (a + b);
    c -= (a + b) * d;

    while (c > 0)
    {
        c -= a;
        if (c <= 0)
        {
            return true;
        }
        c -= b;
        if (c <= 0)
        {
            loosePoints.push_back(c + b);
            return false;
        }
    }
    loosePoints.push_back(b);
    return false;
}

bool possible(long double loosePoints, long int a, long int b, long int &k)
{
    long int wantNoOfTurns = ceil(loosePoints / a);
    k -= wantNoOfTurns;
    if (k >= 0)
        return true;
    return false;
}

int main()
{
    long int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<long int> hp(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> hp[i];
    }

    long int points = 0;
    vector<long int> loosePoints;
    for (i = 0; i < n; i++)
    {
        if (win(a, b, hp[i], loosePoints))
            points++;
    }

    sort(loosePoints.begin(), loosePoints.end());

    int size = loosePoints.size();

    i = 0;
    while (k > 0 && i < size)
    {
        if (possible(loosePoints[i], a, b, k))
        {
            points++;
        }
        i++;
    }

    cout << points << endl;
}