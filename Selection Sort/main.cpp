#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int>& arr, int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}
void selectionSort(vector<int>& arr)
{
	int n = arr.size();
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i; j < n; j++)
		{
			if (arr[min] > arr[j])min = j;
		}
		swap(arr, min, i);
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

	selectionSort(arr);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}