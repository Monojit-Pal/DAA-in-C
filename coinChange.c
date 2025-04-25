#include <stdio.h>
#include <stdlib.h>

void sortCoinsDescending(int coins[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }
}

int findCoinChange(int amount, int coins[], int n, int solution[]) {
    int count = 0;
    int remaining = amount;
    for (int i = 0; i < n && remaining > 0; i++) {
        if (remaining >= coins[i]) {
            solution[count++] = coins[i];
            remaining -= coins[i];
        }
    }
    if (remaining == 0) {
        return count;
    } else {
        return -1;
    }
}

int main() {
    int amount;
    int numCoins;
    printf("Enter the amount: ");
    scanf("%d", &amount);
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);
    int *coins = (int*)malloc(numCoins * sizeof(int));
    int *solution = (int*)malloc(numCoins * sizeof(int));
    if (coins == NULL || solution == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the coin denominations:\n");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }
    sortCoinsDescending(coins, numCoins);
    int count = findCoinChange(amount, coins, numCoins, solution);
    if (count == -1) {
        printf("Not possible\n");
    } else {
        printf("Coins used: ");
        for (int i = 0; i < count; i++) {
            printf("%d", solution[i]);
            if (i < count - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    free(coins);
    free(solution);
    return 0;
}