#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;


double round(double x)//四舍五入程序开始[Start of rounding procedure]
{
    return (x > 0.0) ? (floor(x + 0.5)) : (ceil(x - 0.5));
}//四舍五入程序结束[End of rounding procedure]


int main()
{


    double a = 0, b = 0.00001, c = 1e+308, d = 1, e = 0, f = 1e-307, i = 1, j = 0.1;
    //a是要转化的小数[a is the decimal to be converted]
    //b是绝对误差最大值[b is the maximum absolute error value]
    //c是最大分母[c is the maximum denominator]
    //d是用于处理负值小数的[d is used to handle negative decimals]
    //e是用于切换自动和手动模式的[e is used to switch between automatic and manual modes]
    //f是自动模式最大精度[f is the maximum accuracy of automatic mode]
    //i是循环计算过程中当前分母[i is the current denominator in the loop calculation process]
    //j是自动模式循环计算过程中当前精度[j is the current accuracy during the automatic mode loop calculation process]


    //程序前言开始[Program Preface Start]
    cout << "输入小数程序会转化成分数\n[Entering a decimal program will convert it to a fraction]" << endl << endl;
    cout << "精度模式介绍：\n[Introduction to precision mode:]\n" << endl;
    cout << "自动模式只需输入小数，无需输入精度（绝对误差最大值），程序会自动从精度0.1开始计算，再计算0.01，0.001等等，直到算出精确解为止，最后只需从结果中挑选自己想要的即可,但是如果小数的原分数过于奇怪，可能精度设置成0.1，0.01或0.001等并不能求出原分数，这时可以通过手动模式寻找答案。\n[In automatic mode, you only need to input decimals without the need for precision (maximum absolute error). The program will automatically start calculating with an accuracy of 0.1, then calculate 0.01, 0.001, and so on until an accurate solution is obtained. Finally, you only need to choose what you want from the results. However, if the original fraction of decimals is too strange, setting the precision to 0.1, 0.01, or 0.001 may not be able to calculate the original fraction. In this case, you can find the answer through manual mode.]\n" << endl;
    cout << "手动模式需要自行输入精度，不推荐新手使用。\n[Manual mode requires self input accuracy and is not recommended for beginners.]\n" << endl;
    cout << "请选择精度模式（0：自动    1：手动）：\n[Please select the precision mode (0: automatic 1: manual):]";
    cin >> e;
    //程序前言结束[End of program preface]


    if (e == 1)//手动模式开始[Manual mode start]
    {

        cout << endl << "在这里输入精度（绝对误差最大值）：\n[Enter the accuracy (maximum absolute error) here:]";
        cin >> b;
        cout << endl << "在这里输入小数：\n[Enter decimals here:]";
        cin >> a;
        if (a < 0)
        {
            a = -a;
            d = -d;
        }
        cout << endl << "结果为：[The result is:]";
        for (i = 1; i <= c; i++)
        {
            if (abs((round(a * i)) / i - a) < b)
            {
                if (d < 0) cout << -round(a * i) << "/" << i << "    ";
                else cout << round(a * i) << "/" << i << "    ";
                cout << "绝对误差：[Absolute error:]" << (abs((round(a * i)) / i - a)) << "    相对误差：[Relative error:]" << (abs((round(a * i)) / i - a)) / a * 100 << "%" << endl << endl;
                break;
            }
        }

    }//手动模式结束[End of manual mode]


    else if (e == 0)//自动模式开始[Automatic mode start]
    {

        cout << endl << "在这里输入小数：\n[Enter decimals here:]";
        cin >> a;
        if (a < 0)
        {
            a = -a;
            d = -d;
        }
        cout << endl << "结果如下：\n[The results are as follows:]" << endl << endl;
        cout << std::left << setw(23) << "精度[accuracy]" << std::left << setw(16) << "结果[result]" << std::left << setw(16) << "  绝对误差[absolute error]" << "  相对误差[relative error]" << endl;
        for (j = 0.1; j > f; j = j / 10, b = j)
        {
            cout << std::left << setw(8) << j;
            for (i = 1; i <= c; i++)
            {
                if (abs((round(a * i)) / i - a) < b)
                {
                    if (d < 0) cout << std::right << setw(16) << -round(a * i) << "/" << std::left << setw(16) << i;
                    else cout << std::right << setw(16) << round(a * i) << "/" << std::left << setw(16) << i;
                    cout << std::left << setw(26) << (abs((round(a * i)) / i - a)) << (abs((round(a * i)) / i - a)) / a * 100 << "%" << endl;
                    if ((abs((round(a * i)) / i - a)) == 0) goto endend;
                    break;
                }
            }
        }
    endend:;
        cout << endl;
    }//自动模式结束[Automatic mode end]

    system("pause");
    return 0;
}