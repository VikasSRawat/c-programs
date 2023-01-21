#include<iostream>
#include<unordered_set>
using namespace std;
void print(unordered_set<string> s){

    //using a for-each like construct without any iterator
    for(string str: s)
        cout<<str<<endl;

    cout<<endl;
    //using a normal for-loop without any iterator
    // set<string> ::iterator i;
    // for(i=s.begin();i!=s.end();i++)
    //     cout<<*i<<endl;
}
int main()
{
    unordered_set<string> st;
    //same thing as sets but prints in random order
    //time complexity for unordered_set operations is O(1)
    //internal implementations are implemented using hashmaps
    //cannot have complex datatypes for templates like : unordered_set<pair<int,int>> st;
    //Only basic datatypes are allowed
    st.insert("Vikas");
    st.insert("Singh");
    st.insert("God");
    st.insert("Rawat");
    print(st);

    for(int i=0;i<3;i++)
    {
        string str;
        cin>>str;
        if(st.find(str)!=st.end())
            cout<<"Present"<<endl;
        else
            cout<<"Not Present"<<endl;
    }
    return 0;
}