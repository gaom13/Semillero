#include <bits/stdc++.h>

using namespace std;

vector<int>tab;

void PreCalcular(int n,int v[])
{
    tab.push_back(0);

    for(int i=1; i<=n; i++)
    {
        tab.push_back(tab[i-1]+v[i-1]);
    }

}

int main()
{
    int v[]= {1,3,5,2,1,3,2,1,2,4};
    int i,j;

    PreCalcular(10,v);

    for(int i=0; i<=10; i++)
    {
        cout<<tab[i]<<endl;
    }

    //swap(var1,var2);

    for(int i=0; i<=10; i++)
    {
       cin>>i>>j;
       cout<<tab[max(i,j)]-tab[min(i,j)-1]<<endl;
    }
    return 0;
}
