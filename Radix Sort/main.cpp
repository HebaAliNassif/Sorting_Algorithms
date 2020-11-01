#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int>& arr)
{
	int n = arr.size();
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void countingSort(vector<int>& arr, int k)
{
	vector<int>C(10, 0);
	int n = arr.size();
	vector<int>B(n);
	for (int i = 0; i < n; i++)
	{
		C[(arr[i] / k) % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		B[C[(arr[i] / k) % 10] - 1] = arr[i];
		C[(arr[i] / k) % 10]--;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = B[i];
	}
}
void radixSort(vector<int>&arr)
{
	int k = getMax(arr);
	for (int i = 1; k / i > 0; i *= 10)
	{
		countingSort(arr, i);
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
	radixSort(arr);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}