#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

const int N = 5e6+10;
int a[N];

int qsort(int left,int right,int k){

    int mid = a[left+(right-left)/2];
    int i=left,j=right-1;

    while(i<=j){
        while(a[i]<mid)++i;
        while(a[j]>mid)--j;
        if(i<=j){
            swap(a[i],a[j]);
            ++i,--j;
        }
    }
    if(left<=j&&k<=j) return qsort(left,j+1,k);
    if(i<right && k>=i) return qsort(i,right,k);
    return a[k];
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    int n=read(),k=read();
    for(int i=0;i<n;i++) a[i]=read();
    // int k = n>>1;
    printf("%d\n",qsort(0,n,k));
    return 0;
}