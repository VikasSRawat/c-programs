#include<iostream>
#include<set>
using namespace std;

void print(set<string> s){

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
    //sets is also like maps but without any values i.e.,
    //sets do not take any duplicate values
    set<string> s;
    //insert time complexity = O(log n)
    s.insert("vikas");
    s.insert("abc");
    s.insert(";jkas");
    s.insert("kdjf");

    //time complexity of .find() is O(log n)
    auto i=s.find("vikas");
    cout<<*i<<endl;
    i=s.find("kljhasd");
    if(i!=s.end())
        cout<<"Value is in bounds of the set"<<endl;
    else
        cout<<"Value is not in bounds of the set"<<endl;
    //using functions to print sets
    print(s);

    i=s.find(";jkas");
    s.erase(i);
    print(s);
    //or
    s.erase("vikas");
    print(s);


    
    return 0;
}