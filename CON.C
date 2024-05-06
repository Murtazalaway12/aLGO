#include <stdio.h>

void check_and_conquer(int *array, int start, int end) {
  if (start >= end) {
    return;
  }

  int mid = (start + end) / 2;

  check_and_conquer(array, start, mid);
  check_and_conquer(array, mid + 1, end);

  // Check if the two halves of the array are sorted
  if (array[mid] > array[mid + 1]) {
    // Swap the two elements
    int temp = array[mid];
    array[mid] = array[mid + 1];
    array[mid + 1] = temp;
  }
}

int main() {
  int array[] = {5, 3, 2, 1, 4};

  check_and_conquer(array, 0, sizeof(array) / sizeof(array[0]) - 1);

  for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}
