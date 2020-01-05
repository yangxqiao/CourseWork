#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
 public:
  /// Constructs an m-ary heap for any m >= 2
  Heap(int m, PComparator c = PComparator());

  /// Destructor as needed
  ~Heap();

  /// Adds an item
  void push(const T& item);

  /// returns the element at the top of the heap 
  ///  max (if max-heap) or min (if min-heap)
  T const & top() const;

  /// Removes the top element
  void pop();

  /// returns true if the heap is empty
  bool empty() const;

 private:
  /// Add whatever helper functions and data members you need below
  int m_nary;
  std::vector<T> my_heap;
  PComparator c_;

  void heapify(size_t loc);
  void trickleUp(size_t loc);
};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::logic_error("can't top an empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else{
    return this->my_heap[0];
  }
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::logic_error("can't pop an empty heap");
  }
  else{
    this->my_heap[0] = this->my_heap.back();
    this->my_heap.pop_back();
    this->heapify(0);
  }
}


template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  this->m_nary = m;
  this->c_ = c;
}


template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}


template <typename T, typename PComparator >
void Heap<T, PComparator>::heapify(size_t loc)
{
  unsigned int effsize = this->my_heap.size();
  if(loc*this->m_nary+2 > effsize)
  {
    return;
  }
  unsigned int first_child = (loc)*this->m_nary+1;
  unsigned int better_child = first_child;
  for(int i = 1; i < this->m_nary; i++)
  {
    unsigned int curr_child = first_child+i;
    if(curr_child < effsize)
    {
      if(this->c_(this->my_heap[curr_child], this->my_heap[better_child]))
      {
        better_child = curr_child;
      }
    }
  }
  
  if(this->c_(this->my_heap[better_child], this->my_heap[loc]))
  {
    std::swap(this->my_heap[better_child], this->my_heap[loc]);
    this->heapify(better_child);
  }
}


/// returns true if the heap is empty
template <typename T, typename PComparator >
bool Heap<T, PComparator>::empty() const{
  unsigned int size = my_heap.size();
  if(size == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}


/// Adds an item
template <typename T, typename PComparator >
void Heap<T, PComparator>::push(const T& item){
  this->my_heap.push_back(item);
  int index = this->my_heap.size()-1;
  this->trickleUp(index);
}


template <typename T, typename PComparator >
void Heap<T, PComparator>::trickleUp(size_t loc)
{
  if(loc == 0)
  {
    return;
  }
  unsigned int parent = (loc-1)/this->m_nary;
  while(parent>=0)
  {
    if(this->c_(this->my_heap[loc], this->my_heap[parent]))
    {
      std::swap(this->my_heap[parent], this->my_heap[loc]);
      loc = parent;
      if(loc == 0)
      {
        return;
      }
      parent = (loc-1)/this->m_nary;
    }
    else
    {
      return;
    }
  }
}

#endif

