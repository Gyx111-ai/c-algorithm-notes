#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main () {
	int n,x;
	scanf ("%d %d",&n,&x);
	int lose[1001]; 
	int win[1001];
	int need[1001];
	int a,j;
	for (a=0;a<n;a++) {
		scanf ("%d %d %d",&lose[a],&win[a],&need[a]);
	}
	int dp[1001];//额外数组来储存递推结果
	for (j=0;j<=x;j++) {
		dp[j]=0;
	}//初始化dp数组
	for (a=0;a<n;a++) {
		for (j=x;j>=need[a];j--) {
			*(dp+j)=max(*(dp+j),*(dp+j)-need[a]+win[a]-lose[a]);//取每一次递推的最大值
		}
	}
	int sum=0;
	for (a=0;a<n;a++) {
		sum+=lose[a];
	}
	sum = sum+*(dp+x);
	printf ("%d",5*sum);//5倍经验
}