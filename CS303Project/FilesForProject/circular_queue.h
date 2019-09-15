namespace CQ{

	template<typename Item_Type>
	class queue {
	public:
		queue() : capacity(DEFAULT_CAPACITY), num_items(0),
			front_index(0), rear_index(DEFAULT_CAPACITY - 1),
			the_data(new Item_Type[DEFAULT_CAPACITY]) {}

		queue(size_t capacity) : capacity(capacity), num_items(0),
			front_index(0), rear_index(capacity - 1),
			the_data(new Item_Type[capacity]) {}

		// Cost: O(1) (even on average when grows)
		void push(const Item_Type& item) {
			if (num_items == capacity) {
				reallocate();
			}
			num_items++;
			rear_index = (rear_index + 1) % capacity;
			the_data[rear_index] = item;
		}

		Item_Type& front() {
			return the_data[front_index];
		}

		void pop() {
			front_index = (front_index + 1) % capacity;
			num_items--;
		}
	
	private:
		void reallocate() {
			size_t new_capacity = 2 * capacity;
			Item_Type* new_data = new Item_Type[new_capacity];
			size_t j = front_index;
			for (size_t i = 0; i < num_items; i++) {
				new_data[i] = the_data[j];
				j = (j + 1) % capacity;
			}
			front_index = 0;
			rear_index = num_items - 1;
			capacity = new_capacity;
			std::swap(the_data, new_data);
			delete[] new_data;
		}


		// Data fields
		static const size_t DEFAULT_CAPACITY = 10;
		size_t capacity;
		size_t num_items;
		size_t front_index;
		size_t rear_index;
		Item_Type* the_data;
	};

};
