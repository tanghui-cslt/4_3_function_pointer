#include <iostream>
using namespace std;

void scanf_data(double temp_a[]);
double integral_f(double temp_a[], double(*fun)(double));
double integral_f_simple(double temp_a[], double(*fun)(double));
double func_1(double x);
double func_2(double x);
double func_3(double x);

int main()
{
	double temp_a[2] = { 0 };
	
	scanf_data(temp_a);
	integral_f(temp_a, func_1);
	integral_f_simple(temp_a, func_1);

	scanf_data(temp_a);
	integral_f(temp_a, func_2);
	integral_f_simple(temp_a, func_2);

	scanf_data(temp_a);
	integral_f(temp_a, func_3);
	integral_f_simple(temp_a, func_3);

	getchar();
	getchar();
	getchar();
	
	return 0;
}

double func_1(double x)
{
	return (3*x*x +x);
}
double func_2(double x)
{
	return sin(x);
}
double func_3(double x)
{
	return exp(x);
}


void scanf_data(double temp_a[])
{
	cout << "\n\n********������������½�:**********\n";

	for (size_t i = 0; i < 2; i++)
	{
		cin >> temp_a[i];

	}
}

double integral_f(double temp_a[],double (*fun)(double ))
{
	double piecewise = 4000;			//�ֶθ���
	double len = temp_a[1] - temp_a[0];	//����ĳ���
	double sum = 0;						//���ֵĽ��
	double piece_len = len / piecewise;	//ÿ��С�εĳ���

	double x = temp_a[0];				//���ε��ϵ׵�x
	double x_1 = temp_a[0];				//���ε��µ׵�x
	double fx = 0;						//���ε��ϵ�
	double fx_1 = 1.0 / (1 + x_1*x_1);	//���ε��µ�
	for (int i = 1; i <= piecewise; i++)
	{
		x = x_1;
		x_1 = i * piece_len + temp_a[0];
		fx = fx_1;
		fx_1 = (*fun)(x_1);

		sum += 0.5*piece_len*(fx + fx_1);
	}
	cout << "\n\n************���Ϊ*********\n";
	cout << sum << endl;
	return sum;
}


double integral_f_simple(double temp_a[], double(*fun)(double))
{
	double piecewise = 4000;			//�ֶθ���
	double len = temp_a[1] - temp_a[0];	//����ĳ���
	double sum = 0;						//���ֵĽ��
	double piece_len = len / piecewise;	//ÿ��С�εĳ���

	double x = temp_a[0];
	double x_1 = temp_a[0];
	double x_2 = temp_a[0];
	double fx = 0;
	double fx_1 = 0;
	double fx_2 = 1.0 / (1 + x_2*x_2);

	for (int i = 0; i < piecewise; i = i + 2)
	{
		x = x_2;
		x_1 = (i + 1) * piece_len + temp_a[0];;
		x_2 = (i + 2) * piece_len + temp_a[0];
		//cout << x << " " << x_1 << endl;
		fx = fx_2;
		fx_1 = (*fun)(x_1);
		fx_2 = (*fun)(x_2);

		sum += 2 * piece_len / 6.0 * (fx + 4 * fx_1 + fx_2);
	}
	cout << "\n\n************���Ϊ*********\n";
	cout << sum << endl;
	return sum;
}