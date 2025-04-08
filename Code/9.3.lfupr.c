#include<stdio.h>

int main() {
    int i, j, n, a[50], frame[10], no, k, avail,pos, count = 0;
    int freq[10] = {0}; // Frequency of use
    printf("\nEnter the number of pages : ");
    scanf("%d", &n);

    printf("Enter the page numbers : ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nEnter the number of frames : ");
    scanf("%d", &no);

    for(i = 0; i < no; i++) {
        frame[i] = -1;
        freq[i] = 0;
    }

    printf("\nRef_String\tPage_Frames\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t", a[i]);
        avail = 0;

        for(j = 0; j < no; j++) {
            if(frame[j] == a[i]) {
                avail = 1;
                freq[j]++; // Increase frequency on hit
                printf("hit");
               
            }
        }

        if(avail == 0) {
            int min = freq[0];
            pos = 0;
            for(j = 1; j < no; j++) {
                if(freq[j] < min) {
                    min = freq[j];
                    pos = j;
                }
            }
            frame[pos] = a[i];
            freq[pos] = 1; // Reset frequency for new page
            count++;

            for(k = 0; k < no; k++) {
                if(frame[k] != -1)
                    printf("%d\t", frame[k]);
            }
        }

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", count);
    return 0;
}
