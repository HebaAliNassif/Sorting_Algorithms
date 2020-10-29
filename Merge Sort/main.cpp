#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int>L(n1 + 1);
	vector<int>R(n2 + 1);

	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[p + i];
	}
	L[n1] = INT_MAX;
	for (int i = 0; i < n2; i++)
	{
		R[i] = arr[q + 1 + i];
	}
	R[n2] = INT_MAX;

	int j = 0;
	int k = 0;
	for (int i = p; i <= r; i++)
	{
		if (R[j] < L[k])
		{
			arr[i] = R[j];
			j++;
		}
		else
		{
			arr[i] = L[k];
			k++;
		}
	}
}
void mergeSort(vector<int>& arr, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
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

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}