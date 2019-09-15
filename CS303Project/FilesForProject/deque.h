#ifndef DEQUE_H_
#define DEQUE_H_

#include <stdexcept>
#include "Carray.h"

namespace KW {
  /** A deque is a data structure that provides constant time insert,
      access, and removal to/of the items that are at either end and
      constant time random access to all items. This implementation
      is similar to that used by the standard library. Random access
      is only provided via indexing, but a random access iterator
      can be easially defined.
  */
  template <typename Item_Type>
    class deque {
    
    public:
    // Member functions

    /** Construct an empty deque */
		deque();

    /** Pushes an item onto the back of the deque
	@param item The item to be inserted
    */
    void push_back(const Item_Type& item);

    /** Pushes an item onto the fron of the deque
	@param item The item to be inserted
    */
    void push_front(const Item_Type& item);

    /** Returns a reference to the object at the front of the deque 
	without removing it.
	@return A referenct to the object at the front of the deque
    */
    Item_Type& front();

    /** Returns a const reference to the object at the at the 
	front of the deque without removing it.
	@return A const reference to the object at the top of the deque
    */
    const Item_Type& front() const;

    /** Returns a reference to the object at the back of the deque 
	without removing it.
	@return A referenct to the object at the back of the deque
    */
    Item_Type& back();

    /** Returns a const reference to the object at the at the 
	back of the deque without removing it.
	@return A const reference to the object at the top of the deque
    */
    const Item_Type& back() const;

    /** Removes the front item from the deque
     */
    void pop_front();

    /** Removes the back item from the deque
     */
    void pop_back();

    /** Determine if the deque is empty */
    bool empty() const;

    /** Determine the size of the deque */
    size_t size() const;

    /** Return a reference to an item referenced by an index
	@param i the index
	@return a reference to deque[i]
    */
    Item_Type& operator[](int i);

    /** Return a const reference to an item referenced by an index
	@param i the index
	@return a reference to deque[i]
    */
    const Item_Type& operator[](int i) const;

    private:

    // Data fields
    /** The size of the data blocks */
    static const int BLOCK_SIZE = 5;
    /** The index of the first item in the first data block */
    int offset;
    /** The number of items in the deque */
    int num_items;
    /** Circular array of pointers to data blocks */
    carray<Item_Type*> the_data;
  }; // End class deque

  /** Implementation of the member functions of the deque */
  
  /** Construct an empty deque */
  template<typename Item_Type> 
    deque<Item_Type>::deque() {
    //offset = BLOCK_SIZE / 2;
		offset = 2;
    num_items = 0;
    the_data.push_back(new Item_Type[BLOCK_SIZE]);
  }
  
/** Pushes an item onto the back of the deque.
    @param item The item to be inserted
*/
template<typename Item_Type>
  void deque<Item_Type>::push_back(const Item_Type& item) {
    int capacity = the_data.size() * BLOCK_SIZE;
    if ((num_items + offset) == capacity) {
      the_data.push_back(new Item_Type[BLOCK_SIZE]);
    }
    num_items++;
    (*this)[num_items - 1] = item;
}

  /** Pushes an item onto the front of the deque
      @param item The item to be inserted
  */
  template<typename Item_Type>
    void deque<Item_Type>::push_front(const Item_Type& item) {
    if (offset == 0) {
      the_data.push_front(new Item_Type[BLOCK_SIZE]);
      offset = BLOCK_SIZE;
    }
    offset--;
    num_items++;
    (*this)[0] = item;
  }
 
  /** Returns a reference to the object at the front of the deque 
      without removing it.
      @return A referenct to the object at the front of the deque
  */
  template<typename Item_Type>
    Item_Type& deque<Item_Type>::front() {
    return (*this)[0];
  }
    
  /** Returns a const reference to the object at the at the 
      front of the deque without removing it.
      @return A const reference to the object at the top of the deque
  */
  template<typename Item_Type>
    const Item_Type& deque<Item_Type>::front() const {
    return (*this)[0];
  }
  
  /** Returns a reference to the object at the back of the deque 
      without removing it.
      @return A referenct to the object at the back of the deque
  */
  template<typename Item_Type>
    Item_Type& deque<Item_Type>::back() {
    return (*this)[num_items-1];
  }
  
  /** Returns a const reference to the object at the at the 
      back of the deque without removing it.
      @return A const reference to the object at the top of the deque
  */
  template<typename Item_Type>
    const Item_Type& deque<Item_Type>::back() const {
    return (*this)[num_items-1];
  }
  
/** Removes the front item from the deque. */
template<typename Item_Type>
  void deque<Item_Type>::pop_front() {
    offset++;
    if (offset == BLOCK_SIZE) {
      delete[] the_data.front();
      the_data.pop_front();
      offset = 0;
    }
    num_items--;
}
  
  /** Removes the back item from the deque
   */
  template<typename Item_Type>
    void deque<Item_Type>::pop_back() {
    num_items--;
    if ((offset + num_items) % BLOCK_SIZE == 0) {
      delete[] the_data.back();
      the_data.pop_back();
    }
  }
    
  /** Determine if the deque is empty */
  template<typename Item_Type>
    bool deque<Item_Type>::empty() const {
    return num_items == 0;
  }
  
  /** Determine the size of the deque */
  template<typename Item_Type>
    size_t deque<Item_Type>::size() const {
    return num_items;
  }
  
/** Returns a reference to an item referenced by an index.
    @param i the index
    @return A reference to deque[i]
*/
template<typename Item_Type>
  Item_Type& deque<Item_Type>::operator[](int i) {
    if (i < 0 || i >= num_items)
      throw std::out_of_range("Invalid index to deque::operator[]");
    int block_index = (offset + i) / BLOCK_SIZE;
    int data_index = (offset + i) % BLOCK_SIZE;
    return the_data[block_index][data_index];
}

  /** Return a const reference to an item referenced by an index
      @param i the index
      @return a reference to deque[i]
  */
  template<typename Item_Type>
    const Item_Type& deque<Item_Type>::operator[](int i) const {
    if (i < 0 || i >= num_items)
      throw std::out_of_range("Invalid index to deque::operator[]");
    int block_index = (offset + i) / BLOCK_SIZE;
    int data_index = (offset + i) % BLOCK_SIZE;
    return the_data[block_index][data_index];
  }
  
} // End namespace KW
  
#endif
