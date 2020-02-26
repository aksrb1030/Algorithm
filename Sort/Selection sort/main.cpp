#include <iostream>
#define SIZE 5

using namespace std;

void selection_sort(int list[])
{
	int min;
	int x;
	int y;
	int swap;

	for (int j = 0; j < SIZE - 1; j++)
	{
		min = j;
		for (int i = j + 1; i < SIZE; i++)
		{
			if (list[i] < list[min])
			{
				min = i;
			}
		}
		if (j != min)
		{
			swap = list[j];
			list[j] = list[min];
			list[min] = swap;
		}
	}
}

int main()
{
	int list[SIZE] = { 9, 6, 7, 3, 5 };
	selection_sort(list);
	
	for (int i = 0;  i < SIZE;  i++)
	{
		cout << list[i] <<" ";
	}
	return 0;
}