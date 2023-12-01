#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#define M 2010000
#define inf 0x3f3f3f3f
#define LL long long
#define int long long
using namespace std;
int n,s[M],cnt1[M],cnt2[M],ans;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
signed main(void)
{
    #ifndef ONLINE_JUDGE
        freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
    #endif
	n=read();
	for (int i=0;i<=30;i++) cnt2[i]=1;
	for (int i=1;i<=n;i++){
		int x=read();
		s[i]=s[i-1]^x;
		for (int j=30;j>=0;j--){
			if ((1<<j)&s[i])
				ans+=(1<<j)*cnt2[j],cnt1[j]++;
			else 
				ans+=(1<<j)*cnt1[j],cnt2[j]++;
		}
	}
	printf("%lld",ans);
    return 0;
}