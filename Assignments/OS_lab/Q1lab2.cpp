// C++ program for implementation of FCFS 
// scheduling
#include<iostream>
using namespace std;

// Function to find the waiting time for all 
// processes
void findWaitingTime(int processes[], int n, 
                          int at[],int bt[], int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1]-at[i];
}

// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n, 
                  int at[],int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

//Function to calculate average time
void findavgTime( int processes[], int n, int at[],int bt[])
{
    int arr[n],wt[n], tat[n], total_wt = 0, total_tat = 0;

    //Function to find waiting time of all processes
    findWaitingTime(processes, n, at,bt, wt);

    //Function to find turn around time for all processes
    findTurnAroundTime(processes, n, at,bt, wt, tat);

    //Display processes along with all details
    cout << "Processes  "<<" Arrival time  " <<" Burst time  "
         << " Waiting time  " << " Turn around time\n";

    // Calculate total waiting time and total turn 
    // around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << at[i]<<"\t\t"<<bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }

    cout << "Average waiting time = " 
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " 
         << (float)total_tat / (float)n;
}

// Driver code
int main()
{
    cout<<"Enter the number of processes."<<endl;
    int size =0;
    cin>>size;

    //process id's
    int processes[size];
    for (int i = 0; i < size; i++) {
        processes[i] = i + 1;
    }
    int n = sizeof processes / sizeof processes[0];
    // Arrival time of all processes
    cout<<"Enter arrival time of the corrsponding processes";
    int  arrival_time[size];
    for(int i = 0;i<size;i++){
        cin>>arrival_time[i];
    }
    //Burst time of all processes
    cout<<"Enter burst time for all the process."<<endl;
    int  burst_time[size];
    for(int i = 0;i<size;i++){
        cin>>burst_time[i];
    }

    findavgTime(processes, n,arrival_time,  burst_time);
    return 0;
}