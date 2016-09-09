#include "vector2f.h"
#include "gtest/gtest.h"
#include <iostream>

TEST (Vector2f, DefaultConstructorCorrectlyInitializesDataMember)
{
	Vector2f testVector;
	
	EXPECT_EQ(0.f, testVector._x);
	EXPECT_EQ(0.f, testVector._y);
}

TEST (Vector2f, ConstructorCorrectlyInitializesDataMemberWithParameters)
{
	Vector2f testVector(1.f, 2.f);
	
	EXPECT_EQ(1.f, testVector._x);
	EXPECT_EQ(2.f, testVector._y);
}

TEST (Vector2f, ConstructorCorrectlyInitializesDataMemberWithNegativeParameters)
{
	float x = -1.f;
	float y = -2.f;
	
	Vector2f testVector(x, y);
	
	EXPECT_EQ(-1.f, testVector._x);
	EXPECT_EQ(-2.f, testVector._y);
}

TEST(Vector2f, VectorAssignmentWorksCorrectly)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2 = testVector1;
	
	EXPECT_EQ(1.f, testVector2._x);
	EXPECT_EQ(2.f, testVector2._y);
}

//========================== Tests for unitVector Functionality =====================================

TEST(Vector2f, HasUnitVectorCreationFunctionality)
{
	float _x = 1.f;
	float _y = 2.f;
	auto magnitude = sqrtf(_x*_x+ _y*_y);
	
	Vector2f testVector(_x, _y);
	testVector = testVector.unitVector();
	
	EXPECT_EQ(Vector2f(_x/magnitude, _y/magnitude), testVector);
}

//========================= Tests for vectorDistance Functionality ==================================

TEST(Vector2f, CorrectlyReturnsTheDistanceBetweenTwoVectors)
{
	Vector2f testVector1(3.f, 4.f);
	Vector2f testVector2(1.f, 2.f);
	
	EXPECT_EQ(sqrtf(8), testVector1.vectorDistance(testVector1, testVector2));
	EXPECT_EQ(sqrtf(8), testVector1.vectorDistance(testVector2, testVector1));
	
	EXPECT_EQ(sqrtf(8), testVector2.vectorDistance(testVector1, testVector2));
	EXPECT_EQ(sqrtf(8), testVector2.vectorDistance(testVector2, testVector1));
}

//========================= Tests for Operator Functionality ==================================

TEST(Vector2f, canIdentifyIdenticalVectorsUsingEquivalentOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2 = testVector1;
	
	EXPECT_TRUE(testVector1 == testVector2);
}

TEST(Vector2f, canIdentifyNonIdenticalVectorsUsingEquivalentToOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2(2.f, 3.f);
	
	EXPECT_FALSE(testVector1 == testVector2);
}

TEST(Vector2f, canIdentifyIdenticalVectorsUsingNotEquivalentToOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2 = testVector1;
	
	EXPECT_FALSE(testVector1 != testVector2);
}

TEST(Vector2f, canIdentifyNonIdenticalVectorsUsingNotEquivalentToOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2(3.f, 4.f);
	
	EXPECT_TRUE(testVector1 != testVector2);
}

TEST(Vector2f, canAddTwoVectorsUsingAdditionOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2 = testVector1;
	Vector2f testVector3 = testVector1 + testVector2;
	EXPECT_EQ(Vector2f(2.f,4.f),testVector3);
}

TEST(Vector2f, canSubtractTwoVectorsUsingSubtractionOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2(3.f,4.f);
	Vector2f testVector3 = testVector1 - testVector2;
	EXPECT_EQ(Vector2f(-2.f,-2.f),testVector3);
}

TEST(Vector2f, canMultiplyTwoVectorsUsingMultiplicationOperator)
{
	Vector2f vectorTest1(1.f, 2.f);
	Vector2f vectorTest2(3.f,4.f);
	EXPECT_EQ(11.f,vectorTest1 * vectorTest2);
}

TEST(Vector2f, canPerformVectorScalarAdditionUsingAdditionOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2 = testVector1 + 3.f;
	EXPECT_EQ(Vector2f(4.f,5.f),testVector2);
}

TEST(Vector2f, canPerformVectorScalarSubtractionUsingSubtractionOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2 = testVector1 - 3.f;
	EXPECT_EQ(Vector2f(-2.f,-1.f),testVector2);
}

TEST(Vector2f, canPerformVectorScalarMultiplicationUsingMultiplicationOperator)
{
	Vector2f testVector1(1.f,2.f);
	Vector2f testVector2 = testVector1 * 3.f;
	EXPECT_EQ(Vector2f(3.f,6.f),testVector2);
}

TEST(Vector2f, canPerformVectorScalarDivisionUsingDivisionOperator)
{
	Vector2f testVector1(2.f,4.f);
	Vector2f testVector2 = testVector1 / 2.f;
	EXPECT_EQ(Vector2f(1.f,2.f),testVector2);
}

TEST(Vector2f, canAddTwoVectorsUsingPlusEqualToOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2(3.f,4.f);
	EXPECT_EQ(Vector2f(4.f,6.f),testVector1 += testVector2);
	
}

TEST(Vector2f, canSubtractTwoVectorsUsingMinusEqualToOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2(3.f, 4.f);
	EXPECT_EQ(Vector2f(-2.f,-2.f),testVector1 -= testVector2);
	
}

TEST(Vector2f, canMultiplyTwoVectorsUsingMultiplyEqualToOperator)
{
	Vector2f testVector1(1.f, 2.f);
	Vector2f testVector2(3.f,4.f);
	EXPECT_EQ(Vector2f(3.f,8.f),testVector1 *= testVector2);
}

TEST(Vector2f, canPerformVectorScalarAdditionUsingPlusEqualToOperator)
{
	Vector2f testVector(1.f, 2.f);
	EXPECT_EQ(Vector2f(4.f,5.f),testVector += 3.f);
	
}

TEST(Vector2f, canPerformVectorScalarSubtractionUsingMinusEqualToOperator)
{
	Vector2f testVector(1.f, 2.f);
	EXPECT_EQ(Vector2f(-2.f,-1.f),testVector -= 3.f);
}

TEST(Vector2f, canPerformVectorScalarMultiplicationUsingMultiplyEqualToOperator)
{
	Vector2f testVector(1.f,2.f);
	EXPECT_EQ(Vector2f(3.f,6.f),testVector *= 3.f);
}

TEST(Vector2f, canPerformVectorScalarDivisionUsingDivideEqualToOperator)
{
	Vector2f testVector(2.f,4.f);
	EXPECT_EQ(Vector2f(1.f,2.f),testVector /= 2.f);
}