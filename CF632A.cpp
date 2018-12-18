#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define REPD(i,a,b) for(int i=a;i>=b;--i)
const int N = 100005;
int n,p,a[N],t=0;
double sum=0;
string s;
int main() {
    cin >> n >> p;
    REP(i,1,n) {
        cin >> s;
        if(s=="half") a[i]=0;
        else a[i]=1 , t++;
    }
    REPD(i,n,1) {
        if(a[i]) sum=(sum+0.5)*2;
        else sum*=2;
    }
    cout << (sum-0.5*t)*p << endl;
    //这代码无法AC
    system("PAUSE");
    return 0;
}
