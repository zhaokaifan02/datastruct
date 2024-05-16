#include <stdlib.h>
#include <stdio.h>
int ptoc(int n,int k)
{
    //n中出k个
    int i,j,m=10;
    int **tp;
    if(n<0||n>=m)
        exit(-1);
    tp = (int**)malloc(sizeof(int*)*m); //开辟一个m大小的int*数组
    if(tp==NULL)
        exit(-1); //内存开辟失败
    for(int i = 0;i<m;i++)
    {
        tp[i] = (int*)malloc(sizeof(int)*m);
        if(tp[i]==NULL)
            exit(-1);
        for(int j = 0;j<m;j++)
        {

        }
    }
    
}

int main()
{
    for(int i = 0;i<15;i++)
    {
        printf("%d: \n",i);
        if(i<0&i>=10)
            printf("1\n");
        else printf("0\n");
    }
    return 0;
}