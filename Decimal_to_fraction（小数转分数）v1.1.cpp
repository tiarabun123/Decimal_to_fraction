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
    //a��Ҫת����С��
    //b�Ǿ���������ֵ
    //c������ĸ
    //d�����ڴ���ֵС����
    //e�������л��Զ����ֶ�ģʽ��
    //f���Զ�ģʽ��󾫶�
    //i��ѭ����������е�ǰ��ĸ
    //j���Զ�ģʽѭ����������е�ǰ����


    //����ǰ�Կ�ʼ
    cout << "����С�������ת���ɷ���" << endl << endl;
    cout << "����ģʽ���ܣ�" << endl;
    cout << "�Զ�ģʽֻ������С�����������뾫�ȣ�����������ֵ����������Զ��Ӿ���0.1��ʼ���㣬�ټ���0.01��0.001�ȵȣ�ֱ�������ȷ��Ϊֹ�����ֻ��ӽ������ѡ�Լ���Ҫ�ļ���,�������С����ԭ����������֣����ܾ������ó�0.1��0.01��0.001�Ȳ��������ԭ��������ʱ����ͨ���ֶ�ģʽѰ�Ҵ𰸡�" << endl;
    cout << "�ֶ�ģʽ��Ҫ�������뾫�ȣ����Ƽ�����ʹ�á�" << endl;
    cout << "��ѡ�񾫶�ģʽ��0���Զ�    1���ֶ�����";
    cin >> e;
    //����ǰ�Խ���


    if(e==1)//�ֶ�ģʽ��ʼ
    {
        
        cout << endl<<"���������뾫�ȣ�����������ֵ����";
        cin >> b;
    cout << endl << "����������С����";
    cin >> a;
    if (a < 0)
    {
        a = -a;
        d = -d;
    }
    cout << endl << "���Ϊ��";
    for (i = 1; i <= c; i++)
    {
        if (abs((round(a * i)) / i - a) < b)
        {
            if (d < 0) cout << -round(a * i) << "/" << i <<"    ";
            else cout << round(a * i) << "/" << i << "    ";
            cout << "������" << (abs((round(a * i)) / i - a)) << "    �����" << (abs((round(a * i)) / i - a)) / a * 100 << "%" << endl;
            break;
        }
    }
    
    }//�ֶ�ģʽ����


    else if (e == 0)//�Զ�ģʽ��ʼ
    {
        
        cout << endl << "����������С����";
        cin >> a;
        if (a < 0)
        {
            a = -a;
            d = -d;
        }
        cout << endl << "������£�" << endl << endl;
        cout << std::left << setw(23) << "����" << std::left << setw(16) << "���" << std::left << setw(16) << "  �������" << "  ������" << endl;
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
    }//�Զ�ģʽ����


    return 0;
}