#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapSack(int n, int W, int weight[], int benefit[]) {
    int dp[n + 1][W + 1];  
    int selected[n];       // array to store the selected items

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weight[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];  // if the weight of the current item exceeds the capacity, skip it
            } else {
                dp[i][j] = max(dp[i - 1][j], benefit[i - 1] + dp[i - 1][j - weight[i - 1]]);
            }
        }
    }

    // print the dynamic programming table
    printf("Dynamic Programming Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    // find the selected items
    int j = W;
    for (int i = n; i > 0 && j > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            selected[i - 1] = 1;
            j -= weight[i - 1];
        } else {
            selected[i - 1] = 0;
        }
    }

    // print the selected items and maximum value
    printf("\nSelected items:\n");
    int max_value = dp[n][W];
    for (int i = 0; i < n; i++) {
        if (selected[i]) {
            printf("Item %d (weight: %d, benefit: %d)\n", i + 1, weight[i], benefit[i]);
        }
    }
    printf("\nMaximum value: %d\n", max_value);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    int weight[n], benefit[n];
    printf("Enter the weight and benefit of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &weight[i], &benefit[i]);
    }

    knapSack(n, W, weight, benefit);

    return 0;
}