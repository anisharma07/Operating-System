#include <iostream>
#include <bits/stdc++.h>
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
bool checkIfComplete(int burst[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (burst[i] != 0)
        {
            return true;
        }
    }
    return false;
}
bool contain(queue<int> readyQueue, int currProcess)
{
    while (!readyQueue.empty())
    {
        if (readyQueue.front() == currProcess)
        {
            return true;
        }
        readyQueue.pop();
    }
    return false;
}
int main()
{

    int n, tq, time = 0, currProcess = -1;
    cout << "\nEnter the number of Processes: ";
    cin >> n;
    int arrival_time[n], burst[n], rem_burst[n];
    int wt[n], tat[n], completion[n];
    queue<int> readyQueue;
    cout << "\nEnter arrival_time time of process: ";
    for (int i = 0; i < n; i++)
        cin >> arrival_time[i];
    cout << "\nEnter burst time of process: ";
    for (int i = 0; i < n; i++)
        cin >> burst[i];
    for (int i = 0; i < n; i++)
        rem_burst[i] = burst[i];
    cout << "Enter the time quantum: ";
    cin >> tq;
    while (checkIfComplete(rem_burst, n))
    {
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= time && rem_burst[i] != 0 && i != currProcess && !contain(readyQueue, i))
            {
                readyQueue.push(i);
            }
        }
        if (currProcess != -1 && rem_burst[currProcess] != 0)
        {
            readyQueue.push(currProcess);
        }
        if (!readyQueue.empty())
        {
            currProcess = readyQueue.front();
            readyQueue.pop();
            if (rem_burst[currProcess] >= tq)
            {
                rem_burst[currProcess] = rem_burst[currProcess] - tq;
                time += tq;
            }
            else
            {
                for (int i = 1; i < tq; i++)
                {
                    if (rem_burst[currProcess] - i == 0)
                    {
                        rem_burst[currProcess] -= i;
                        time += i;
                        break;
                    }
                }
            }
            if (rem_burst[currProcess] == 0)
            {
                completion[currProcess] = time;
            }
        }
        else
        {
            time++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        wt[i] = completion[i] - arrival_time[i] - burst[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + burst[i];
    }
    printResults(burst, arrival_time, wt, tat, completion, n);
    return 0;
}
// 0 1 2 4
// 5 4 2 1