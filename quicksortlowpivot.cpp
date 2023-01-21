#include<iostream>
using namespace std;
void swap(int *x,int *y){
	int t=*x;
	*x=*y;
	*y=t;
}

void print(int *arr,int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
//This is more efficient than the quicksort where pivot is at the end of the array
int partition(int *arr,int low,int high){
	int pivot=arr[low];
	int i=low;
	int j=high;
	while(i<j){
		//keep on incrementing the value of i until a point comes where pivot is smaller than a[i]
		//this is done so that we find larger value as compared to pivot to place on the right side
		while(pivot>=arr[i]&&i<=high-1)
			i++;

		//keep on decrementing the value of j until a point comes where pivot is bigger than a[j]
		//this is done so that we find the smaller value as compared to pivot to place on the left side
		while(pivot<=arr[j]&&j>low)
			j--;

		if(i<j)
			swap(&arr[i],&arr[j]);//now we are just swapping the value which is on a[i] and a[j]
			//a[i] will be with the bigger numbers and a[j] with the smaller numbers
		}
		//this is done until i < j as when j reaches a point behind i ,it will find that all the numbers are smaller or equal to pivot
		//or if it reaches the point that i>j , then all the numbers beyond j will be bigger than the pivot leading to it swapping all the numbers again

	swap(&arr[low],&arr[j]);//than we swap the pivot(i.e., a[low]) and a[j] so that the pivot is placed correctly in its positon i.e., all the numbers  on the right side are bigger than the pivot and all the numbers on the left side are smaller than the pivot

	//it then returns the new pivot's new position i.e., j (after swapping a[low] and a[j])	so that partition will happen to the subarrays after and before the pivot
	return j;
}
void quicksort(int *arr,int low,int high){
	if(low<high){
		int pivot=partition(arr,low,high);
		// int n=sizeof(arr)/sizeof(int);
		// print(arr,n);//checking the array after every pivot exchange
		quicksort(arr,low,pivot-1);
		quicksort(arr,pivot+1,high);
	}
	return;
}

int main()
{
	int arr[]={5,2,3,1,4,6,9};
	int n=sizeof(arr)/sizeof(int);
	cout<<"Before sorting the array"<<endl;
	print(arr,n);
	quicksort(arr,0,n-1);
	cout<<"After sorting the array"<<endl;
	print(arr,n);
	return 0;
}