// Program 7 Memory Allocation Algorithms (First Fit, Best Fit and Worst Fit)
#include <iostream>

using namespace std;

const int MAX = 100; // Maximum number of memory blocks and processes

int allocation[3];

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1)
                    worstIdx = j;
                else if (blockSize[worstIdx] < blockSize[j])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int m, n;
    int blockSize[MAX], processSize[MAX];

    cout << "Enter the number of memory blocks: ";
    cin >> m;
    cout << "Enter the size of each memory block:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
    }

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the size of each process:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processSize[i];
    }

    int choice;
    cout << "\nChoose the Memory Allocation Algorithm:\n";
    cout << "1. First Fit\n2. Best Fit\n3. Worst Fit " << endl;
    cout << "Enter choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
        firstFit(blockSize, m, processSize, n);
        break;
    case 2:
        bestFit(blockSize, m, processSize, n);
        break;
    case 3:
        worstFit(blockSize, m, processSize, n);
        break;
    default:
        cout << "Wrong Choice";
        break;
    }
    return 0;
}