#include "deque.h"
#include "gtest/gtest.h"

class DequeTest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	DequeTest() {
		// You can do set-up work for each test here.
	}

	virtual ~DequeTest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
		array2.push_back('a');
		array2.push_back('b');
		array2.push_back('c');
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case.
	Deque<int> array1;
	Deque<char> array2 = Deque<char>(4);
};

TEST_F(DequeTest, SizeNominal) 
{
	EXPECT_EQ(0, array1.size());
	EXPECT_EQ(3, array2.size());
}

TEST_F(DequeTest, SizeBoundary) 
{
	// check whether the deque array can resize
	array2.push_back('d');
	EXPECT_EQ(4, array2.size());
	array2.push_back('e');
	EXPECT_EQ(5, array2.size());
	
	array1.push_back(1);
	array1.push_back(2);
	EXPECT_EQ(2, array1.size());
}

TEST_F(DequeTest, EmptyNominal)
{
	EXPECT_EQ(true, array1.empty());
	EXPECT_EQ(false, array2.empty());
}

TEST_F(DequeTest, EmptyBoundary)
{
	// check whether the deque array will be empty when pop all 
	// elements
	array2.pop_back();
	array2.pop_back();
	array2.pop_back();
	EXPECT_EQ(true, array2.empty());
}

TEST_F(DequeTest, IndexOperatorNominal)
{
	EXPECT_EQ('a', array2[0]);
	EXPECT_EQ('b', array2[1]);
	EXPECT_EQ('c', array2[2]);

	array2[0] = 'd';
	array2[1] = 'e';
	array2[2] = 'f';
	EXPECT_EQ('d', array2[0]);
	EXPECT_EQ('e', array2[1]);
	EXPECT_EQ('f', array2[2]);
}

TEST_F(DequeTest, IndexOperatorNonNominal)
{
	ASSERT_THROW(array2[-1], std::range_error);
	ASSERT_THROW(array2[3], std::range_error);
	ASSERT_THROW(array1[5], std::range_error);
}

TEST_F(DequeTest, PushBackNominal)
{
	array1.push_back(0);
	array1.push_back(1);
	array1.push_back(2);

	EXPECT_EQ(0, array1[0]);
	EXPECT_EQ(1, array1[1]);
	EXPECT_EQ(2, array1[2]);
	EXPECT_EQ(3, array1.size());

	array2.push_back('a');
	array2.push_back('b');
	EXPECT_EQ('a', array2[3]);
	EXPECT_EQ('b', array2[4]);
	EXPECT_EQ(5, array2.size());
}

TEST_F(DequeTest, PushFrontNominal)
{
	array1.push_front(0);
	EXPECT_EQ(0, array1[0]);
	array1.push_front(1);
	array1.push_front(2);
	EXPECT_EQ(2, array1[0]);
	EXPECT_EQ(1, array1[1]);
	EXPECT_EQ(0, array1[2]);
	EXPECT_EQ(3, array1.size());
}

TEST_F(DequeTest, PopBackNominal)
{
	array1.push_back(0);
	array1.push_back(1);
	array1.push_back(2);
	array1.pop_back();
	array1.pop_back();
	EXPECT_EQ(0, array1[0]);
	EXPECT_EQ(1, array1.size());	
}

TEST_F(DequeTest, PopFrontNominal)
{
	array2.pop_front();
	EXPECT_EQ('b', array2[0]);
	array2.pop_front();
	EXPECT_EQ('c', array2[0]);
	array2.pop_front();
	EXPECT_EQ(true, array2.empty());
}
