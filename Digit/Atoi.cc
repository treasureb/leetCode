#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

/*
 * 实现一个atoi
 * 1.先去除字符串前面的空格
 * 2.然后判断第一个字符是否在'-'号,然后进行标记
 * 3.忽略除0-9之外的字符
 * 4.对于超过最大值/最小值的结果，返回临界值
 *
 */
int My_atoi(string str)
{
     int length = str.size();
        long long ret_64 = 0;
        int op = 1;
        int p = 0;
        //先去除掉前面多余的空格
        while (str[p] == ' ') 
            ++p;
        //标记正负号
        if (str[p] == '+' || str[p] == '-') 
        {
            if (str[p] == '-') op = -1;
            p++;
        }

        for (int i = p; i < length; ++i)
        {
            if ('0' <= str[i] && str[i] <= '9') 
            {
                ret_64 = ret_64 * 10 + (str[i] - '0');
                //超过最大值/最小值，则返回最大值/最小值
                if ((op == -1 && ret_64 > 2147483648LL)) 
                    return -2147483648;
                if ((op == 1 && ret_64 > 2147483647LL)) 
                    return 2147483647;
            }   
            else 
                break;
        }
        return (int)ret_64 * op;
}

int main()
{
    string s = "1314";
    int ret = My_atoi(s);
    cout<<ret<<endl;
    return 0;
}
