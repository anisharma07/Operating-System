// Experiment: 3 Write a program to simulate CPU scheduling using first come first server(FCFS) algorithm.
#include <iostream>
using namespace std;

void setWaitingTime(int arrival[], int burst[], int wt[], int n)
{
    int timeCounter = 0;
    for (int i = 0; i < n; i++)
    {
        wt[i] = timeCounter - arrival[i];
        if (wt[i] < 0)
        {
            wt[i] = 0;
            timeCounter = arrival[i];
        }
        timeCounter += burst[i];
    }
}
void setTurnAround(int burst[], int wt[], int tat[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + burst[i];
    }
}

void printResults(int arrival[], int Burst[], int tat[], int wt[], int n)
{
    double total_wt = 0, total_tat = 0;
    cout << "\nProcesses \t"
         << "AT"
         << "\t\tBT"
         << "\t\tWT"
         << "\t\tTAT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " P" << i + 1
             << "\t\t"
             << arrival[i]
             << "\t\t"
             << Burst[i]
             << "\t\t"
             << wt[i]
             << "\t\t"
             << tat[i]
             << endl;
        // get avg. wt and tat
        total_wt += wt[i];
        total_tat += wt[i];
    }
    cout << "Average waiting Time: " << total_wt / n << endl;
    cout << "Average turn around Time: " << total_tat / n << endl;
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the Number of processes: ";
    cin >> n;
    int AT[n], BT[n], WT[n], TAT[n];
    cout << "Enter the Arrival time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        cin >> AT[i];
    }
    cout << "Enter the Burst time: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        cin >> BT[i];
    }
    setWaitingTime(AT, BT, WT, n);
    setTurnAround(BT, WT, TAT, n);

    printResults(AT, BT, TAT, WT, n);
    return 0;
}
// 0 1 2 4
// 5 4 2 1