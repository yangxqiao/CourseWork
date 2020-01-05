#ifndef DEQUE_H
#define DEQUE_H
#include <stdexcept>

/**
 * Implements a templated, array-based, 
 * double-ended queue.
 *
 * The Deque should allow for amortized O(1) 
 * insertion and removal from either end. 
 * It should dynamically resize, when it becomes
 * full, but never needs to shrink.  
 *
 * It should use a circular buffer approach
 * by tracking the "front" and "back" location.
 *
 */
template <typename T>
class Deque
{
 public:
  /* START - DO NOT CHANGE ANY OF THESE LINES */
  /**
   *  Default constructor 
   *   Create an array of size 1 by default
   */
  Deque();

  /**
   *  Default constructor 
   *   Create an array of the given capacity.
   */
  Deque(size_t capacity);

  /**
   *  Destructor
   */
  ~Deque();

  /**
   *  Returns the number of elements in the Deque. 
   *   - Must run in O(1)
   */
  size_t size() const;

  /**
   *  returns true if the deque is empty
   *   - Must run in O(1)
   */
  bool empty() const;

  /**
   *  returns  the i-th element from the front
   *   - Must run in O(1)
   *   - Must throw std::range_error if i is
   *      an invalid location
   */
  T& operator[](size_t i);

  /**
   *  returns  the i-th element from the front
   *   - Must run in O(1)
   *   - Must throw std::range_error if i is
   *      an invalid location
   */
  T const & operator[](size_t i) const;

  /**
   *  Inserts a new item at the back of the
   *  Deque
   *   - Must run in amortized O(1)
   */
  void push_back(const T& item);

  /**
   *  Inserts a new item at the front of the
   *  Deque
   *   - Must run in amortized O(1)
   */
  void push_front(const T& item);

  /**
   *  Removes the back item from the Deque
   *   - Must run in amortized O(1)
   *   - Simply return if the deque is empty
   */
  void pop_back();

  /**
   *  Removes the front item from the Deque
   *   - Must run in amortized O(1)
   *   - Simply return if the deque is empty
   */
  void pop_front();
  /* END - DO NOT CHANGE ANY OF THESE LINES */
 private:
  /* Add data members and private helper 
   * functions below 
   */
  T* array;
  int front;
  int back;
  size_t size_;
  size_t capacity;
  
};


/**
 *  Default constructor 
 *   Create an array of size 1 by default
 */
template <typename T>
Deque<T>::Deque()
{
  this->array = new T[1];
  this->front = 0;
  this->back = 0;
  this->size_ = 0;
  this->capacity = 1;
}

/**
 *  Default constructor 
 *   Create an array of the given capacity.
 */
template <typename T>
Deque<T>::Deque(size_t capacity)
{
  if(capacity < 1)
  {
    throw std::range_error("Invalid capacity");
  }
  else
  {
    this->array = new T[capacity];
    this->front = 0;
    this->back = 0;
    this->size_ = 0;
    this->capacity = capacity;   
  }
}

/**
 *  Destructor
 */
template <typename T>
Deque<T>::~Deque()
{
  delete [] this->array;
}

/**
 *  Returns the number of elements in the Deque. 
 *   - Must run in O(1)
 */
template <typename T>
size_t Deque<T>::size() const
{
  return this->size_;
}

/**
 *  returns true if the deque is empty
 *   - Must run in O(1)
 */
template <typename T>
bool Deque<T>::empty() const
{
  if(this->size_ == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/**
 *  returns  the i-th element from the front
 *   - Must run in O(1)
 *   - Must throw std::range_error if i is
 *      an invalid location
 */
template <typename T>
T& Deque<T>::operator[](size_t i)
{
  if(i >= this->size_)
  {
    throw std::range_error("Invalid index");
  }
  else
  {
    size_t real_idx = (this->front + i + this->capacity) % this->capacity;
    return this->array[real_idx];
  }
}

/**
 *  returns  the i-th element from the front
 *   - Must run in O(1)
 *   - Must throw std::range_error if i is
 *      an invalid location
 */
template <typename T>
T const & Deque<T>::operator[](size_t i) const
{
  if(i >= this->size_)
  {
    throw std::range_error("Invalid index");
  }
  else
  {
    size_t real_idx = (this->front + i + this->capacity) % this->capacity;
    return this->array[real_idx];
  }
}

/**
 *  Inserts a new item at the back of the
 *  Deque
 *   - Must run in amortized O(1)
 */
template <typename T>
void Deque<T>::push_back(const T& item)
{
  if(this->size_ == this->capacity)
  {
    size_t new_capacity = this->capacity * 2;
    T* new_array = new T[new_capacity];
    for(int i = this->front; i < this->back; i++)
    {
      size_t real_idx_new_array = (i+new_capacity)%new_capacity;
      size_t real_idx_old_array = (i+this->capacity)%this->capacity;
      new_array[real_idx_new_array] = this->array[real_idx_old_array];
    }
    T* temp = this->array;
    this->array = new_array;
    delete [] temp;
    this->capacity = new_capacity;
  }
  
  this->array[back] = item;
  this->back = this->back + 1;
  this->size_ = this->size_ + 1;
}

/**
 *  Inserts a new item at the front of the
 *  Deque
 *   - Must run in amortized O(1)
 */
template <typename T>
void Deque<T>::push_front(const T& item)
{
  if(this->size_ == this->capacity)
  {
    size_t new_capacity = this->capacity * 2;
    T* new_array = new T[new_capacity];
    for(int i = this->front; i < this->back; i++)
    {
      size_t real_idx_new_array = (i+new_capacity)%new_capacity;
      size_t real_idx_old_array = (i+this->capacity)%this->capacity;
      new_array[real_idx_new_array] = this->array[real_idx_old_array];
    }

    T* temp = this->array;
    this->array = new_array;
    delete [] temp;
    this->capacity = new_capacity;
  }

  this->front = this->front - 1;
  size_t real_idx = (this->front+this->capacity)%this->capacity;
  this->array[real_idx] = item;
  this->size_++;

}

/**
 *  Removes the back item from the Deque
 *   - Must run in amortized O(1)
 *   - Simply return if the deque is empty
 */
template <typename T>
void Deque<T>::pop_back()
{
  if(this->size_ == 0)
  {
    return;
  }
  else
  {
    this->back--;
    this->size_--;
  }
}

/**
 *  Removes the front item from the Deque
 *   - Must run in amortized O(1)
 *   - Simply return if the deque is empty
 */
template <typename T>
void Deque<T>::pop_front()
{
  if(this->size_ == 0)
  {
    return;
  }
  else
  {
    this->front++;
    this->size_--;
  }
}


#endif
