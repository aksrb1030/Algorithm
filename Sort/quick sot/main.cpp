#include <iostream>
#define SIZE 9
#define SWAP(x, y, temp) ( (temp) = (x), (x) = (y), (y)= (temp) )	//메크로 함수

using namespace std;
/*
1, 피벗을 기준으로 2개의 부분 리스트로 나눈다.
2. 피벗보다 작은 값은 모두 왼쪽, 큰값은 오른쪽 리스트로 옮긴다
2개
*/

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];	// 정렬할 리스트의 가장 왼쪽이 pivot

	/* low와 high가 교차할 때까지 반복(low < high)*/
	do
	{
		/* list[low]가 피벗보다 작으면 계속 low를 증가 */
		do
		{
			low++; // low는 left + 1 에서 시작
		} while (low <= right && list[low] < pivot);

		/* list[high]가 피벗보다 크면 계속 high를 감소 */
		do {
			high--; //high는 right 에서 시작
		} while (high >= left && list[high] > pivot);

		// 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
		if (low < high) {
			SWAP(list[low], list[high], temp);
		}
	} while (low<high);

	// low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
	SWAP(list[left], list[high], temp);

	// 피벗의 위치인 high를 반환
	return high;

	low = left;
	high = right + 1;
}
void quick_sort(int list[], int left, int right)
{
	/* 정렬할 범위가 2개 이상의 데이터면(리스트의 크기가 0이나 1이 아니면) */
	if (left < right)
	{
		// partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할(Divide)
		int q = partition(list, left, right);

		// 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
		quick_sort(list, left, q - 1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
		quick_sort(list, q + 1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
	}
}

int main()
{

	int list[SIZE] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
	
	// 퀵 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 8)
	quick_sort(list, 0 , 8);

	for (int i = 0; i < SIZE; i++)
	{
		cout << list[i] <<" " ;
	}
	return 0;
}
