#include<iostream>
#include<set>
using namespace std;
void print(multiset<string> s)
{
    for(string str:s)
        cout<<str<<endl;
}
int main(){
    multiset<string> str;
    //multisets can be used instead of priority queues
    //they can store multiple values
    str.insert("abc");
    str.insert("abc");
    str.insert("def");

    print(str);

    auto i=str.find("abc");
    str.erase(i);//when passing iterator it will only delete the value at that iterator 
    //hence when deleting a value of which there are multiple present then it will find the address of the first value and delete only that
    
    cout<<endl;
    print(str);
    cout<<endl;
    str.insert("abc");
    print(str);

    str.erase("abc");//When passing string it will find all the values of that occuring string and delete all the occurences
    cout<<endl;
    print(str);
    //Question using multisets
    //to find the max number of candies a monk can eat in a limited time . If he takes about 1 min to eat a bag of candy and 
    //everytime he eats a bag of candy another candy bag will be added to which will be half the size of the candy bag he ate

     //ex : 2 1 7 4 2;
    int arr[]={2,1,7,4,2};
    int n=sizeof(arr)/sizeof(int);
    multiset<int> st;
    for(int i=0;i<n;i++)
        st.insert(arr[i]);
    int sum=0;
    for(int j=0;j<3;j++)
    {
        auto i=st.end();
        i--;
        int k=*i;
        cout<<k<<endl; 
        st.insert(k/2);
        sum+=k;
        st.erase(i);
    }
    cout<<sum<<endl;
    return 0;
}