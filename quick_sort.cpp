#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e9;
 
int partition(int *a, int start, int end){
    
    int pivot_element = a[start], count=0, temp;
    for(int i=start+1;i<=end;i++)
        if(a[i]<pivot_element) count++;
    
    int pivot_index = start + count;
    
    a[start] = a[pivot_index], a[pivot_index] = pivot_element;
    
    int i = start, j=end;
    
    while(i<=pivot_index and j > pivot_index){
        if(a[i] <= pivot_element) i++;
        else if(a[j] > pivot_element) j--;
        else temp = a[i], a[i]=a[j], a[j] = temp, i++, j--;
    }
    
    return pivot_index;
}
 

void quickSort(int *a, int start, int end)
{
	if(start >= end) return;
	int pivot_index= partition(a, start, end);
	quickSort(a, start, pivot_index-1);
	quickSort(a, pivot_index+1, end);
}
 
int main()
{
	int n, arr[mxN];
	cin>>n;
	for(int i = 0; i < n; i++) cin>>arr[i];
	quickSort(arr, 0, n-1);
	for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
}
