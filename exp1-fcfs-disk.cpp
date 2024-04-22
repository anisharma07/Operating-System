// Experiment 1: Implement Disk Scheduling using First come first serve algorithm.
#include <iostream>
using namespace std;

void FCFS(int arr[], int head, int n)
{
    if (n == 0)
    {
        return;
    }
    int seekCount = 0;
    int distance, currentTrack;

    for (int i = 0; i < n; i++)
    {
        currentTrack = arr[i];
        if (currentTrack > head)
        {
            distance = currentTrack - head;
        }
        else
        {
            distance = head - currentTrack;
        }

        seekCount = seekCount + distance;
        head = currentTrack;
    }

    cout << "\nTotal seek time using FCFS: "
         << seekCount << endl;
    cout << "Seek Sequence: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int head, n;
    cout << "Enter Requests count: ";
    cin >> n;
    int requestsArr[n];
    cout << "Enter Requests: ";
    for (int i = 0; i < n; i++)
        cin >> requestsArr[i];
    cout << "Enter initial head: ";
    cin >> head;

    FCFS(requestsArr, head, n);

    return 0;
}

// Head = 100
// 55
// 58
// 39
// 18
// 90
// 160
// 150
// 38
// 184

// seek count = 9

// real time, distributed, clustered, batch, multiprocessing, multitasking.