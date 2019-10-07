#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
  int start2 = mid + 1;

  if (arr[mid] <= arr[start2]) {
    // 两边都是有序的 右边最小大于等于左边最大
    // 自然就是有序的 （默认是小到大排序
    return;
  }

  while (start <= mid && start2 <= end) {
    if (arr[start] <= arr[start2]) {
      start++;
    } else {
      // 整体右边挪动一个位置
      //
      int value = arr[start2];
      int index = start2;

      while (index != start) {
        arr[index] = arr[index - 1];
        index--;
      }
      arr[start] = value;

      start++;
      mid++;
      start2++;
    }
  }
}

void merge_sort(int arr[], int l, int r) {
  if (l < r) {
    int mid = l + (r - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}
int main() {

  int arr[] = {1, 53, 24, 456, 32, 42, 534, 568, 23512, 345};
  merge_sort(arr, 0, 9);
  for (int i = 0; i < 10; i++) {
    if (!i)
      printf("[");
    printf("%d", arr[i]);
    if (i == 9) {
      printf("]\n");
    } else {
      printf(",");
    }
  }

  return 0;
}
