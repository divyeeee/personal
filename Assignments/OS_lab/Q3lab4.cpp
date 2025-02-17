#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
};

// Function to implement Shortest Remaining Time First (SRTF) Scheduling
void srtfScheduling(vector<Process> processes) {
    int n = processes.size();
    int currentTime = 0, completed = 0;
    int shortestIndex = -1, shortestTime = INT_MAX;

    vector<int> remainingTime(n);
    for (int i = 0; i < n; i++)
        remainingTime[i] = processes[i].burstTime;

    vector<bool> completedProcess(n, false);

    cout << "\nSRTF Scheduling:\n";
    cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\n";

    while (completed < n) {
        shortestIndex = -1;
        shortestTime = INT_MAX;

        // Find the process with the shortest remaining time
        for (int i = 0; i < n; i++) {
            if (!completedProcess[i] && processes[i].arrivalTime <= currentTime && remainingTime[i] < shortestTime) {
                shortestTime = remainingTime[i];
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1) {
            currentTime++;
            continue;
        }

        // Process execution
        remainingTime[shortestIndex]--;
        currentTime++;

        // If the process is completed
        if (remainingTime[shortestIndex] == 0) {
            completed++;
            completedProcess[shortestIndex] = true;
            processes[shortestIndex].turnAroundTime = currentTime - processes[shortestIndex].arrivalTime;
            processes[shortestIndex].waitingTime = processes[shortestIndex].turnAroundTime - processes[shortestIndex].burstTime;
        }
    }

    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t" << p.waitingTime << "\t" << p.turnAroundTime << "\n";
    }
}

// Function to implement Round Robin Scheduling
void roundRobinScheduling(vector<Process> processes, int timeQuantum) {
    int n = processes.size();
    queue<int> readyQueue;
    int currentTime = 0;

    vector<int> remainingTime(n);
    for (int i = 0; i < n; i++)
        remainingTime[i] = processes[i].burstTime;

    vector<int> waitingTime(n, 0), turnAroundTime(n, 0);
    vector<bool> processInQueue(n, false);

    int completed = 0, lastArrivalIndex = 0;

    // Push processes into queue when they arrive
    while (completed < n) {
        for (int i = lastArrivalIndex; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processInQueue[i]) {
                readyQueue.push(i);
                processInQueue[i] = true;
                lastArrivalIndex = i + 1;
            }
        }

        if (readyQueue.empty()) {
            currentTime++;
            continue;
        }

        int index = readyQueue.front();
        readyQueue.pop();

        int executionTime = min(timeQuantum, remainingTime[index]);
        remainingTime[index] -= executionTime;
        currentTime += executionTime;

        for (int i = lastArrivalIndex; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !processInQueue[i]) {
                readyQueue.push(i);
                processInQueue[i] = true;
                lastArrivalIndex = i + 1;
            }
        }

        if (remainingTime[index] > 0) {
            readyQueue.push(index);
        } else {
            completed++;
            turnAroundTime[index] = currentTime - processes[index].arrivalTime;
            waitingTime[index] = turnAroundTime[index] - processes[index].burstTime;
        }
    }

    cout << "\nRound Robin Scheduling (Time Quantum = " << timeQuantum << "):\n";
    cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t" << processes[i].arrivalTime << "\t" << processes[i].burstTime
             << "\t" << waitingTime[i] << "\t" << turnAroundTime[i] << "\n";
    }
}

int main() {
    int n, timeQuantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    cout << "Enter Process ID, Arrival Time, and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i].pid >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    cout << "Enter Time Quantum for Round Robin: ";
    cin >> timeQuantum;

    srtfScheduling(processes);
    roundRobinScheduling(processes, timeQuantum);

    return 0;
}