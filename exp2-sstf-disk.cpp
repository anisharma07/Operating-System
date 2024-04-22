// Experiment 1: Implement Disk Scheduling using Shortest Seek Time First algorithm.
#include <iostream>
using namespace std;

void SSTF(int a[], int n, int pos, int time)
{
    cout << "\nSeek Sequence: ";
    for (int i = 0; i < n; i++)
    {
        int next_min = INT16_MAX;
        int index;
        for (int j = 0; j < n; j++)
        {
            int diff = abs(pos - a[j]);
            if (diff < next_min && a[j] != -1)
            {
                next_min = diff;
                index = j;
            }
        }
        time = time + abs(pos - a[index]);
        cout << a[index] << " ";
        pos = a[index];
        a[index] = -1;
    }
    cout << "\nThe Total no. of track movement by the head are: " << time << "\n"
         << endl;
}

int main()
{
    int n, head, time = 0;
    cout << "Enter No. of Request tracks: ";
    cin >> n;
    int requestsArr[n];
    cout << "Enter Request tracks: ";
    for (int i = 0; i < n; i++)
        cin >> requestsArr[i];
    cout << "Enter initial position of r/w head: ";
    cin >> head;
    SSTF(requestsArr, n, head, time);
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