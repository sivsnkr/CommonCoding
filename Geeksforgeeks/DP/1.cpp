#include<bits/stdc++.h>
using namespace std;

int getres(int arr[],int n)
{
	int dp[n];
	dp[0] = arr[0];
	
	int i;
	for(i = 1; i < n; i++)
	{
		int mxm = 0;
		int first = i-1;
		int second = 0;
		while(first >= second)
		{
			mxm = max(mxm,dp[first]+dp[second]);
			first--;
			second++;
		}
		dp[i] = max(mxm,arr[i]);
	}
	return dp[n-1];
}

int main()
{
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int size  = sizeof(arr)/sizeof(arr[0]);
	int res = getres(arr,size);
	cout<<res<<endl;
}