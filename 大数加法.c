#include <stdio.h>
#include <string.h>
#define SIZE 102

int main (void)
{
    int a,b;
    int carry = 0;
    int sum = 0;
    int k = 0;
    int res[SIZE+1] = {0};
    char num1[SIZE];
    char num2[SIZE];

    // 读同一行两个大数，支持带前导零输入
    scanf ("%s %s", num1, num2);
    int len1 = strlen(num1);
    int len2 = strlen(num2);
	//从最低位开始读取
    int i = len1 - 1;
    int j = len2 - 1;
    while (i>=0 || j>=0 || carry != 0)
    {
    	//保证位数不一样时依然可以正常竖式加法
        a = (i >= 0) ? (num1[i] - '0') : 0;
        b = (j >= 0) ? (num2[j] - '0') : 0;
        sum = a + b + carry;
        carry = sum / 10;
        //辅助数组进行存储
        res[k] = sum % 10;
        k++;
        i--;
        j--;
    }

    // 反向输出结果
    for (int p = k-1; p >= 0; p--)
    {
        printf("%d", res[p]);
    }
    printf("\n");
    return 0;
}
