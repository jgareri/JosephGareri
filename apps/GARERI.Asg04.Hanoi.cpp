// GARERI.Asg04.Hanoi.cpp 
//Joseph Gareri
//jgareri@my.athens.edu
//Asg 04
//Derived from code pulled from instructor lecture

#include <iostream>
#include <stack> 
#include <chrono>
#include <fstream>

using namespace std;

void recursiveDisks(int, int, int, int);
void iterateDisks(int, int, int, int);

class Iterate
{
public:
	int from;
	int to;
	int temp;
	int num;
};

void recursiveDisks(int numDisks, int fromPeg, int toPeg, int tempPeg)
{
	if (numDisks > 0)
	{
		recursiveDisks(numDisks - 1, fromPeg, tempPeg, toPeg);
		cout << "Move a disk from peg " << fromPeg << endl;
		cout << " to peg " << toPeg << endl;
		recursiveDisks(numDisks - 1, tempPeg, toPeg, fromPeg);

	}
	
}

void iterateDisks(int numDisks, int fromPeg, int toPeg, int tempPeg)
{
	stack<Iterate> stackofdisks;

	while (numDisks >= 1 || !stackofdisks.empty()) 
	{
		while(numDisks>=1)
		{
			Iterate disk;
			disk.from = fromPeg;
			disk.to = toPeg;
			disk.temp = tempPeg;
			disk.num = numDisks;
			stackofdisks.push(disk);
			swap(toPeg, tempPeg);
			numDisks--;

		}
		Iterate disk = stackofdisks.top();
		stackofdisks.pop();
		cout << "Move a disk from peg " << disk.from << endl << " to peg " << disk.to << endl;
		if (disk.num >= 1)
		{
			fromPeg = disk.temp;
			tempPeg = disk.from;
			toPeg = disk.to;
			numDisks = disk.num - 1;
		}
	}


}

int main()
{
	ofstream outfile("Time_Data.txt"); //time data push to file is for convenience
	const int numDisks = 30;
	const int fromPeg = 1;
	const int toPeg = 3;
	const int tempPeg = 2;
	cout << "First we move disks using recursion: " << endl;

	auto start = std::chrono::high_resolution_clock::now();
	recursiveDisks(numDisks, fromPeg, toPeg, tempPeg);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << " with elapsed time: " << elapsed_seconds.count() << "s\n";

	cout << "All the pegs are moved!" << endl << endl;

	cout << "Then we move disks using iteration: " << endl;
	auto start2 = std::chrono::high_resolution_clock::now();
	iterateDisks(numDisks, fromPeg, toPeg, tempPeg);
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds2 = end - start;
	std::cout << " with elapsed time: " << elapsed_seconds2.count() << "s\n";
	cout << "All pegs are moved again." << endl;

	outfile << "Num of Disks: "<< numDisks << " | Recursive Time (in seconds): " << elapsed_seconds.count() << endl;
	outfile << "Num of Disks: "<< numDisks << " | Iterative Time (in seconds): " << elapsed_seconds2.count() << endl;

	outfile.close();
	return 0;

}




