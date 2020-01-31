#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
const int MAXL=20;
const int MAXN=10;
LL L,R,pw[MAXL]; int x,y,l1,l2,r1,r2;
LL f[MAXL][MAXN],ans,ans1,ans2;
int main(){
	scanf("%lld%lld",&L,&R),pw[0]=1;
	x=floor(log10((DB)L))+1,y=floor(log10((DB)R))+1;
	for (int i=1;i<=18;i++) pw[i]=pw[i-1]*10LL;
	l1=floor((DB)L/(DB)pw[x-1]),r1=floor((DB)R/(DB)pw[y-1]);
	l2=L%10LL,r2=R%10LL;
	for (int i=1;i<=18;i++)
		for (int j=1;j<=9;j++)
			f[i][j]=pw[max(i-2,0)];
	if (l1<=l2){
		for (int i=min(l1,l2)+1;i<=9;i++) ans1+=f[x][i];
		ans1+=(pw[max(0,x-2)]-(L/10)%pw[max(0,x-2)]-1);
		if (l1==l2) ans1++;
	}
	else{
		for (int i=max(l1,l2)+1;i<=9;i++) ans1+=f[x][i];
		ans1+=(pw[max(0,x-2)]-(L/10)%pw[max(0,x-2)]);
	}
	if (r1>=r2){
		for (int i=1;i<=max(r1,r2)-1;i++) ans2+=f[y][i];
		ans2+=((R/10)%pw[max(y-2,0)]);
		if (r1==r2) ans2++;
	}
	else{
		for (int i=1;i<=min(r1,r2)-1;i++) ans2+=f[y][i];
		ans2+=((R/10)%pw[max(y-2,0)]+1);
	}
	for (int i=x+1;i<=y-1;i++)
		for (int j=1;j<=9;j++) ans+=f[i][j];
	ans+=(ans1+ans2);
	if (x==y){
		LL tmp=0;
		for (int i=1;i<=9;i++) tmp+=f[x][i];
		ans=ans1+ans2-tmp;
	}
	printf("%lld",ans);
	return 0;
}
/*愿你历遍山河，依然觉得人间值得。*/ 
