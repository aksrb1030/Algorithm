#include <iostream>
#define SIZE 10
using namespace std;

void gap_sort(int list[], int start, int end, int gap)
{
	int key, j, i; 
	for (i = start + gap; i <= end; i = i + gap)
	{
		key = list[i];

		for (j = i - gap; j >= start && list[j]>key; j = j - gap)
		{
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}
void shell_sort(int list[])
{
	for (int gap = SIZE/2; gap > 0; gap=gap/2)
	{
		if ((gap % 2) == 0)
		{
			gap++;
		}

		for (int i = 0; i < gap; i++)
		{
			gap_sort(list, i, SIZE-1, gap);
		}
	}
}

int main()
{
	int list[SIZE] = {10, 8, 6, 20 , 4, 3, 22, 1, 0 , 15};

	shell_sort(list);

	for (int i = 0; i < SIZE; i++)
	{
		cout << list[i] << " ";
	}
	return 0;
}