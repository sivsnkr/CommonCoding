#include <bits/stdc++.h>
using namespace std;

int main()
{
    Node * root = makeNode(1);
    int n;
    cin>>n;

    int i;
    for(i = 0; i < n; i++){
        int src,dest;
        cin>>src>>dest;
        Node * newNodesrc = findNode(root,src);
        if(newNodesrc->lnode)
            newNodesrc->rnode = makeNode(dest);
        else
            newNodesrc->lnode = makeNode(dest);
    }

    vector<int> e1(10),e2(10);

    if(root->lnode)
        e1[0]++;
    if(root->rnode)
        e2[0]++;

    level(root->lnode,1,e1);
    level(root->rnode,1,e2);

    int sum = 0;

    for(i = 0; i < e1.size(); i++){
        sum+=e1[i];
    }

    int sum1 = 0;

    for(i = 0; i < e2.size(); i++){
        sum1+=(e2[i]*(sum-e1[i]));
    }
    cout<<sum1<<endl;
}