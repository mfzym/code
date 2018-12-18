#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
const int N = 100005;
int tot,tmp=N;

struct node {
    string s;
    int n;
} p[N];

void input() {
    freopen("user_input.txt","r",stdin);
    cin >> tot;
    REP(i,1,tot) 
        cin >> p[i].n >> p[i].s;
    fclose(stdin);

    freopen("observe.txt","r",stdin);
    int t; cin >> t;
    REP(i,1,t) {
        string s; bool flag=1;
        cin >> s;
        REP(j,1,tot) if(p[j].s==s)
            {p[j].n++; flag=0; break;}
        if(flag) p[++tot].s=s , p[tot].n++;
    } fclose(stdin);
}

int main() {
    input();
    int t = N;
    freopen("list.txt","w",stdout);
    REP(i,1,tot)  {
        if(p[i].n<2) {t=i;break;}
        cout << p[i].s << endl;
    } fclose(stdout);
    freopen("observe.txt","w",stdout);
    if(tot-t+1>0) cout << tot-t+1 << endl;
    REP(i,t,tot) cout << p[i].s << endl;
    return 0;
}