#include<iostream>
using namespace std;
//Merge will then will start merging the split arrays
void merge(int *arr,int low,int mid,int high){
    // int aux[high-low+1];
    int *aux=(int *)malloc((high-low+1)*sizeof(int));
    //This is done using an auxilary array and merging 2 sorted arrays techniques
    //the new merges array will be in the auxillary array
    int i=low,j=mid+1,k=0;
    while(i<=mid&&j<=high){
        if(arr[i]<arr[j]){
            aux[k]=arr[i];
            i++;
        }
        else{
            aux[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
        aux[k++]=arr[i++];
    while(j<=high)
        aux[k++]=arr[j++];
    i=low;
    //We will then store the auxillary elements into the array from the specified low to high
    for(int x=0;x<k;x++)
        arr[i++]=aux[x];
    free(aux);

}
void mergesort(int *arr,int low,int high){//mergesort keeps on breaking the array until all there are single elements

    if(low<high){//the base case will be when we have only have one element left i.e., it won't get split anymore
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    return;
}
void print(int *arr,int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[]={2,5,1,2,8,1,9,6,5,6,9};
    // int arr[]={2,1,8,5,3};
    int n=sizeof(arr)/sizeof(int);
    cout<<"Before sorting "<<endl;
    print(arr,n);
    mergesort(arr,0,n-1);
    cout<<"After sorting "<<endl;
    print(arr,n);
    return 0;
}  