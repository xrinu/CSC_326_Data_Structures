#include<iostream>
#include<string>

using namespace std;


struct process {
	int job;
	string status = "waiting";
	int partition;
	int waste;
};


struct JQ {
	int name;
	int memory;
};


struct MM {
	int pname;
	int psize;
	int flag = 0;
};

int main() {

	int numJobs;
	int numPartitions;
	int pWaste;
	string pstatus;

	process output[50], output2[50];
	MM Pinput[50];
	JQ Jinput[50];

	cout << "enter the total number of jobs: ";
	cin>> numJobs;
	

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
		cout << "enter the partition name (in number) : ";
		cin >> Pinput[k].pname;
		cout << "size of the partition: ";
		cin >> Pinput[k].psize;
	}

	
	int totalWaste = 0;
	int x = 1;
	int z = 0;
	int y = 1;
	int b = 0;

	
	for (int m =1 ; m <= numJobs; m++) {

		
		for (int u = 1; u <= numPartitions; u++)
		{
			
			if (Jinput[m].memory <= Pinput[u].psize && Pinput[u].flag == 0  )
			{
			
				output[x].job = Jinput[m].name;
				output[x].partition = Pinput[u].pname;
				output[x].waste = Pinput[u].psize - Jinput[m].memory;
				output[x].status = "run";				
				Pinput[u].flag = 1;   
				totalWaste = totalWaste + output[x].waste;
				x++;
				z = u;
				b = 1;  
				break;
			}
			
			if (u == numPartitions   &&  b == 0 )
			{
				output2[y].job = Jinput[m].name;
				y++;
		}
		}

		b = 0;				
	}

	cout << endl;
	cout << "job       partition        waste          status  " <<endl;
	cout << "---------------------------------------------------------";
	cout << endl;

	
	for (int p = 1; p <= numJobs && output[p].status == "run" ; p++)

	{		
		cout  << output[p].job << "         " << output[p].partition <<"                  " << output[p].waste << "                 " << output[p].status <<endl;
	}

	y = y - 1;

	for (int num = 1; num <= y ; num++)
	{		
		cout << output2[num].job << "        NA                 NA                 waiting"  << endl;
	}

	

	cout << "total waste: " <<totalWaste << endl;

	cout << endl;
    
	return 0;

}