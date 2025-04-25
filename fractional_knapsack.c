#include <stdio.h>

struct item {
    int weight, value;
    float ratio;
};

void sortDescending(struct item items[], int n) {
    int i, j;
    struct item key;
    for (i = 1; i < n; i++) {
        key = items[i];
        j = i - 1;
        
        while (j >= 0 && items[j].ratio < key.ratio) {
            items[j + 1] = items[j];
            j = j - 1;
        }
        items[j + 1] = key;
    }
}

float fractionalKnapsack(struct item items[], int n, int capacity) {
    sortDescending(items, n);
    
    float totalValue = 0;
    int currentWeight = 0;
    
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].ratio * remainingWeight;
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int n, capacity;
    struct item items[100];
    float totalValue;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter the weight and value of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float) items[i].value / items[i].weight;
    }
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    totalValue = fractionalKnapsack(items, n, capacity);
    printf("Total value in the knapsack: %.2f\n", totalValue);
    
    return 0;
}