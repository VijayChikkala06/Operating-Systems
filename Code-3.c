// To implement the Shortest Job First (SJF) CPU scheduling algorithm.

#include <stdio.h>

int main() 
{ 
	int n, bt[20], wt[20], tat[20], p[20], temp;
    float avg_wt = 0, avg_tat = 0; 
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Time for each process:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("P%d: ", i+1);
		scanf("%d", &bt[i]); 
	    p[i] = i+1; 
    } 
    for (int i = 0; i < n-1; i++) 
    { 
		for (int j = i+1; j < n; j++) 
        { 
			if (bt[i] > bt[j]) 
            { 
				temp = bt[i]; bt[i] = bt[j]; bt[j] = temp; 
				temp = p[i]; p[i] = p[j]; p[j] = temp; 
			} 
		} 
    } 
    wt[0] = 0; 
    for (int i = 1; i < n; i++) 
    { 
		wt[i] = wt[i-1] + bt[i-1]; 
    } 
