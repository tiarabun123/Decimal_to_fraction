#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    
    double a=0,b=0.001,c=10000;
    //b是精度，c是分母最大值
    cout << "输入大于0小于1的小数转化成分数" << endl;
    cin >> a;
    cout << "结果显示:" << endl;
    for(double i=1;i<c;i++)
    {
    if((1-(a*i-(int)(a*i)))<b)
    {
    cout << (int)(a*i)+1 <<"/"<<i<< endl;
    break;
    }
    if((a*i)==(int)(a*i))
    {
    cout << (int)(a*i) <<"/"<<i<< endl;
    break;
    }
    }
    
    return 0;
}
