#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input(int start[], int finish[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter start and finish time for activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }
}

void sortActivitiesByFinishTime(int start[], int finish[], int n, int indices[]) {
    for (int i = 0; i < n; i++) {
        indices[i] = i + 1;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;

                temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }
}

void activitySelection(int start[], int finish[], int n, int indices[]) {
    printf("Selected Activities:\n");
    printf("%d", indices[0]);
    int lastFinish = finish[0];
    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            printf(", %d", indices[i]);
            lastFinish = finish[i];
        }
    }
    printf("\n");
}

int main() {
    int n;
    clock_t start_time, end_time;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    int* start = (int*)malloc(n * sizeof(int));
    int* finish = (int*)malloc(n * sizeof(int));
    int* indices = (int*)malloc(n * sizeof(int));
    input(start, finish, n);
    sortActivitiesByFinishTime(start, finish, n, indices);
    start_time = clock();
    activitySelection(start, finish, n, indices);
    end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    free(start);
    free(finish);
    free(indices);
    return 0;
}