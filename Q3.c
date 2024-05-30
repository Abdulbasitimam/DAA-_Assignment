#include <stdio.h>

void coinChange(int amount) {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(coins) / sizeof(coins[0]);
    int count[n];  // Array to store the count of each coin denomination

    // initialize the count array with zeros
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // iterate from the highest denomination to the lowest
    for (int i = n - 1; i >= 0; i--) {
        // while the coin denomination is less than or equal to the remaining amount
        while (amount >= coins[i]) {
            count[i]++;  // increment the count of the coin denomination
            amount -= coins[i];  // subtract the coin denomination from the remaining amount
        }
    }

    // print the results
    printf("Minimum number of coins required for Rs. 1988:\n");
    for (int i = n - 1; i >= 0; i--) {
        if (count[i] > 0) {
            printf("%d coin(s) of Rs. %d\n", count[i], coins[i]);
        }
    }
}

int main() {
    int amount = 1988;
    coinChange(amount);
    return 0;
}