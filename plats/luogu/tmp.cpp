#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 1e5+50;
const int inf = 0x3f3f3f3f;
int n,k,x,t,i,j,sum,ans,sub;
int l,r;
struct Node{
    int id;
    int sum;
};

bool cmp(Node x,Node y){
    return x.sum<y.sum;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    while(scanf("%d%d",&n,&k)&&(k!=0||n!=0)){
        Node a[maxn];
        a[0].sum=0;a[0].id=0;
        for(int m=1;m<=n;m++){
            scanf("%d",&x);
            a[m].sum=a[m-1].sum+x;
            a[m].id=m;
        }
        sort(a,a+n+1,cmp);
        while(k--){
            scanf("%d",&t);
            i=0;
            j=1;
            sum=ans=0;
            sub=inf;
            l=r=0;
            while(j<=n){
                sum=a[j].sum-a[i].sum;//因为总是大减小，所以sum总是正的
                if(abs(sum-t)<sub){
                    l=min(a[i].id,a[j].id);
                    r=max(a[i].id,a[j].id);
                    sub=abs(sum-t);
                    ans=sum;
                }
                if(sum<t)j++;//如果和比t小了，就j右移
                else if(sum>t)i++;//反之左移
                else break;//sum==t就不需要往下找了
                if(i==j)j++;//如果i右移到和j相等
            }
            l++;//因为l取的是左端点的前一个点的id，所以要往右移一下
            printf("%d %d %d\n",ans,l,r);
        }
    }
}

