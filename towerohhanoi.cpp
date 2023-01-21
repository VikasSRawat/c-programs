#include<iostream>
using namespace std;
void toh(int n,char sou,char aux,char des){
    if(n==1)//End case when we move disc from source to destination without any auxilary as there is only 1 disc left
        cout<<"Moving "<<n<<" from "<<sou<<" to "<<des<<endl;
    else{
        toh(n-1,sou,des,aux);//transfering n-1 discs from sou to aux using des as a helper
        cout<<"Moving "<<n<<" from "<<sou<<" to "<<des<<endl;//printing the steps to move bottom disc to its destination
        toh(n-1,aux,sou,des);//transfering n-1 discs from aux to sou using des as a helper
        //The goal is to put the largest disc onto the destination as anything else can be put ontop of the largest disc
    }
}
int main()
{
    int n;
    cout<<"Enter the number of disks : ";
    cin>>n;
    toh(n,'A','B','C');
    return 0;
}