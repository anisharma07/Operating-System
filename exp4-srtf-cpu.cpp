// Experiment 4: Write a program to simulate CPU scheduling using Shortest remaining time First(SRTF) algorithm.

#include <iostream>
using namespace std;

void printResults(int burst_time[], int arrival_time[], int waiting[], int turnaround[], int completion[], int n)
{
    double avgTAT = 0, avgWT = 0;
    cout << "Process"
         << "\t\t"
         << "BT"
         << "\t\t"
         << "AT"
         << "\t\t"
         << "WT"
         << "\t\t"
         << "TAT"
         << "\t\t"
         << "CT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << "\t\t" << burst_time[i] << "\t\t" << arrival_time[i] << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << "\t\t" << completion[i] << endl;
        avgWT += waiting[i];
        avgTAT += turnaround[i];
    }
    cout << "\nAverage waiting time =" << avgWT / n << endl;
    cout << "Average Turn around time =" << avgTAT / n << endl;
    cout << endl;
}
int main()
{

    int arrival_time[20], burst[20], burst_time[20];
    int waiting[20], turnaround[20], completion[20];
    int smallest, count = 0, time, n;
    double end;
    cout << "\nEnter the number of Processes: ";
    cin >> n;
    cout << "\nEnter arrival_time time of process: ";
    for (int i = 0; i < n; i++)
        cin >> arrival_time[i];
    cout << "\nEnter burst time of process: ";
    for (int i = 0; i < n; i++)
        cin >> burst[i];
    for (int i = 0; i < n; i++)
        burst_time[i] = burst[i];

    burst[19] = INT16_MAX;
    for (time = 0; count != n; time++)
    {
        smallest = 19;
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= time && burst[i] < burst[smallest] && burst[i] > 0)
                smallest = i;
        }
        burst[smallest]--;

        if (burst[smallest] == 0)
        {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - arrival_time[smallest] - burst_time[smallest];
            turnaround[smallest] = end - arrival_time[smallest];
        }
    }
    printResults(burst_time, arrival_time, waiting, turnaround, completion, n);

    return 0;
}
// 0 1 2 4
// 5 4 2 1