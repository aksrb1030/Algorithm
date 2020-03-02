#include <iostream>
#define SIZE 5
using namespace std;

void bubble_sort(int list[])
{
	int temp;

	for (int i = SIZE-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

int main()
{

	int list[SIZE] = { 7, 4, 5, 1, 3 };

	bubble_sort(list);
	for (int i = 0; i < SIZE; i++)
	{
		cout << list[i] <<" ";
	}
	return 0;
}