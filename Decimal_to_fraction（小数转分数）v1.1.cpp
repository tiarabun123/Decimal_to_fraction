#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;


double round(double x)
{
    return (x > 0.0) ? (floor(x + 0.5)) : (ceil(x - 0.5));
}


int main()
{
    

    double a = 0, b = 0.00001, c = 1e+308, d = 1, e=0,f=1e-307,i = 1,j=0.1;
    //a是要转化的小数
    //b是绝对误差最大值
    //c是最大分母
    //d是用于处理负值小数的
    //e是用于切换自动和手动模式的
    //f是自动模式最大精度
    //i是循环计算过程中当前分母
    //j是自动模式循环计算过程中当前精度


    //程序前言开始
    cout << "输入小数程序会转化成分数" << endl << endl;
    cout << "精度模式介绍：" << endl;
    cout << "自动模式只需输入小数，无需输入精度（绝对误差最大值），程序会自动从精度0.1开始计算，再计算0.01，0.001等等，直到算出精确解为止，最后只需从结果中挑选自己想要的即可,但是如果小数的原分数过于奇怪，可能精度设置成0.1，0.01或0.001等并不能求出原分数，这时可以通过手动模式寻找答案。" << endl;
    cout << "手动模式需要自行输入精度，不推荐新手使用。" << endl;
    cout << "请选择精度模式（0：自动    1：手动）：";
    cin >> e;
    //程序前言结束


    if(e==1)//手动模式开始
    {
        
        cout << endl<<"在这里输入精度（绝对误差最大值）：";
        cin >> b;
    cout << endl << "在这里输入小数：";
    cin >> a;
    if (a < 0)
    {
        a = -a;
        d = -d;
    }
    cout << endl << "结果为：";
    for (i = 1; i <= c; i++)
    {
        if (abs((round(a * i)) / i - a) < b)
        {
            if (d < 0) cout << -round(a * i) << "/" << i <<"    ";
            else cout << round(a * i) << "/" << i << "    ";
            cout << "绝对误差：" << (abs((round(a * i)) / i - a)) << "    相对误差：" << (abs((round(a * i)) / i - a)) / a * 100 << "%" << endl;
            break;
        }
    }
    
    }//手动模式结束


    else if (e == 0)//自动模式开始
    {
        
        cout << endl << "在这里输入小数：";
        cin >> a;
        if (a < 0)
        {
            a = -a;
            d = -d;
        }
        cout << endl << "结果如下：" << endl << endl;
        cout << std::left << setw(23) << "精度" << std::left << setw(16) << "结果" << std::left << setw(16) << "  绝对误差" << "  相对误差" << endl;
        for (j = 0.1; j > f; j = j / 10,b=j)
        {
            cout  << std::left << setw(8)<< j;
            for (i = 1; i <= c; i++)
            {
                if (abs((round(a * i)) / i - a) < b)
                {
                    if (d < 0) cout << std::right << setw(16) <<-round(a * i) << "/" << std::left << setw(16) << i ;
                    else cout  << std::right << setw(16) << round(a * i) << "/" << std::left << setw(16) << i ;
                    cout <<  std::left << setw(16) << (abs((round(a * i)) / i - a))  << (abs((round(a * i)) / i - a)) / a * 100 << "%" << endl;
                    if ((abs((round(a * i)) / i - a)) == 0) goto endend;
                    break;
                }
            }
        }
    endend:;
    }//自动模式结束


    return 0;
}