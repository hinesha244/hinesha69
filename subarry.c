#include <stdio.h>

int* find_subarray_with_given_sum(int arr[], int n, int sum) {
  int current_sum = arr[0], start = 0;
  static int result[2];

  for (int i = 1; i <= n; i++) {
    while (current_sum > sum && start < i - 1) {
      current_sum -= arr[start];
      start++;
    }

    if (current_sum == sum) {
      result[0] = start;
      result[1] = i - 1;
      return result;
    }

    if (i < n) {
      current_sum += arr[i];
    }
  }

  return -1;
}