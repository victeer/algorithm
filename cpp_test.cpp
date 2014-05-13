#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{

    map<int,int> amap;
    amap.insert(pair<int,int>(1,1));
    amap.insert(pair<int,int>(2,2));
    amap.insert(map<int, int>::value_type(7,1));
    map<int,int>::iterator it;
    for(it = amap.begin();it != amap.end();it++)//从前向后
    {
        cout<<"key:"<<it->first<<" value:"<<it->second<<endl;
    }
    map<int,int>::reverse_iterator iit;
    for(iit=amap.rbegin();iit!=amap.rend();iit++){
        cout<<"key:"<<iit->first<<" value:"<<iit->second<<endl;
    }
    it=amap.find(1);
    if(it != amap.end())
    {
        while(it != amap.end()){
           cout<<"Find, the value is "<<it->second<<endl;
           it++;
        }
    }else
    {
           cout<<"Do not Find"<<endl;
    }
    vector<int> t;
    t.push_back(1);
    t.push_back(1);
    t.push_back(1);
    t.push_back(1);
    t.push_back(1);
    cout<<"size:"<<t.size()<<endl;
    cout<<"cpacity:"<<t.capacity()<<endl;
    cout<<"empty:"<<t.empty()<<endl;
}
