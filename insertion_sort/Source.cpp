#include <iostream>

using namespace std;

int n;
int a[20];
int i;

//fucntion declaration for insertion sort:
int insertionSort(int , int a[]);

int insertionSort( int n, int a[]) {
	if (n <= 0)    //base case:
		return 0;

	insertionSort(n-1,a);
	int last = a[n - 1];
	int j = n - 2;

	while (j >= 0 && a[j] > last)
	{
		a[j + 1] = a[j];
		j--;
	} a[j + 1] = last;
}



int main()
{
	cout << "Enter your limit: ";
	cin >> n;
	cout << "Enter your integers that to be sorted: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//to print output:
	insertionSort(n, a);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	system("pause");
	return 0;
}