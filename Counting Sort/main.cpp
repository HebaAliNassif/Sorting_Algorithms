#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr, int k)
{
	vector<int>C(k, 0);
	int n = arr.size();
	vector<int>B(n);
	for (int i = 0; i < n; i++)
	{
		C[arr[i]]++;
	}
	for (int i = 1; i < k; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		B[C[arr[i]]-1] = arr[i];
		C[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = B[i];
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
	int k;
	cin >> k;
	countingSort(arr, k);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}