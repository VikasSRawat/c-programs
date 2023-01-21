#include<iostream>
using namespace std;
void count_sort(int *arr,int n){
    int k=arr[0];
    for(int i=0;i<n;i++)
        if(k<arr[i])
            k=arr[i];
    int *count=(int *)malloc(sizeof(int)*(k+1));
    for(int i=0;i<=k;i++)
        count[i]=0;
    
    for(int i=0;i<n;i++)
        count[arr[i]]++;
    
    for(int i=1;i<=k;i++)
        count[i]=count[i]+count[i-1];
    
    int *b=(int *)malloc(sizeof(int)*n);

    for(int i=n-1;i>=0;i--)
    {
        count[arr[i]]--;
        b[count[arr[i]]]=arr[i];
    }

    for(int i=0;i<n;i++)
        arr[i]=b[i];

}
void print(int *arr,int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[]={3,1,4,6,2,5};
    int n=sizeof(arr)/sizeof(int);
    count_sort(arr,n);
    print(arr,n);
    return 0;
}