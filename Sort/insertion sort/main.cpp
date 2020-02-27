#include <iostream>
#define SIZE 5

using namespace std;

void insertion_sort(int list[])
{
    int key,i,j;
	for (int i = 1; i < SIZE; i++)
	{
        key = list[i];

        for ( j = i-1; j >=0 ; j--)
        {
            if (list[j] > key)
            {
                // 오른쪽으로 이동
                list[j+1] = list[j];
            }
            else
            {
                break;
            }
            
        }
        list[j+1] = key;
	}
}
int main()
{
	int list[SIZE] = {8, 5, 6, 2 ,4};

    insertion_sort(list);
    for (int i = 0; i < SIZE; i++)
    {
        
        cout << list[i]<<endl;
    }
    
    return 0;
}