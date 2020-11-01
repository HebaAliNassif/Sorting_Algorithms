#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void bucketSort(vector<float>& arr)
{
	int n = arr.size();
	vector<vector<float>>buckets(n);
	for (int i = 0; i < n; i++)
	{
		buckets[arr[i] * n].push_back(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		sort(buckets[i].begin(), buckets[i].end());
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < buckets[i].size(); j++)
		{
			arr[k] = buckets[i][j];
			k++;
		}
	}
}
int main()
{
	int n = 0;
	cin >> n;
	vector<float> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	bucketSort(arr);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}