#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<int ,string> m;
    m[2]= "vikas";
    m[1]="lsjadf";
    m[12]="kjasdh";
    m.insert({0,";laskdjf"});

    //or we can insert inside the map using pair

    m.insert(pair<int, string>(21,"John"));

    map<int,string> :: iterator i;
    for(i=m.begin();i!=m.end();i++)
        cout<<(*i).first<<" "<<(*i).second<<endl;
    auto it=m.find(0);//.find will return a pointer pointing to the index 
    //if index is out of bounds then it will return a random garbage value as its pointing to the end address(which is +1 from the last index)
    cout<<(*it).first<<" "<<(*it).second<<endl;

    it=m.find(123);
    if(it==m.end())
        cout<<"Garbage value"<<endl;
    else
        cout<<(*it).first<<" "<<(*it).second<<endl;

    m.insert({2,"singh"});
    for(i=m.begin();i!=m.end();i++)
        cout<<(*i).first<<" "<<(*i).second<<endl;
   
    return 0;
}