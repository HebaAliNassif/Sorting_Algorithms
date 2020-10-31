#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& arr, int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void bubbleSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])swap(arr, j, j + 1);
		}
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

	bubbleSort(arr);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}