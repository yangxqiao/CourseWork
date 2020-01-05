#include "stack.h"
#include "gtest/gtest.h"

class StackTest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	StackTest() {
		// You can do set-up work for each test here.
	}

	virtual ~StackTest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
		array2.push('a');
		array2.push('b');
		array2.push('c');
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
	Stack<int> array1;
	Stack<char> array2;
};

TEST_F(StackTest, SizeNominal) 
{
	EXPECT_EQ(0, array1.size());
	EXPECT_EQ(3, array2.size());
}

TEST_F(StackTest, SizeBoundary) 
{
	array2.push('d');
	EXPECT_EQ(4, array2.size());
	array2.push('e');
	EXPECT_EQ(5, array2.size());
	
	array1.push(1);
	array1.push(2);
	EXPECT_EQ(2, array1.size());
}

TEST_F(StackTest, EmptyNominal)
{
	EXPECT_EQ(true, array1.empty());
	EXPECT_EQ(false, array2.empty());
}

TEST_F(StackTest, EmptyBoundary)
{
	// check whether the deque array will be empty when pop all 
	// elements
	array2.pop();
	array2.pop();
	array2.pop();
	EXPECT_EQ(true, array2.empty());
}

TEST_F(StackTest, PopNominal)
{
	array2.pop();
	EXPECT_EQ('b', array2.top());
	array2.pop();
	EXPECT_EQ(1, array2.size());
	EXPECT_EQ('a', array2.top());
}

TEST_F(StackTest, PopNonNominal)
{
	ASSERT_THROW(array1.pop(), std::underflow_error);
}

TEST_F(StackTest, PushNominal)
{
	array1.push(0);
	EXPECT_EQ(0, array1.top());
	array1.push(1);
	EXPECT_EQ(1, array1.top());
	array1.push(2);
	EXPECT_EQ(2, array1.top());
}

TEST_F(StackTest, TopNonNominal)
{
	ASSERT_THROW(array1.top(), std::underflow_error);
}