#include <iostream>
using namespace std;

int n;
int *a;

void minMax(int i,int j,int &min,int &max)
{
    if(i==j)
        max=min=a[i];
    else if(i==j-1)
    {
        if(a[i]<a[j])
        {
            max=a[j];
            min=a[i];
        }
        else
        {
            max=a[i];
            min=a[j];            
        }
    }
    else
    {
        int mid=(i+j)/2;
        
        int min1,max1;
        minMax(i,mid,min,max);
        minMax(mid+1,j,min1,max1);
        
        if(max1>max)
            max=max1;
        if(min1<min)
            min=min1;
    }
}

int main() 
{
    cout<<"Enter the size: ";
    cin>>n;

    a=new int[n];     //Dynamically allocating the memory
    cout<<"Enter the Numbers: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int min,max;
    minMax(0,n-1,min,max);
    cout<<"Min: "<<min<<endl;
    cout<<"Max: "<<max;
    
    delete[] a;  //free the dynamically allocate momery
}


// OUTPUT:
// Enter the size: 8
// Enter the Numbers: 5 8 666 4 2 3 0 88
// Min: 0
// Max: 666
