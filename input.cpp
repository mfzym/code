#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;++i)
const int N = 100005;

struct node {
    string s;
    int n;
    friend bool operator <(node a,node b)
		{return a.n<b.n;}
}p[N];
priority_queue <node> q;

int main() {
    
	int tot=0;
    REP(i,1,N) {
        bool flag=1; string t;
        cin >> t;
        if(t=="exit") break;
        if((t.size()!=11) || (t[0]!='1')) 
            {puts("������������������!"); continue;}
        REP(i,1,tot) if(p[i].s==t) 
			{p[i].n++; flag=0; printf("�ֻ��� %d �� %d ������!",i,p[i].n); break;}
        if(flag) p[++tot].s = t , p[tot].n++ , printf("�ֻ��� %d �������!",tot);
        
    }
    REP(i,1,tot) {
		node t;
		t.s=p[i].s , t.n=p[i].n;
		q.push(t);
	}
	puts("������ɣ���лʹ��!");
	freopen("user_input.txt","w",stdout);
    while(!q.empty()) {node t=q.top(); cout << t.s << endl; q.pop();}
    //system("PAUSE");
    return 0;
}
