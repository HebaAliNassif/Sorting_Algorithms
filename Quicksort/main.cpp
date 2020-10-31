#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int l, int r)
{
	int pivot = arr[r];
	int pindex = l - 1;
	int i = l;
	while (i < r)
	{
		if (arr[i] < pivot)
		{
			pindex++;
			int temp = arr[i];
			arr[i] = arr[pindex];
			arr[pindex] = temp;
		}
		i++;
	}
	int temp = arr[r];
	arr[r] = arr[pindex+1];
	arr[pindex+1] = temp;
	return pindex+1;
}

void quicksort(vector<int>& arr, int l, int r)
{
	if (l < r)
	{
		int p = partition(arr, l, r);
		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
}
int main()
{
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	quicksort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}