#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;


double round(double x)//�����������ʼ[Start of rounding procedure]
{
    return (x > 0.0) ? (floor(x + 0.5)) : (ceil(x - 0.5));
}//��������������[End of rounding procedure]


int main()
{


    double a = 0, b = 0.00001, c = 1e+308, d = 1, e = 0, f = 1e-307, i = 1, j = 0.1;
    //a��Ҫת����С��[a is the decimal to be converted]
    //b�Ǿ���������ֵ[b is the maximum absolute error value]
    //c������ĸ[c is the maximum denominator]
    //d�����ڴ���ֵС����[d is used to handle negative decimals]
    //e�������л��Զ����ֶ�ģʽ��[e is used to switch between automatic and manual modes]
    //f���Զ�ģʽ��󾫶�[f is the maximum accuracy of automatic mode]
    //i��ѭ����������е�ǰ��ĸ[i is the current denominator in the loop calculation process]
    //j���Զ�ģʽѭ����������е�ǰ����[j is the current accuracy during the automatic mode loop calculation process]


    //����ǰ�Կ�ʼ[Program Preface Start]
    cout << "����С�������ת���ɷ���\n[Entering a decimal program will convert it to a fraction]" << endl << endl;
    cout << "����ģʽ���ܣ�\n[Introduction to precision mode:]\n" << endl;
    cout << "�Զ�ģʽֻ������С�����������뾫�ȣ�����������ֵ����������Զ��Ӿ���0.1��ʼ���㣬�ټ���0.01��0.001�ȵȣ�ֱ�������ȷ��Ϊֹ�����ֻ��ӽ������ѡ�Լ���Ҫ�ļ���,�������С����ԭ����������֣����ܾ������ó�0.1��0.01��0.001�Ȳ��������ԭ��������ʱ����ͨ���ֶ�ģʽѰ�Ҵ𰸡�\n[In automatic mode, you only need to input decimals without the need for precision (maximum absolute error). The program will automatically start calculating with an accuracy of 0.1, then calculate 0.01, 0.001, and so on until an accurate solution is obtained. Finally, you only need to choose what you want from the results. However, if the original fraction of decimals is too strange, setting the precision to 0.1, 0.01, or 0.001 may not be able to calculate the original fraction. In this case, you can find the answer through manual mode.]\n" << endl;
    cout << "�ֶ�ģʽ��Ҫ�������뾫�ȣ����Ƽ�����ʹ�á�\n[Manual mode requires self input accuracy and is not recommended for beginners.]\n" << endl;
    cout << "��ѡ�񾫶�ģʽ��0���Զ�    1���ֶ�����\n[Please select the precision mode (0: automatic 1: manual):]";
    cin >> e;
    //����ǰ�Խ���[End of program preface]


    if (e == 1)//�ֶ�ģʽ��ʼ[Manual mode start]
    {

        cout << endl << "���������뾫�ȣ�����������ֵ����\n[Enter the accuracy (maximum absolute error) here:]";
        cin >> b;
        cout << endl << "����������С����\n[Enter decimals here:]";
        cin >> a;
        if (a < 0)
        {
            a = -a;
            d = -d;
        }
        cout << endl << "���Ϊ��[The result is:]";
        for (i = 1; i <= c; i++)
        {
            if (abs((round(a * i)) / i - a) < b)
            {
                if (d < 0) cout << -round(a * i) << "/" << i << "    ";
                else cout << round(a * i) << "/" << i << "    ";
                cout << "������[Absolute error:]" << (abs((round(a * i)) / i - a)) << "    �����[Relative error:]" << (abs((round(a * i)) / i - a)) / a * 100 << "%" << endl << endl;
                break;
            }
        }

    }//�ֶ�ģʽ����[End of manual mode]


    else if (e == 0)//�Զ�ģʽ��ʼ[Automatic mode start]
    {

        cout << endl << "����������С����\n[Enter decimals here:]";
        cin >> a;
        if (a < 0)
        {
            a = -a;
            d = -d;
        }
        cout << endl << "������£�\n[The results are as follows:]" << endl << endl;
        cout << std::left << setw(23) << "����[accuracy]" << std::left << setw(16) << "���[result]" << std::left << setw(16) << "  �������[absolute error]" << "  ������[relative error]" << endl;
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
    }//�Զ�ģʽ����[Automatic mode end]

    system("pause");
    return 0;
}