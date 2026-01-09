#include <stdio.h>

int main() {
    int n, i;
    int bt[10], wt[10], tat[10];
    int total_wt = 0, total_tat = 0;

    printf("Numero de procesos: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Tiempo de rafaga del proceso %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nProceso\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nPromedio WT = %.2f", (float) total_wt / n);
    printf("\nPromedio TAT = %.2f\n", (float) total_tat / n);

    return 0;
}
