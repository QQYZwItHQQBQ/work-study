#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=(1e5+5);
int N,cnt,ans; LL M,curt;
struct node{
	LL pos,cst;
}a[MAXN];
priority_queue<LL> Q;
bool cmp(node p,node q){
	return p.pos<q.pos;
}
int read1(){
	int x=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') 
		x=(x<<1)+(x<<3)+(ch&15),ch=getchar();
	return x;
}
LL read2(){
	LL x=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') 
		x=(x<<1)+(x<<3)+(ch&15),ch=getchar();
	return x;
}
int main(){
	N=read1(),M=read2();
	for (int i=1;i<=N;i++)
		a[i].pos=read2(),a[i].cst=read2();
	sort(a+1,a+N+1,cmp);
	for (int i=1;i<=N;i++){
		curt+=(a[i].pos-a[i-1].pos);
		curt+=a[i].cst;
		Q.push(a[i].cst),cnt++;
		if (curt<=M) ans=max(ans,cnt);
		else{
			while (curt>M&&!Q.empty()){
				LL x=Q.top(); Q.pop();
				curt-=x,cnt--;
			}
			ans=max(ans,cnt);
		}
	}
	printf("%d",ans);
	return 0;
}
