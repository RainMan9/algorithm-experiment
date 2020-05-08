#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* a, int* b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

//递归法
void quick_sort_recursive(int arr[], int start, int end) {
	if (start >= end)
		return;
	int mid = arr[end];
	int left = start, right = end - 1;

	while (left < right) {
		while (arr[left] < mid && left < right)
			left++;
		while (arr[right] >= mid && left < right)
			right--;
		swap(&arr[left], &arr[right]);
	}
	if (arr[left] >= arr[end])
		swap(&arr[left], &arr[end]);
	else
		left++;
    if (left) {
        quick_sort_recursive(arr, start, left - 1);
    }
    quick_sort_recursive(arr, left + 1, end);
}

void Qsort(int arr[], int len) {
	quick_sort_recursive(arr, 0, len - 1);
}

void print(int* arr, int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	srand(time(NULL));
	int arr[]={2,5,1,3,4,9,8,6,7,0,11};
	Qsort(arr,sizeof(arr)/sizeof(int));
	print(arr,sizeof(arr)/sizeof(int));
	return 0;
}
