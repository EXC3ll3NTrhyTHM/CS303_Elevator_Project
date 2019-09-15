#ifndef CARRAY_H_
#define CARRAY_H_


namespace KW {
  /** A carray is a data structure that provides constant time insert,
      access, and removal to/of the items that are at either end and
      constant time random access to all items. It is similar to the
      deque, but does not meet all of the requirements of the deque.
  */
  template <typename Item_Type>
    class carray {
    
    public:
    // Member functions

    /** Construct an empty carray */
    carray() : capacity(DEFAULT_CAPACITY), num_items(0),
      front_index(0), back_index(DEFAULT_CAPACITY -1),  
      the_data(new Item_Type[DEFAULT_CAPACITY]) {}

    /** Pushes an item onto the back of the carray
	@param item The item to be inserted
    */
    void push_back(const Item_Type& item) {
        if (num_items == capacity) {
            reallocate();
        }
        num_items++;
        back_index = (back_index + 1) % capacity;
        the_data[back_index] = item;
    }

    /** Pushes an item onto the fron of the carray
	@param item The item to be inserted
    */
    void push_front(const Item_Type& item) {
      if (num_items == capacity) {
	reallocate();
      }
      num_items++;
      front_index = (front_index - 1 + capacity) % capacity;
      the_data[front_index] = item;
    }
    
    /** Returns a reference to the object at the front of the carray 
	without removing it.
	@return A referenct to the object at the front of the carray
    */
    Item_Type& front() {
      return the_data[front_index];
    }

    /** Returns a const reference to the object at the at the 
	front of the carray without removing it.
	@return A const reference to the object at the top of the carray
    */
    const Item_Type& front() const {
      return the_data[front_index];
    }

    /** Returns a reference to the object at the back of the carray 
	without removing it.
	@return A referenct to the object at the back of the carray
    */
    Item_Type& back() {
      return the_data[back_index];
    }

    /** Returns a const reference to the object at the at the 
	back of the carray without removing it.
	@return A const reference to the object at the top of the carray
    */
    const Item_Type& back() const {
      return the_data[back_index];
    }

    /** Removes the front item from the carray
     */
    void pop_front() {
      front_index = (front_index + 1) % capacity;
      num_items--;
    }

    /** Removes the back item from the carray
     */
    void pop_back() {
      back_index = (back_index - 1 + capacity) % capacity;
      num_items--;
    }

    /** Determine if the carray is empty */
    bool empty() const {
      return num_items == 0;
    }

    /** Determine the size of the carray */
    int size() const {
      return num_items;
    }

    /** Return a reference to an item referenced by an index
	@param i the index
	@return a reference to carray[i]
    */
    Item_Type& operator[](int i) {
      return the_data[(i + front_index) % capacity];
    }

    /** Return a const reference to an item referenced by an index
	@param i the index
	@return a reference to carray[i]
    */
    const Item_Type& operator[](int i) const {
      return the_data[(i + front_index) % capacity];
    }

    private:

    /** Double the capacity and reallocate the data
	Pre: The array is filled to capacity
	Post: The capacity is doubled and the first half
              of the expanded array is filled with data.
    */
    void reallocate() {
        int new_capacity = 2 * capacity;
        Item_Type* new_data = new Item_Type[new_capacity];
        int j = front_index;
        for (int i = 0; i < num_items; i++) {
            new_data[i] = the_data[j];
            j = (j + 1) % capacity;
        }
        front_index = 0;
        back_index = num_items - 1;
        capacity = new_capacity;
        the_data = new_data;
    }

    // Data fields
    /** The initial size of the data array */
    static const int DEFAULT_CAPACITY = 5;
    /** The current capacity of the data array */
    int capacity;
    /** The number of items in the carray */
    int num_items;
    /** The index of the front of the carray */
    int front_index;
    /** The index of the back of the carray */
    int back_index;
    /** Pointer to the array containing the data */
    Item_Type* the_data;
  };
}
#endif
