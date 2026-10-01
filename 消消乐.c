#include <stdio.h>
#include <string.h>
int main () {
	int top,m,n;
	scanf ("%d",&n);
	char ac[n][6];//保证字符串长度不超过5
	for (m=0;m<=n-1;m++) {
		scanf ("%s",ac[m]);
	} 
	char res[100][6];
	top=1;
	strcpy (res[0],ac[0]);//把ac数组值赋给res数组
	for (m=1;m<=n-1;m++) {
		if (strcmp(ac[m],res[top-1])==0) {//判断是否相等
			top-=1;
		}
		else {
			strcpy (res[top],ac[m]);
			top++;
		}
	}
	if (top==0) {
		printf ("c1ear!");
	}
	else {
		for(m=0;m<=top-1;m++) {
			printf ("%s \n",res[m]);
		}
	}
}