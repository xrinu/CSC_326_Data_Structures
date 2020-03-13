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
	int indexWorst;
	int flag2 = 0;
	int worstWaste;
	int totalWaste;

	//loop for jobs:
	for (int m = 1; m <= numJobs; m++)
	{
		worstWaste = 0;

		//loop for partitions
		for (int u = 1; u <= numPartitions; u++)
		{
			if (Jinput[m].memory <= Pinput[u].psize    &&  Pinput[u].flag == 0)
			{
				waste = Pinput[u].psize - Jinput[m].memory;
				//to check worst waste:
				if (worstWaste < waste)
				{
					worstWaste = waste;
					indexWorst = Pinput[u].pname;
				}
			}
			//after going through all partitions
			if (u == numPartitions)

			{
				 totalWaste = worstWaste + waste;
				Pinput[indexWorst].flag = 1;
				Pinput[indexWorst].status = "run";
				cout << Jinput[m].name << "             " << Pinput[indexWorst].pname << "            " << worstWaste << "           " << Pinput[indexWorst].status << endl;
			}
			
		}
	}

	system("PAUSE");
	return 0;
}