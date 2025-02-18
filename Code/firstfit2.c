#include<stdio.h>

struct memory {
    int size, alloc, flag;
} m[50];

struct process {
    int psize, flag;
} p[10];

void main() {
    int blk, i, np;
    printf("Enter the number of blocks: ");
    scanf("%d", &blk);
    
    // Input sizes of blocks
    for(i = 0; i < blk; i++) {
        printf("Size of block %d: ", i + 1);
        scanf("%d", &m[i].size);
        m[i].flag = 0;  // Initializing the flag as 0 (not allocated)
    }

    printf("\n");
    printf("Enter the number of processes: ");
    scanf("%d", &np);

    // Input sizes of processes
    for(i = 0; i < np; i++) {
        printf("Size of process %d: ", i + 1);
        scanf("%d", &p[i].psize);
        p[i].flag = 0;  // Initially, no process is allocated
    }

    // Allocate memory to processes
    for(i = 0; i < np; i++) {
        int allocated = 0;
        for(int j = 0; j < blk; j++) {
            if(p[i].psize <= m[j].size && m[j].flag == 0) {
                m[j].alloc = p[i].psize;  // Allocate process to block
                m[j].flag = 1;  // Mark the block as allocated
                p[i].flag = 1;  // Mark the process as allocated
                printf("Process %d is allocated to Block %d\n", i + 1, j + 1);
                allocated = 1;
                break;  // Once allocated, break out of the loop
            }
        }

        if (!allocated) {
            printf("Process %d is waiting (No suitable block found)\n", i + 1);
        }
    }
}

