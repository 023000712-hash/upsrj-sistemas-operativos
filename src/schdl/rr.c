#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void rr_schedule(Process p[], int n, int quantum)
{
    int time = 0;
    int done;

    do {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 &&
                p[i].arrival_time <= time) {

                done = 0;

                if (p[i].remaining_time > quantum) {
                    time += quantum;
                    p[i].remaining_time -= quantum;
                } else {
                    time += p[i].remaining_time;
                    p[i].waiting_time =
                        time - p[i].arrival_time - p[i].burst_time;
                    p[i].turnaround_time =
                        p[i].waiting_time + p[i].burst_time;
                    p[i].remaining_time = 0;
                    p[i].completed = 1;
                }
            }
        }
    } while (!done);
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    int quantum;

    printf("Número de procesos: ");
    scanf("%d", &n);

    printf("Quantum: ");
    scanf("%d", &quantum);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    rr_schedule(p, n, quantum);

    print_results(p, n, "RR Scheduling");
    return 0;
}
#endif

