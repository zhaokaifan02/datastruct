#include <vector>
using namespace std;


// long long maximumHappinessSum(vector<int>& happiness, int k) {
//         //不能冒泡排，数量过大就崩了
//         /*
//         for(int i = 0;i<happiness.size();i++)
//         {
//             for(int j = i;j<happiness.size();j++)
//             {
//                 if(happiness[i]<happiness[j])
//                     swap(happiness[i],happiness[j]);
//             }
//         }
//         */
//         long long sum = 0;
//         for(int i = 0;i<k;i++)
//         {
//             sum += happiness[i]-i<=0?0:happiness[i]-i;//题目给出了不会为负数
//         }
//         return sum;
// }

//新的策略，冒泡本质上就是确定一个东西的位置最终位置。
//我们把排成从大到小的，每次冒泡完成后，检查他的位置，是否小于k
//小于k的话，说明这个数要选
//那么他具体是几呢。0的话真实值是 num - 0;因为第一个
// 10的话是num - 10;因为前面选出过10个了。所以真实值的映射也有了
//再注意happiness[i]-i<=0?0:happiness[i]-i 这个判断

long long maximumHappinessSum(vector<int>& happiness, int k) {
    //冒泡怎么优化都过不起，只能用快排
        long long sum = 0;
        for(int i = 0;i<happiness.size();i++)
        {
            for(int j = i+1;j<happiness.size();j++)
            {
                if(happiness[i]<=happiness[j])
                {
                    swap(happiness[i],happiness[j]);
    
                }
            }
            //step是真是位
            if(i<k)
            sum+=happiness[i]-i<0?0:happiness[i]-i;
        }
        return sum;
}

