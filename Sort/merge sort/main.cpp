#include <iostream>
#define SIZE 8
int sorted[SIZE];   // 추가적인 공간이 필요

using namespace std;

// i : 정렬된 왼쪽 리스트에 대한 인덱스
// j : 정렬된 오른쪽 리스트에 대한 인덱스
// k : 정렬된 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */


void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid+1;
    k = left;

    /* 분할 정렬된 list의 합병*/
   while(i<=mid && j<=right)
   {
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  // 남아 있는 값들을 일괄 복사
  if(i>mid)
  {
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  // 남아 있는 값들을 일괄 복사
  else
  {
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++)
  {
    list[l] = sorted[l];
  }
}

void merge_sort(int list[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left + right)/2; // 중간 위치를 계산하여 리스트를 균등 분할(Divide)
        cout << "하기전 : "<< left << right << mid << endl;
        merge_sort(list, left, mid);

        cout << "앞쪽 : "<< left << right << mid << endl;
        merge_sort(list, mid+1, right);

        cout << "뒤쪽 : "<< left << right << mid << endl;
        merge(list, left, mid, right);
        
        cout << " 끝" << endl;
    }
}

int main()
{
	int list[SIZE] = {21, 10, 12, 20 , 25, 13, 15, 22};

    // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
    merge_sort(list, 0, SIZE-1);
    for (int i = 0; i < SIZE; i++)
    {
        
        cout << list[i]<<endl;
    }
    
    return 0;
}