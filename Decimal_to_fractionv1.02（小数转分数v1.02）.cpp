#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    
    double a=0,b=0.000001,c=10000,i=1;
    //b是精度，c是分母最大值
    cout << "输入大于0的小数，程序会转化成分数" << endl;
    cout << "当前精度为:" <<b<< endl;
    cout << "当前分母最大值为:" <<c<<endl;
    cout << "若想修改参数，请以文本模式打开此文件" << endl;
    cout << "在这里输入小数: ";
    cin >> a;
    cout << "结果为: ";
    for(i=1;i<=c;i++)
    {
    if((1-(a*i-(int)(a*i)))<b)
    {
    cout << (int)(a*i)+1 <<"/"<<i<< endl;
    cout << "误差为: " <<(((int)(a*i)+1)/i-a)/a*100<<"%"<< endl;
    break;
    }
    if((a*i)==(int)(a*i))
    {
    cout << (int)(a*i) <<"/"<<i<< endl;
    cout << "此解为精确解" << endl;
    break;
    }
    }
    if(i==c+1)
    {
    cout << "无"<<endl<<"提示: 目前最大分母设置过小" << endl;
    }
    return 0;
}
