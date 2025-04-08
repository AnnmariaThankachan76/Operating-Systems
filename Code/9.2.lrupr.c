#include<stdio.h>

int main() {
	int i, j, n, a[50], frame[10], no, k, avail, count=0, least, pos, time[10];
	printf("\nEnter the number of pages : ");
	scanf("%d",&n);

	printf("Enter the page numbers : ");
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("\nEnter the number of frames : ");
	scanf("%d", &no);
	
	for(i = 0; i < no; i++) {
		frame[i] = -1;
		time[i] = 0;
	}

	printf("\nRef_String\tPage_Frames\n");

	for(i = 0; i < n; i++) {
		printf("%d\t\t", a[i]);
		avail = 0;

		for(k = 0; k < no; k++) {
			if(frame[k] == a[i]) {
				avail = 1;
				time[k] = i;  // update recent use time
				printf("hit");
				
			}
		}

		if(avail == 0) {
			// Find the least recently used page
			least = time[0];
			pos = 0;
			for(j = 1; j < no; j++) {
				if(time[j] < least) {
					least = time[j];
					pos = j;
				}
			}
			frame[pos] = a[i];
			time[pos] = i;
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
