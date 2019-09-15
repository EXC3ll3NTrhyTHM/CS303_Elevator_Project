#include <cstddef>

template<typename Item_Type>
class queue {
private:
	// Insert implementation-specific data fields
	// Insert definition of Node here
#include "Node.h"
	// Data fields
	Node* front_of_queue;
	Node* back_of_queue;
	size_t num_items;

public:

	queue(Node* front_of_queue = NULL, Node* back_of_queue = NULL) :
		front_of_queue(front_of_queue), back_of_queue(back_of_queue), num_items(0) {}
	
	void push(const Item_Type& item) {
		if (front_of_queue == NULL) {
			back_of_queue = new Node(item, NULL);
			front_of_queue = back_of_queue;
			back_of_queue = new Node(item, NULL);
			front_of_queue = back_of_queue;
		}
		else {
			back_of_queue->next = new Node(item, NULL);
			back_of_queue = back_of_queue->next;
		}
		num_items++;
	}
	
	Item_Type& front() {
		return front_of_queue->data;
	
	}

	int size(){
		return num_items;
	}

	
	void pop() {
		Node* old_front = front_of_queue;
		front_of_queue = front_of_queue->next;
		if (front_of_queue == NULL) {
			back_of_queue = NULL;
		}
		delete old_front;
		num_items--;
	}

};
