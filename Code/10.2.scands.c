#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int head, a[25], i, n, size, distance, seektime = 0, pos;

    printf("\nEnter Head position: ");
    scanf("%d", &head);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk size: ");
    scanf("%d", &size);

    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Add head, start (0), and end (size-1)
    a[n++] = head;
    a[n++] = 0;
    a[n++] = size - 1;

    // Sort the entire array
    bubbleSort(a, n);

    // Find position of head in sorted array
    for (i = 0; i < n; i++) {
        if (a[i] == head) {
            pos = i;
            break;
        }
    }

    printf("\n\tSCAN DISK SCHEDULING\n");

    // Move to the right
    for (i = pos; i < n - 1; i++) {
        distance = a[i + 1] - a[i];
        printf("Head movement from %d to %d : %d\n", a[i], a[i + 1], distance);
        seektime += distance;
    }

    // Then reverse and go to the left
    for (i = pos - 1; i > 0; i--) {
        distance = a[i] - a[i - 1];
        printf("Head movement from %d to %d : %d\n", a[i], a[i - 1], distance);
        seektime += distance;
    }

    printf("\nTotal seek time is : %d\n", seektime);

    return 0;
}
