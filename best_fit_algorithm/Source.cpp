#include<iostream>
#include<string>

using namespace std;

struct process {
	int job;
	int partition;
};

struct JQ {
	int name;
	int memory;
};

struct MM {
	int pname;
	int psize;
	int flag = 0;  //waiting
	string status;
};


int main() {

	int numJobs;
	int numPartitions;
	
	MM Pinput[50];
	JQ Jinput[50];

	cout << "enter the total number of jobs: ";
	cin >> numJobs;
	for (int i = 1; i <= numJobs; i++)
	{
		cout << "enter the job name (in number) : ";
		cin >> Jinput[i].name;
		cout << "memory needed: ";
		cin >> Jinput[i].memory;

	}
	cout << "enter the total number of partitions: ";
	cin >> numPartitions;

	for (int k = 1; k <= numPartitions; k++)
	{
		cout << "enter the partition name  (in number): ";
		cin >> Pinput[k].pname;
		cout << "size of the partition: ";
		cin >> Pinput[k].psize;
	}

	cout << endl;
	cout << "job       partition        waste          status  " << endl;
	cout << "------------------------------------------------";
	cout << endl;

	int waste = 0;
	int indexBest;
	int bestWaste;

	//loop for jobs:
	for (int m = 1; m <= numJobs; m++)
	{	
		 bestWaste = 999999999;

		//loop for partitions
		for (int u = 1; u <= numPartitions; u++)         	
		{
			
			if (Jinput[m].memory <= Pinput[u].psize    &&  Pinput[u].flag == 0  )
			{
				waste = Pinput[u].psize - Jinput[m].memory;
				//to check best waste:
				if (bestWaste > waste)
				{
					bestWaste = waste;
					indexBest = Pinput[u].pname;	
					
				}
			}
			//after going through all partitions
			if (u == numPartitions)
			{
				Pinput[indexBest].flag = 1;
				Pinput[indexBest].status = "run"; 
				cout << Jinput[m].name << "             " << Pinput[indexBest].pname << "            " << bestWaste << "           " << Pinput[indexBest].status   << endl;			
			}
		}	
	}
	cout << "total waste: " << bestWaste << endl;

	system("PAUSE");
	return 0;
}