#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define REPD(i,a,b) for(int i=a;i>=b;--i)
const int N = 100005;

struct node {
    string s;
    int n;
} p[N];

bool cmp(node x,node y) { return x.n > y.n; }

int main() {
    
	int tot=0;
    REP(i,1,N) {
        bool flag=1; 
        string t;
        cin >> t;
        if(t=="exit") break;
        if((t.size()!=11) || (t[0]!='1')) 
            {puts("������������������!"); continue;}
        REP(j,1,tot) if(p[j].s==t) 
            {p[j].n++ , flag=0 , printf("�ֻ��� %d �� %d ������!\n",j,p[j].n); break;}
        if(flag)  p[++tot].s = t , p[tot].n++ , printf("�ֻ��� %d �������!\n",tot);
    }
    sort(p+1,p+tot+1,cmp);
	puts("������ɣ���лʹ��!");
	freopen("user_input.txt","w",stdout);
    cout << tot << endl;
    REPD(i,tot,1) cout << p[i].n <<" "<< p[i].s << endl;
    system("PAUSE");
    return 0;
}
