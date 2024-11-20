 
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item
{
    int val;
    int wei;
};

double sack(int m,const vector<Item>& items)
{
    vector<pair<double,Item>> valPerWei;
    for(const auto& i:items)
    {
        valPerWei.push_back({(double)i.val/i.wei,i});
    }
   
    sort(valPerWei.begin(), valPerWei.end(), [](const pair<double, Item>& a, const pair<double, Item>& b)
    {
        return a.first > b.first;
    });
   
    double totalval=0.0;
   
    for(const auto& vpm: valPerWei)
    {
        const Item& item=vpm.second;
        if(m>=item.wei)
        {
            m-=item.wei;
            totalval+=item.val;
        }
        else
        {
            totalval+=item.val*((double)m/item.wei);
            break;
        }
    }
    return totalval;
}

int main()
{
    vector<Item>items={{60,10},{100,20},{120,30},{70,10}};
    int m=50;
   
    double maxVal=sack(m,items);
    cout<<"Maximum Profit: "<<maxVal;
}


// OUTPUT:
// Maximum Profit: 270
