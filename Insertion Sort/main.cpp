#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr)
{
	int n = arr.size();
	int key;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
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

	InsertionSort(arr);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}