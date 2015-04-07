#include<iostream>


using namespace std;

int matrix[1000][1000] = {0};
int array[1000];

int calculate(int i, int j);

int main()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>array[i];
	
	cout<<calculate(0, n-1);
}

int calculate(int p, int q) {
	int min = 9999;
	int weight = 0;
	int answer = 0;
	if(matrix[p][q] > 0)
		return matrix[p][q];
	if(p  == q)
	{
		matrix[p][q] = 0;
		return 0;
	}
	for(int i = p; i <= q ; i++)
		weight += array[i];
	for(int r = p; r < q; r++) {
		//int answer = matrix[p][r-1] + matrix[r+1][q] + weight;
		answer = calculate(p, r) + calculate(r+1, q) + weight;
		if(answer < min)
			min = answer;
	}
	matrix[p][q] = min;	
	return min;
}
