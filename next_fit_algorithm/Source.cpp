#include<iostream>
#include<string>

using namespace std;

struct process {
	int job;
	string status = "waiting";
	int partition;
	int waste;



};

//job queue
struct JQ {
	int name;
	int memory;
};

//main memory
struct MM {
	int pname;
	int psize;
	int flag = 0;

};


int main() {

	int numJobs;
	int numPartitions;
	int pWaste;

	//struct objects
	process output[50], output2[50];
	MM Pinput[50];
	JQ Jinput[50];

	cout << "enter the total number of jobs: ";
	cin >> numJobs;


	//input jobs and memeory
	for (int i = 1; i <= numJobs; i++)
	{
		cout << "enter the job name (in number) : ";
		cin >> Jinput[i].name;
		cout << "memory needed: ";
		cin >> Jinput[i].memory;

	}

	cout << "enter the total number of partitions: ";
	cin >> numPartitions;


	//input partittion and sizes
	for (int k = 1; k <= numPartitions; k++)
	{
		cout << "enter the partition name  (in number) : ";
		cin >> Pinput[k].pname;
		cout << "size of the partition: ";
		cin >> Pinput[k].psize;
	}



	//next fit
	int totalWaste = 0;
	int p = 1;
	int x = 1;
	int flag2;
	int r = 1;
	int temp;
	//loop for job
	for (int m = 1; m <= numJobs; m++)
	{
		flag2 = 0;

		//loop for partitions
		while (p <= numPartitions)
		{
			//compare memory and size
			if (Jinput[m].memory <= Pinput[p].psize  )
			{
				output[x].job = Jinput[m].name;
				output[x].partition = Pinput[p].pname;
				output[x].waste = Pinput[p].psize - Jinput[m].memory;
				output[x].status = "run";
				totalWaste = totalWaste + output[x].waste;
				x++;
				flag2 = 1;
				temp = p + 1;
				break;
			}		
			p++;
		}
		if (flag2 == 1)
		{
			p++;
		}
		//when a job not fit into any of the partition
		if (flag2 != 1 )
		{
			output2[r].job = Jinput[m].name;
			r++;
			p = temp;
		}	
	}

	cout << endl;
	cout << "job       partition        waste          status  " << endl;
	cout << "---------------------------------------------------------";
	cout << endl;

	//output jobs which is on run
	for (int n = 1; n <= numJobs && output[n].status == "run"; n++)
	{
		cout << output[n].job << "         " << output[n].partition << "                  " << output[n].waste << "                 " << output[n].status << endl;
	}

	r = r - 1;

	//output jobs which is on waiting:
	for (int num = 1; num <= r; num++)
	{
		cout << output2[num].job << "         NA                   NA                 waiting" << endl;
	}

	cout << "total waste: " << totalWaste << endl;

	system("PAUSE");
	return 0;
}