

#include <iostream>
using namespace std;
void snakeArray(int** M, int n) {

	int k = 1;
	int i = 0, j = 0, dir = 1;

	while (k <= n * (n + 1) / 2) {
		M[i][j] = k++;
		i += dir;
		j -= dir;
		if (j < 0) {
			j = 0;
			dir = -dir;
		}
		if (i < 0) {
			i = 0;
			dir = -dir;
		}
	}
	
	i += dir;
	j -= dir;
	while (k <= n * n) {
		M[i][j] = k++;
		i += dir;
		j -= dir;
		if (i >= n) {
			dir = -dir;
			i = n - 1;
			j += 2;
		}
		if (j >= n) {
			dir = -dir;
			j = n - 1;
			i += 2;
		}
	}
}


int main()
{
	int n;
	cout << "Input n" << endl;
	cin >> n;
	int** M = new int* [n];
	for (int i = 0; i < n; ++i)
		M[i] = new int[n];

	snakeArray(M, n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << M[i][j] << ' ';
		cout << endl;
	}

	for (int i = 0; i < n; ++i)
		delete[] M[i];
	delete[] M;
	return 0;
}