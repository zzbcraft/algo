#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 递归 正向思路解法
int climb(int n)
{
    // 必须满足大于0的条件
    assert(n > 0);
    if(n == 1) return 1;
    if(n == 2) return 2;

    return climb(n-1) + climb(n-2);
}

// 递归 逆向思路解法
int climb2(int n)
{
    assert(n > 0);
    if(n == 1) return 1;
    if(n == 2) return 2;

    int arrSum[n];
    arrSum[1] = 1;
    arrSum[2] = 2;
    
    for(int i=3; i<=n; i++)
    {
        arrSum[i] = arrSum[i-1] + arrSum[i-2];
    }

    return arrSum[n];
}

// 递归 逆向节省内存思路解法
int climb3(int n)
{
    assert(n > 0);
    if(n == 1) return 1;
    if(n == 2) return 2;

    int sum1 = 1;
    int sum2 = 2;
    int sum = 0;
    for(int i=3; i<=n; i++)
    {
        sum = sum1 + sum2;
        sum1 = sum2;
        sum2 = sum;
    }

    return sum;
}

int main(void)
{
    int num;
    puts("请输入台阶数：");
    scanf("%d",&num);

    // int rs = climb(num);
    // int rs = climb2(num);
    int rs = climb3(num);

    printf("%d\n", rs);
}
