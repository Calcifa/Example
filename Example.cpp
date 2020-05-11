/*************************************************循环输出多个文件**********************************************************************************/
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//#include<fstream>
//#include<iomanip>
//#include<iostream>
//#include<sstream>
//using namespace std;
//int main()
//{
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		string s1 = "Step";
//		string s2 = ".dat";
//		ostringstream name;
//		name << s1 << i << s2;
//		ofstream fp1(name.str(), ofstream::out);
//		fp1 << i << endl;
//		fp1.close();
//	}
//}
/********************************************************new生成二维数组***************************************************************************/
//#include <iostream>
//using namespace std;
//int main()
//{
//	int row, col;
//	row = 3;
//	col = 4;
//	int** max;
//	max = new int* [row];
//	for (int i = 0; i < row; i++)
//	{
//		max[i] = new int[col];
//	}
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			max[i][j] = 4;
//		}
//	}
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			cout << max[i][j] << "\t";
//		}
//		cout << endl;
//	}
//}
/************************************************************OMP并行***********************************************************************/
//#include <iostream>
//#include<ctime>
//#include <omp.h>
//using namespace std;
////int main()
////{
////	int sum = 0;
////	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
////	int coreNum = omp_get_num_procs();//获得处理器个数 
////	int* sumArray = new int[coreNum];//对应处理器个数，先生成一个数组    
////	for (int i = 0; i < coreNum; i++)//将数组各元素初始化为0        
////		sumArray[i] = 0;
////#pragma omp parallel for     
////	for (int i = 0; i < 10; i++)
////	{
////		int k = omp_get_thread_num();//获得每个线程的ID   
////		cout << k << endl;
////		sumArray[k] = sumArray[k] + a[i];
////	}
////	for (int i = 0; i < coreNum; i++)
////		sum = sum + sumArray[i];
////	cout << "sum: " << sum << endl;
////	cout << coreNum << endl;
////	return 0;
////}
//void test()
//	int a = 0;
//	int i;
//	for (i = 0; i < 100000000; i++)
//		a++;
//}
//int main()
//{
//	int i;
//	clock_t t1 = clock();
//#pragma omp parallel for
//	for (i = 0; i < 10; i++)
//		test();
//	clock_t t2 = clock();
//	double dert = double(t2 - t1) / CLOCKS_PER_SEC;
//	cout << dert << endl;
//}
/***********************************************************new生成三维数组************************************************************************/
//#include <iostream>
//#define X 7
//#define Y 4
//#define Z 2
//using namespace std;
//int main()
//{
//	int i, j, k;
//	int*** max;
//	max = new int** [X];
//	for (i = 0; i < X; i++)
//	{
//		max[i] = new int* [Y];
//		for (int j = 0; j < Y; j++)
//		{
//			max[i][j] = new int[Z];
//		}
//	}
//	for (k = 0; k < Z; k++)
//	{
//		for (j = 0; j < Y; j++)
//		{
//			for (i = 0; i < X; i++)
//			{
//				max[i][j][k] = 4;
//			}
//		}
//	}
//	for (k = 0; k < Z; k++)
//	{
//		for (j = 0; j < Y; j++)
//		{
//			for (i = 0; i < X; i++)
//			{
//				cout << max[i][j][k] << "\t";
//			}
//			cout << endl;
//		}
//		cout << "----------------------------" << endl;
//	}
//}
/***********************************************************tecplot三维柱坐标数据格式************************************************************************/
#include<fstream>
#include<cmath>
#include<iostream>

#define pi 3.1415926
#define N_Theta 120
#define N_R 50
#define N_Z 50

using namespace std;

int main()
{
	int i, j, k;
	ofstream fp("test.dat", ofstream::out);
	fp << "TITLE = \"Test\"" << endl;
	fp << "VARIABLES = \"Theta\",\"R\",\"Z\",\"Data\"" << endl;
	fp << "ZONE T = \"Cirlcular zone\"" << endl;
	fp << "I = " << N_R << ", J = " << N_Theta + 1 << ", K = " << N_Z << endl;
	fp << "DATAPACKING = POINT" << endl;
	double d_theta = 2 * pi / N_Theta;
	for (k = 0; k < N_Z; k++)
	{
		for (j = 0; j < N_Theta + 1; j++)
		{
			for (i = 0; i < N_R; i++)
			{
				double data = i * 1e5;
				double theta = j * d_theta;
				double x = cos(theta) * i;
				double y = sin(theta) * i;
				fp << x << " " << y << " " << k << " " << data << endl;
			}
		}
	}
}