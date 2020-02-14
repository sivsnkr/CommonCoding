#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> weights(n);
    vector<pair<int, int>> vertices(n);

    int i;
    for (i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        vertices.at(a).second++;
        vertices.at(a).first = a;
        vertices.at(b).second++;
        vertices.at(b).first = b;
    }

    for (i = 0; i < n; i++)
    {
        cin >> weights.at(i);
    }

    sort(weights.begin(), weights.end(), [](int a, int b) -> bool {
        return a > b;
    });

    sort(vertices.begin(), vertices.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second > b.second;
    });

    i = 0;
    for (pair<int, int> &a : vertices)
    {
        a.second = weights.at(i);
        i++;
    }

    sort(vertices.begin(), vertices.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.first < b.first;
    });

    for (i = 0; i < n; i++)
    {
        cout << vertices[i].second << " ";
    }
    cout << endl;
}
