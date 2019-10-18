#pragma once
namespace KW {

	template<typename Item_Type>
	class vector {
	private:
		// Data fields
		/** The initial capacity of the array */
		static const size_t INITIAL_CAPACITY = 10;
		/** The current capacity of the array */
		size_t current_capacity;
		/** The current num_items of the array  */
		size_t num_items;
		/** The array to contain the data */
		Item_Type* the_data;
	public:
		// Member Functions  
		/** Constructs<i> </i>an empty vector with the default
		initial capacity.
		*/
		vector<Item_Type>() : current_capacity(INITIAL_CAPACITY),
			the_data(new Item_Type[INITIAL_CAPACITY]), num_items(0) { }

		vector<Item_Type>(const vector<Item_Type>& other) : current_capacity(other.current_capacity), num_items(other.num_items), the_data(new Item_Type[other.current_capacity]) {
			for (size_t i = 0; i < num_items; i++)
				the_data[i] = other.the_data[i];
		}

		virtual ~vector<Item_Type>() {
			delete[] the_data;
		}


		void putBack(int index){
			
			if (index<0 || index>= num_items)
				throw std::out_of_range("index to insert is out of range");
			Item_Type item = the_data[index]; //save the element as a temporary variable first.

			for (int i = index; i < num_items-1; i++)
				the_data[i] = the_data[i + 1];
			the_data[num_items - 1] = item;
		}

		vector<Item_Type>& operator=(const vector<Item_Type>& other) {
			// Make a copy of the other vector.

			vector<Item_Type> the_copy(other);
			// Swap contents of self with the copy.
			swap(the_copy);
			// Return -- upon return the old value will be destroyed.
			return *this;
		}



		void push_back(const Item_Type& the_value) {
			// Make sure there is space for the new item.
			if (num_items == current_capacity) {
				// Allocate an expanded array
				reserve(2 * current_capacity);
			}
			// Insert the new item.
			the_data[num_items] = the_value;
			num_items++;
		}
		
		
		void reserve(size_t new_capacity) {
			if (new_capacity > current_capacity) {
				if (new_capacity > 2 * current_capacity)
					current_capacity = new_capacity;
				else
					current_capacity *= 2;  // Double the capacity.
				Item_Type* new_data = new Item_Type[current_capacity];
				// Copy the data over.
				for (size_t i = 0; i < num_items; i++)
					new_data[i] = the_data[i];
				// Free the memory occupied by the old copy.
				delete[] the_data;
				// Now point to the new data.
				the_data = new_data;
			}
		}

		void insert(size_t index, const Item_Type& the_value) {
			// Validate index.
			if (index > num_items) {
				throw std::out_of_range("index to insert is out of range");
			}
			// Ensure that there is space for the new item.
			if (num_items == current_capacity) {
				reserve(2 * current_capacity);   // Allocate an expanded array
			}
			// Move data from index to num_items - 1 down.
			for (size_t i = num_items; i > index; i--) {
				the_data[i] = the_data[i - 1];
			}
			// Insert the new item.
			the_data[index] = the_value;
			num_items++;
		}
		
		void erase(size_t index) {
			// Validate index.
			if (index > num_items) {
				throw std::out_of_range
					("index to insert is out of range");
			}
			// Move items below the removed one up.
			for (size_t i = index + 1; i < num_items; i++) {
				the_data[i - 1] = the_data[i];
			}
			num_items--;
		}

		Item_Type& at(size_t index) {
			// Verify that the index is legal.
			if (index < 0 || index >= num_items) {
				throw std::out_of_range
					("index to operator[] is out of range");
			}
			return the_data[index];
		}

		const Item_Type& at(size_t index) const {
			// Verify that the index is legal.
			if (index < 0 || index >= num_items) {
				throw std::out_of_range
					("index to operator[] is out of range");
			}
			return the_data[index];
		}
		
		Item_Type& operator[](size_t index) {
			// Verify that the index is legal.
			if (index < 0 || index >= num_items) {
				throw std::out_of_range
					("index to operator[] is out of range");
			}
			return the_data[index];
		}

		const Item_Type& operator[](size_t index) const {
			// Verify that the index is legal.
			if (index < 0 || index >= num_items) {
				throw std::out_of_range
					("index to operator[] is out of range");
			}
			return the_data[index];
		}

		bool empty() const{
			return num_items == 0;
		}

		size_t size() const{
			return num_items;
		}

		void swap(vector<Item_Type>& other) {
			std::swap(num_items, other.num_items);
			std::swap(current_capacity, other.current_capacity);
			std::swap(the_data, other.the_data);
		}




	};
};