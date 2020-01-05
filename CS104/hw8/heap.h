#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>
template <
         typename T,
         typename KComparator = std::equal_to<T>,
         typename PComparator = std::less<T>,
         typename Hasher = std::hash<T> 
         >
class Heap
{
public:
    /// Constructs an m-ary heap. M should be >= 2
    Heap(int m = 2,
         const PComparator& c = PComparator(),
         const Hasher& hash = Hasher(),
         const KComparator& kcomp = KComparator()  );

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

    /// decreaseKey - Finds key matching old object &
    /// updates its location in the heap based on the new value
    void decreaseKey(const T& old, const T& newVal);

 private:
    /// Add whatever helper functions and data members you need below
    size_t heapify(size_t loc);
    size_t trickleUp(size_t loc);

 private:
   /// Data members - These should be sufficient
    std::vector< T > store_;
    int m_;
    PComparator c_;
    std::unordered_map<T, size_t, Hasher, KComparator> keyToLocation_;

};

// Complete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
Heap<T,KComparator,PComparator,Hasher>::Heap(
    int m,
    const PComparator& c,
    const Hasher& hash,
    const KComparator& kcomp ) :

    store_(),
    m_(m),
    c_(c),
    keyToLocation_(100, hash, kcomp)
{

}

// Complete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
Heap<T,KComparator,PComparator,Hasher>::~Heap()
{

}

// Incomplete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
void Heap<T,KComparator,PComparator,Hasher>::push( const T& item)
{
    typename std::unordered_map<T, size_t, Hasher, KComparator>::iterator it = keyToLocation_.find(item);
    if(it == keyToLocation_.end())
    {
        store_.push_back(item);
        int index = store_.size()-1;
        size_t position = trickleUp(index);
        keyToLocation_.insert(std::make_pair(item, position));
    }
}

// Incomplete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
void Heap<T,KComparator,PComparator,Hasher>::decreaseKey(const T& old, const T& newVal)
{
    if(c_(newVal, old))
    {
        typename std::unordered_map<T, size_t, Hasher, KComparator>::iterator it = keyToLocation_.find(old);
        if(it != keyToLocation_.end())
        {
            size_t current_pos = it->second;
            store_[current_pos] = newVal;
            size_t position = trickleUp(current_pos);
            keyToLocation_.erase(old);
            keyToLocation_.insert(std::make_pair(newVal, position));
        }
    }
}

// Complete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
T const & Heap<T,KComparator,PComparator,Hasher>::top() const
{
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if(empty()) {
        throw std::logic_error("can't top an empty heap");
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return store_[0];
}

// Incomplete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
void Heap<T,KComparator,PComparator,Hasher>::pop()
{
    if(empty()) {
        throw std::logic_error("can't pop an empty heap");
    }
    else if(store_.size() == 1){
        keyToLocation_.erase(store_[0]);
        store_.pop_back();
    }
    else
    {
        keyToLocation_.erase(store_[0]);
        store_[0] = store_.back();
        typename std::unordered_map<T, size_t, Hasher, KComparator>::iterator it = keyToLocation_.find(store_[0]);
        store_.pop_back();
        size_t position = heapify(0);
        it->second = position;
    }
}

/// Complete!
template <typename T, typename KComparator, typename PComparator, typename Hasher >
bool Heap<T,KComparator,PComparator,Hasher>::empty() const
{
    return store_.empty();
}


template <typename T, typename KComparator, typename PComparator, typename Hasher >
size_t Heap<T,KComparator,PComparator,Hasher>::heapify(size_t loc)
{
    unsigned int effsize = store_.size();
    if(loc*this->m_+2 > effsize)
    {
        return loc;
    }
    else
    {
        unsigned int first_child = (loc)*this->m_+1;
        unsigned int better_child = first_child;
        for(int i = 1; i < this->m_; i++)
        {
            unsigned int curr_child = first_child+i;
            if(curr_child < effsize)
            {
                if(this->c_(store_[curr_child], store_[better_child]))
                {
                    better_child = curr_child;
                }
            }
        }
  
        if(this->c_(store_[better_child], store_[loc]))
        {
            std::swap(store_[better_child], store_[loc]);
            this->heapify(better_child);
        }

        return loc;
    }
}


template <typename T, typename KComparator, typename PComparator, typename Hasher >
size_t Heap<T,KComparator,PComparator,Hasher>::trickleUp(size_t loc)
{
    if(loc == 0)
    {
        return loc;
    }
    unsigned int parent = (loc-1)/this->m_;
    while(parent>=0)
    {
        if(this->c_(store_[loc], store_[parent]))
        {
            std::swap(store_[parent], store_[loc]);
            loc = parent;
            if(loc == 0)
            {
                return loc;
            }
            parent = (loc-1)/this->m_;
        }
        else
        {
            return loc;
        }
    }
}
#endif

