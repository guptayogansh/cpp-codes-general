#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e9;
 
void Merge(int *a, int start, int end, int mid)
{
	int i, j, k, temp[mxN];
	i = start;
	j = mid + 1;
	k = 0;
	
	while (i <= mid and j <= end)
	{
		if (a[i] < a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}
 
	while (i <= mid) temp[k++] = a[i++];
	while (j <= end) temp[k++] = a[j++];
 
	for (i = start; i <= end; i++) a[i] = temp[i-start];
}
 

void MergeSort(int *a, int start, int end)
{
	if(start >= end) return;
	int mid=(start+end)/2;
	MergeSort(a, start, mid);
	MergeSort(a, mid+1, end);
	Merge(a, start, end, mid);
}
 
int main()
{
	int n, arr[mxN];
	cin>>n;
	for(int i = 0; i < n; i++) cin>>arr[i];
	MergeSort(arr, 0, n-1);
	for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
}
