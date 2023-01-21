#include<iostream>
using namespace std;

void heapify(int *arr,int n,int i){
    int largest=i;
    int l=2*i+1;//as indexes are starting from the 0 in the array
    int r=2*i+2;//hence for parent = 0 , l = 1 and r = 2

    if(l<n&&arr[largest]<arr[l])
        largest=l;
    if(r<n&&arr[largest]<arr[r])
        largest=r;
    
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(int *arr,int n){
    //building a heap
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}


void print(int *arr,int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[]={4,1,3,9,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    print(arr,n);
    return 0;
}