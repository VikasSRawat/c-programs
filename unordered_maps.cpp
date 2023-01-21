#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    //just like maps but stores values randomly
    //time complexity is nearly O(1)
    //internal implementations are done using hashmaps
    unordered_map<int,string> m1;
    m1.insert({1,"Vikas"});
    m1.insert({2,"Singh"});
    m1.insert({3,"Rawat"});
    unordered_map<int,string> :: iterator i;
    for(i=m1.begin();i!=m1.end();i++)
        cout<<(*i).first<<" "<<(*i).second<<endl;
    
    unordered_map <string,int> m2;
    for(int j=0;j<3;j++)
    {
        string s;
        cin>>s;
        m2[s]++;
    }
    unordered_map<string,int>:: iterator k;
    for(k=m2.begin();k!=m2.end();k++)
        cout<<(*k).first<<" "<<(*k).second<<endl;
    
    return 0;
}