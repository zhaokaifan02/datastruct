#include <stdio.h>
void BC1()
{
    printf("Practice makes perfect!");
}
void BC2()
{
    printf("v   v\n");
    printf(" v v \n");
    printf("  v  \n");
}
void BC3()
{
    printf("The size of short is %d bytes.\n", sizeof(short)); //2
    printf("The size of int is %d bytes.\n", sizeof(int)); //4
    printf("The size of long is %d bytes.\n", sizeof(long)); //4 //32位系统
    printf("The size of long long is %d bytes.\n", sizeof(long long)); //8
}
void BC6()
{
    printf("     **     \n");
    printf("     **     \n");
    printf("************\n");
    printf("************\n");
    printf("    *  *    \n");
    printf("    *  *    \n");
}
void BC7()
{
    printf("0%O 0x%X",1234,1234);
    //%o  8进制 因为8进制不存在字母，所以没有大小O，但是GCC不看这个
    //%x %X 16进制 体现的是FFF还是fff
}
void BC8()
{
    printf("%15d",0XABCDEF);
    //%md m表示输出的宽度
}
void BC9()
{
    int a = printf("Hello World!\n");
    printf("%d\n", a); //printf输出的是 12+1, 1表示占位符\n大小
}

void BC10()
{
    int a,b,c;
    scanf("%d %d %d\n",&a,&b,&c);
    printf("score1=%d,score2=%d,score3=%d\n",a,b,c);
}
void BC11()
{
    int a;
    double b,c,d;
    scanf("%d;%f,%f,%f\n",&a,&b,&c,&d);
    a = (double)(int)(a*100+0.5)/100; //先乘100再四舍五入，最后再除100
    b = (double)(int)(b*100+0.5)/100;
    c = (double)(int)(c*100+0.5)/100;
    printf("The each subject score of No. %d is %.2f, %.2f, %.2f.\n", a,b,c,d);
}
void BC12()
{
    char a;
    scanf("%c\n",&a);
    printf("    %c\n",a);
    printf("   %c %c\n",a,a);
    printf("  %c %c %c\n",a,a,a);
    printf(" %c %c %c %c\n",a,a,a,a);
    printf("%c %c %c %c %c\n",a,a,a,a,a);
}
void BC13()
{
    //输出ASCII码
    char a;
    scanf("%c\n",&a);
    printf("%d\n",a); //计算机内部就是ascii码，所以直接输出就行
}
void BC14()
{
    printf("%d\n",(-8+22)*40-10+212/2);
}
void BC15()
{
    int a,b;
    scanf("%d %d\n",&a,&b);
    printf("%d %d\n",a/b,a%b); //商和余数
}
void BC19()
{
    //反向输出
    int a;
    scanf("%d\n",&a);
    while(a!=0)
    {
        printf("%d",a%10);
        a/=10;
    }
}
void BC20()
{
    int a,b;
    scanf("%d %d\n",&a,&b);
    printf("%d\n", (a%100+b%100)%100);
}
void BC21()
{
    double a;
    scanf("%lf\n",&a);
    printf("%d\n",(int)a%10);
    //优先级 int 提升大于%运算，%模运算只能用作整形
}
void BC22()
{
    int a;
    scanf("%d\n",&a);
    printf("%lld\n",(long long)a*31560000);
}
void BC23()
{
    int a;
    scanf("%d\n",&a);
    int hour = a/3600;
    int minute = (a - hour*3600)/60;
    int second = a - hour*3600-minute*60;
    printf("%d %d %d\n",hour,minute,second);
}
void BC24()
{
    double a,b,c;
    scanf("%lf %lf %lf\n",&a,&b,&c);
    printf("%.2lf %.2lf\n",a+b+c,(a+b+c)/3);
}
void BC25()
{
    int wight,height;
    scanf("%d %d\n",&wight,&height);
    printf("%.2f\n", wight/(((double)height*(double)height/10000)));
}
void BC26()
{
    
}
int main()
{
    BC9();
}