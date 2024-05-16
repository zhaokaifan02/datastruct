#include <stdio.h>
int count1(unsigned int v)
{
    //通过除法求MSB
    //权值复位法
    int count = 0;
    if(v>0&&v<256)
    {
        while(v>0)
        {
            count += v%2;
            v = v/2;
        }
        return count;
    }
    return -1;
}

int count2(unsigned int v)
{
    //移位运算
    int count = 0;
    if(v>0&&v<256)
    {
        for(int i = 0;i<7;i++)
        {
            count+=((v>>i)&0x01);
        }
        return count;
    }
    return -1;
}
int count3 (unsigned int v)
{
    unsigned int v1 = (v&0x55) + ((v>>1)&0x55);
    unsigned int v2 = (v1&0x33)+((v1>>2)&0x33);
    unsigned int v3 = (v2&0x0f)+((v2>>4)&0x0f);
    return v3;
}
void fill(unsigned int v, unsigned int* out)
{
    unsigned int v1 = v|(v>>1);
    unsigned int v2 =v1 |(v>>2);
    unsigned int v3 = v2|(v>>4);
    *out = v3;
}
int main()
{
    // unsigned int a = 85;
    // printf("%d ", count1(a));
    // printf("%d ", count2(a));
    unsigned int v,filled = 0;
    scanf("%d",&v);
    fill(v,&filled);
    printf("MSB:%d ", count2(filled)); //8个1最高位就是8
}