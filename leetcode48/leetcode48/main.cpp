#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) 
{
	int bir = 0;
	int iki = 0;
	int uc = 0;
	int dort = 0;

	int M = matrix.size() - 1;
	int N = M+1;
	if (N % 2 != 0)
		N += 1;
	for (int j = 0; j < N/2; j++)
	{
		M = M - j;
		int NN = M;
		for (int i = 0; i < NN - j; i++)
		{
			bir = matrix[j][i+j];
			iki = matrix[i+j][M];
			uc = matrix[M][M - i];
			dort = matrix[M - i][j];
			//swap
			matrix[i+j][M] = bir;
			matrix[M][M - i] = iki;
			matrix[M - i][j] = uc;
			matrix[j][i+j] = dort;
		}
		M = M + j;
	}

}

void main()
{
	//vector<vector<int>> matrix = {	{1, 2, 3},
	//								{4, 5, 6},
	//								{7, 8, 9} };

	vector<vector<int>> matrix = { {5,1,9,11},
								{2,4,8,10},
								{13,3,6,7},
								{15,14,12,16} };

	//vector<vector<int>> matrix = { {2,29,20,26,16,28},
	//						{12,27,9,25,13,21},
	//						{32,33,32,2,28,14},
	//						{13,14,32,27,22,26},
	//						{33,1,20,7,21,7},
	//						{4,24,1,6,32,34} };

	//vector<vector<int>> matrix = { {1, 2},
	//							{3, 4}};

	rotate(matrix);

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " , ";
		}
		cout << endl;
	}
	system("pause");
}