#include <iostream>
using namespace std;

int main()
{
    long int d;
    cin >> d;
    long int oc, of, od;
    cin >> oc >> of >> od;
    long int cs, cb, cm, cd;
    cin >> cs >> cb >> cm >> cd;

    long long int ot, ct;
    long int dist = d;
    ot = oc;
    if (d - of > 0)
        ot += (d - of) * od;
    ct = cb + (d / cs) * cm + d * cd;

    if (ot > ct)
    {
        cout << "Classic Taxi";
    }
    else
    {
        cout << "Online Taxi";
    }
    cout << endl;
    return 0;
}