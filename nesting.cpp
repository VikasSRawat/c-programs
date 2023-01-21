#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
    map<pair<int,int>,int> m;
    pair<int,int> p1 ,p2;
    p1={4,2};
    p2={2,3};
    cout<<(p1<p2)<<endl;

    set<int>s1={1,2,3};
    set<int>s2={1,2};
    cout<<(s2>s1)<<endl;

    m.insert({{11,2},0});
    m.insert({{13,2},2});
    m.insert({{5,2},1});

    map<pair<int,int>,int> :: iterator i;
    for(i=m.begin();i!=m.end();i++)
        cout<<(*i).first.first<<","<<(*i).first.second<<" "<<(*i).second<<endl;

    map<int,set<string>> result;
    for(int i=0;i<3;i++){
        int n;
        cin>>n;
        string name;
        cin>>name;
        set<string>str;
        str.insert(name);
        result.insert(n,str);
    }
    map<int,set<string>>::iterator it; 
    it=result.end();
    it--;
    for(;it!=result.begin(); i--)
        cout<<(*it).first<<endl;
    return 0;
}