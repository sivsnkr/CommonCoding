#include <bits/stdc++.h>
using namespace std;

int getres(int arr1[], int arr2[], int n, int i, int size)
{
	if (i == size - 1)
		return n;
	int res1 = getres(arr1, arr2, n + arr1[i + 1], i + 1, size);
	int res2 = getres(arr1, arr2, n + arr2[i + 1], i + 1, size);
	return min(res1, res2);
}

int main()
{
	int firstassembly[] = {4, 5, 3, 2};
	int secondassembly[] = {2, 10, 1, 4};

	// entry point first assembly

	int res1 = getres(firstassembly, secondassembly, 10 + firstassembly[0], 0, 4);
	int res2 = getres(secondassembly, firstassembly, 12 + secondassembly[0], 0, 4);

	cout << min(res1, res2) << endl;
}