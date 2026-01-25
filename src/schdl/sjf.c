#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void sjf_schedule(Process p[], int n)
{
    int time = 0;
    int completed = 0;

    while (completed < n) {
        int idx = -1;

        /* Buscar el proceso más corto que ya haya llegado */
        for (int i = completed; i < n; i++) {
            if (!p[i].completed && p[i].arrival_time <= time) {
                if (idx == -1 ||
                    p[i].burst_time < p[idx].burst_time ||
                    (p[i].burst_time == p[idx].burst_time &&
                     p[i].id < p[idx].id)) {
                    idx = i;
                }
            }
        }

        /* Si nadie ha llegado aún, avanzar el tiempo */
        if (idx == -1) {
            time++;
            continue;
        }

        /* Reordenar el arreglo en orden de ejecución */
        Process temp = p[completed];
        p[completed] = p[idx];
        p[idx] = temp;

        /* Calcular tiempos */
        p[completed].waiting_time =
            time - p[completed].arrival_time;
        time += p[completed].burst_time;
        p[completed].turnaround_time =
            p[completed].waiting_time + p[completed].burst_time;

        p[completed].completed = 1;
        completed++;
    }
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    sjf_schedule(p, n);

    print_results(p, n, "SJF Scheduling");
    return 0;
}
#endif

