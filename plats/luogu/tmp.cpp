#include<iostream>
#include<cstring>
using namespace std;
int n;
char a[3000][3000];//开大点 
int h=3,w=5;//h是高,w是宽
int main(){
#ifndef ONLINE_JUDGE
	freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
	cin>>n;
	memset(a,' ',sizeof(a));//别被坑了!!! 
	a[1][3]=a[2][2]=a[2][4]=a[3][1]=a[3][3]=a[3][5]='*';
	for(int i=1;i<n;i++){
    	//向下和向右
		for(int j=1;j<=h;j++){
			for(int k=1;k<=w+1;k++){
				a[j+h][k]=a[j+h][k+w+1]=a[j][k];
				a[j][k]=' ';//把上面的清掉
			}
		}
        //向上
		for(int j=1;j<=h;j++){
			for(int k=1;k<=w+1;k++){
				a[j][k+w/2+1]=a[j+h][k];
			}
		}
		h*=2;w=2*h-1;
        //刷新完成一次
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	for(int k=1;k<=n;k++){
		for (int i = 1; i <= w / 2; i++) {
			cout << " ";
		}
		cout<<"*\n";
	}
	return 0;
}
