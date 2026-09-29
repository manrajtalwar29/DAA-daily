#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    int k = n;

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {

            if (arr[i] == arr[j]) {

                // Shift elements to the left
                for (int x = j; x < k - 1; x++) {
                    arr[x] = arr[x + 1];
                }

                k--;
                j--;
            }
        }
    }

    return k;
}

int main() {
    int arr[] = {3, 1, 2, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = removeDuplicates(arr, n);

    printf("k = %d\n", k);
    printf("Array after removing duplicates: ");

    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
