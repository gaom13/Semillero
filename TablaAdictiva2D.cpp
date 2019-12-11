#include <bits/stdc++.h>
using namespace std;
int tab[6][6];
int m[5][5]= {{1,3,2,1,4},{3,2,1,0,1},{3,2,1,0,1},{3,2,2,1,1},{1,2,3,4,5}};
void PreCalcular(int n,int v[5][5])
{
    memset(tab, 0, sizeof(tab));
    tab[1][1]=m[0][0];
    for (int i = 2; i <= 5; i++)
        tab[i][1] = tab[i-1][1] + m[i - 1][0];
    for (int j = 2; j <= 5; j++)
        tab[1][j] = tab[1][j-1] + m[0][j - 1];

    for (int i = 2; i <= 5; i++)
        for (int j = 2; j <= 5; j++)
            tab[i][j] = tab[i][j - 1] + tab[i - 1][j] +
                        m[i - 1][j - 1] - tab[i - 1][j - 1];

}
int query(int f1, int c1, int f2, int c2)
{
    return tab[f2][c2] - tab[f1-1][c2] -
           tab[f2][c1-1] + tab[f1-1][c1-1];
}
int main()
{


    PreCalcular(5,m);

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<m[i][j]<<" ";

        }
        cout<<endl;
    }

    cout << query(2, 2, 4, 4) << endl;



    return 0;
}
