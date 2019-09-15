

#include "queue.h"
#include "circular_queue.h"
#include <string>
#include "deque.h"

using namespace std;


void removeItem(const char item, queue<char>& queue){
	int count = 0;
	int old_size = queue.size();

	while (count < old_size){
		if (queue.front() != item)
			queue.push(queue.front());

		queue.pop();
		count++;
	}
}

int main()
{

	queue<string> names;
	names.push("Rich");
	names.push("Debbie");
	names.push("Robin");
	names.push("Dustin");
	names.push("Jonathan");

	string first = names.front();

	names.pop();
	names.push("Philip");


	//declaring a circular queue
	CQ::queue<string> cir_queue(5);
	cir_queue.push("A");
	cir_queue.push("B");
	cir_queue.push("C");
	cir_queue.push("D");
	cir_queue.push("E");
	cir_queue.pop();
	cir_queue.push("F");
	cir_queue.push("G");

	KW::deque<string> deq;
	deq.push_back("A");
	deq.push_back("B");
	deq.push_back("C");
	deq.push_back("D");
	deq.push_back("E");
	deq.push_back("E");
	deq.push_back("E");
	deq.push_back("E");
	deq.push_back("E");
	deq.push_back("E");
	deq.push_back("E");
	deq.push_back("M");

	string res = deq[11];

	queue<char> q;
	q.push('A');
	q.push('C');
	q.push('B');
	q.push('C');
	q.push('C');
	q.push('D');

	removeItem('C', q);


	return 0;
}

