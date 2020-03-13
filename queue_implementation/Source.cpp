#include <iostream>
#include <string>

using namespace std;

struct Customer
{
	string CustomerName;    //Name of customer
	int ArrivalTime;        //Time of arrival
	int ServiceTime;       // Service time for customer
	int FinishTime;        // Time customer leaves
};
Customer newCus;

struct FcfsQueue
{
	Customer CustomerList[100];
	int length = -1;
	int head = -1;
};
FcfsQueue queue;

void GetInfo(Customer&);
void Enqueue(FcfsQueue &queue, Customer &newCus);
void Dequeue(FcfsQueue &queue, Customer &newCus);
void PrintList(FcfsQueue &queue);


int main()
{

	FcfsQueue MyQueue;

	GetInfo(newCus);        //Get info of first customer
	Enqueue(queue, newCus);  //Enqueue customer      
	GetInfo(newCus);        //Second customer
	Enqueue(queue, newCus);  //Enqueue second customer
	PrintList(MyQueue);     //Print names of customers
	Dequeue(queue, newCus); //Serve first customer
	Dequeue(queue, newCus); //Serve second customer
	Dequeue(queue, newCus); //Empty queue

	system("pause");
	return 0;
}

void GetInfo(Customer&)
{

	cout << "Customer Name: ";
	cin >> newCus.CustomerName;
	cout << "Arrival Time: ";
	cin >> newCus.ArrivalTime;
	cout << "Service Time: ";
	cin >> newCus.ServiceTime;
	cout << "Time Finished: ";
	cin >> newCus.FinishTime;
}

void Enqueue(FcfsQueue &queue, Customer &newCus)
{
	queue.length++;
	if (queue.length >= 99)
		cout << "Sorry Queue is full! " << endl;

	else
		queue.CustomerList[queue.length] = newCus;  //Address of struct is stored in array

}

void Dequeue(FcfsQueue &queue, Customer &newCus)
{
	if (queue.length == -1)
		cout << "Queue is empty!" << endl;

	else
	{
		queue.head++;
		newCus = queue.CustomerList[queue.head];
		cout << "Customer served: " << newCus.CustomerName << endl;
	}

	if (queue.head == queue.length)
		queue.head = queue.length = -1;     //When head reaches end reset array.


}

void PrintList(FcfsQueue &MyQueue)
{
	for (int i = 0; i <= queue.length; i++)
		cout << "Customer " << i + 1 << " " << queue.CustomerList[i].CustomerName << endl;
}