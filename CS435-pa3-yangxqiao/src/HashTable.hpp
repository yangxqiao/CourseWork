#pragma once
#include <string>
#include <utility>
#include <functional>

template <typename ValueType, 
	typename HashFuncType = std::hash<std::string>>
class HashTable
{
public:
	// Constructs the hash table with the given capacity (size of underlying array)
	HashTable(size_t capacity)
		:mTableData(new std::pair<std::string, ValueType>[capacity])
		,mCapacity(capacity)
		,mSize(0)
	{ }

    // Copy Constructor
    HashTable(const HashTable& rhs)
        :mTableData(new std::pair<std::string, ValueType>[rhs.mCapacity])
        ,mCapacity(rhs.mCapacity)
        ,mSize(rhs.mSize)
    {
        for(unsigned int i = 0; i < mCapacity; i++)
        {
            mTableData[i] = rhs.mTableData[i];
        }
    }

    // Assignment Operator
    HashTable& operator=(const HashTable& rhs)
    {
        if(&rhs != this)
        {
            mCapacity = rhs.mCapacity;
            mSize = rhs.mSize;
            mTableData = new std::pair<std::string, ValueType>[mCapacity];
            for(unsigned int i = 0; i < mCapacity; i++)
            {
                mTableData[i] = rhs.mTableData[i];
            }
        }
        return *this;
    }

    // Move Copy Constructor
    HashTable(HashTable&& rhs)
        :mTableData(std::move(rhs.mTableData))
        ,mCapacity(std::move(rhs.mCapacity))
        ,mSize(std::move(rhs.mSize))
    {
        rhs.mTableData = nullptr;
        rhs.mCapacity = 0;
        rhs.mSize = 0;
    }

    // Move Assignment Operator
    HashTable& operator=(HashTable&& rhs)
    {
        if(&rhs != this)
        {
            mTableData = std::move(rhs.mTableData);
            mCapacity = std::move(rhs.mCapacity);
            mSize = std::move(rhs.mSize);
            
            rhs.mTableData = nullptr;
            rhs.mCapacity = 0;
            rhs.mSize = 0;
        }
        return *this;
    }
    
    // Destructor
    ~HashTable()
    {
        mCapacity = 0;
        mSize = 0;
        delete [] mTableData;
        mTableData = nullptr;
    }

	// Returns overall capacity of hash table (size of underlying array)
	size_t Capacity() const
	{
		return mCapacity;
	}

	// Returns the number of elements currently inserted in the hash table
	size_t Size() const
	{
		return mSize;
	}

	// Tries to insert (key, value) into hash table
	// Returns true if insert succeeds, false if not
	bool Insert(const std::string& key, const ValueType& value)
	{
        unsigned int index = mHashFunc(key) % mCapacity;
        unsigned int originalIndex = mHashFunc(key) % mCapacity;
        while(!mTableData[index].first.empty())
        {
            index++;
            if(index == mCapacity)
            {
                index = 0;
            }
            if(index == originalIndex)
            {
                return false;
            }
        }
        mTableData[index] = {key, value};
        mSize++;
        return true;
	}

	// Returns pointer to value for given key, or nullptr
	// if not in hash table
	ValueType* Find(const std::string& key) const
	{
        unsigned int index = mHashFunc(key) % mCapacity;
        unsigned int originalIndex = mHashFunc(key) % mCapacity;
        while(!mTableData[index].first.empty())
        {
            if(mTableData[index].first == key)
            {
                return &(mTableData[index].second);
            }
            index++;
            if(index == mCapacity)
            {
                index = 0;
            }
            if(index == originalIndex)
            {
                return nullptr;
            }
        }
		return nullptr;
	}

	// Executes provided lambda expression on each element inserted into the table
	void ForEach(std::function<void(const std::string& key, ValueType& value)> func)
	{
        for(unsigned int i = 0; i < mCapacity; ++i)
        {
            if(!mTableData[i].first.empty())
            {
                func(mTableData[i].first, mTableData[i].second);
            }
        }
	}

	// Gets a const pointer to underlying data (for testing)
	const std::pair<std::string, ValueType>* Data() const
	{
		return mTableData;
	}
private:
	// NOTE: you should not need any more member data!
	
	// Underlying hash table array
	std::pair<std::string, ValueType>* mTableData;
	// Allocated capacity of hash table array
	size_t mCapacity;
	// Number of elements in HashTable
	size_t mSize;
	// Hash function
	HashFuncType mHashFunc;
};
