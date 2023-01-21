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

int partition(int *arr,int low,int high){
	int pivot=arr[high];
	int i=-1,j=0;
	for(j=0;j<high;j++){
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);//Will swap the smaller value which is later in the array and swap it with the bigger value
		}
	}
	swap(&arr[i+1],&arr[high]);//Then it will swap the pivot to its rightfull posiiton
	return i+1;//Will return the new position
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