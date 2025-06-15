#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Job {
    char name[10];
    int deadline;
    int profit;
};

void input(struct Job jobs[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter job name, deadline, and profit for job %d: ", i + 1);
        scanf("%s %d %d", jobs[i].name, &jobs[i].deadline, &jobs[i].profit);
    }
}

void sortJobsByProfit(struct Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int findMaxDeadline(struct Job jobs[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

int jobSequencing(struct Job jobs[], int n) {
    int maxDeadline = findMaxDeadline(jobs, n);
    int* slots = (int*)malloc(maxDeadline * sizeof(int));
    struct Job* scheduledJobs = (struct Job*)malloc(maxDeadline * sizeof(struct Job));
    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = -1;
    }
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = i;
                scheduledJobs[j] = jobs[i];
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("Scheduled Jobs:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i] != -1) {
            printf("%s ", scheduledJobs[i].name);
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);
    free(slots);
    free(scheduledJobs);
    return totalProfit;
}

int main() {
    int n;
    clock_t start, end;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job* jobs = (struct Job*)malloc(n * sizeof(struct Job));
    input(jobs, n);
    sortJobsByProfit(jobs, n);
    start = clock();
    jobSequencing(jobs, n);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    free(jobs);
    return 0;
}