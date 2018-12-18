#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int f[25],n;
int main()
{
    scanf("%d",&n);
    f[1]=0;f[2]=1;f[3]=2;
    if(n==1||n==2||n==3)
    {
        printf("%d",f[n]);
        return 0;
    }
    for(int i=4;i<=n;i++)
    {
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    }
    printf("%d",f[n]);
    system("PAUSE");
    return 0;
 } 