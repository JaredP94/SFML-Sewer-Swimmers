#include "vector2f.h"
#include "gtest/gtest.h"
#include <iostream>

TEST (Vector2f, DefaultConstructorCorrectlyInitializesDataMember)
{
	Vector2f test_Vector;
	EXPECT_EQ(0.f, test_Vector._x);
	EXPECT_EQ(0.f, test_Vector._y);
}

TEST (Vector2f, ConstructorCorrectlyInitializesDataMemberWithParameters)
{
	Vector2f test_Vector(1.f, 2.f);
	EXPECT_EQ(1.f, test_Vector._x);
	EXPECT_EQ(2.f, test_Vector._y);
}

TEST (Vector2f, ConstructorCorrectlyInitializesDataMemberWithNegativeParameters)
{
	Vector2f test_Vector(-1.f, -2.f);
	EXPECT_EQ(-1.f, test_Vector._x);
	EXPECT_EQ(-2.f, test_Vector._y);
}

TEST(Vector2f, VectorAssignmentWorksCorrectly)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2 = test_Vector1;
	EXPECT_EQ(1.f, test_Vector2._x);
	EXPECT_EQ(2.f, test_Vector2._y);
}

TEST(Vector2f, HasUnitVectorCreationFunctionality)
{
	float _x = 1.f;
	float _y = 2.f;
	auto magnitude = sqrtf(_x*_x+ _y*_y);
	Vector2f test_Vector(_x, _y);
	test_Vector = test_Vector.unitVector();
	EXPECT_EQ(Vector2f(_x/magnitude, _y/magnitude), test_Vector);
}

TEST(Vector2f, CorrectlyReturnsTheDistanceBetweenTwoVectors)
{
	Vector2f test_Vector1(3.f, 4.f);
	Vector2f test_Vector2(1.f, 2.f);
	EXPECT_EQ(sqrtf(8), test_Vector1.vectorDistance(test_Vector1, test_Vector2));
	EXPECT_EQ(sqrtf(8), test_Vector1.vectorDistance(test_Vector2, test_Vector1));
	EXPECT_EQ(sqrtf(8), test_Vector2.vectorDistance(test_Vector1, test_Vector2));
	EXPECT_EQ(sqrtf(8), test_Vector2.vectorDistance(test_Vector2, test_Vector1));
}

TEST(Vector2f, canIdentifyIdenticalVectorsUsingEquivalentOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2 = test_Vector1;
	EXPECT_EQ(test_Vector1,test_Vector2);
}

TEST(Vector2f, canIdentifyNonIdenticalVectorsUsingEquivalentToOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2(2.f, 3.f);
	EXPECT_FALSE(test_Vector1 == test_Vector2);
}

TEST(Vector2f, canIdentifyIdenticalVectorsUsingNotEquivalentToOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2 = test_Vector1;
	EXPECT_FALSE(test_Vector1 != test_Vector2);
}

TEST(Vector2f, canIdentifyNonIdenticalVectorsUsingNotEquivalentToOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2(3.f, 4.f);
	EXPECT_TRUE(test_Vector1 != test_Vector2);
}

TEST(Vector2f, canAddTwoVectorsUsingAdditionOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2 = test_Vector1;
	Vector2f test_Vector3 = test_Vector1 + test_Vector2;
	EXPECT_EQ(Vector2f(2.f,4.f),test_Vector3);
}

TEST(Vector2f, canSubtractTwoVectorsUsingSubtractionOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2(3.f,4.f);
	Vector2f test_Vector3 = test_Vector1 - test_Vector2;
	EXPECT_EQ(Vector2f(-2.f,-2.f),test_Vector3);
}

TEST(Vector2f, canMultiplyTwoVectorsUsingMultiplicationOperator)
{
	Vector2f vectorTest1(1.f, 2.f);
	Vector2f vectorTest2(3.f,4.f);
	EXPECT_EQ(11.f,vectorTest1 * vectorTest2);
}

TEST(Vector2f, canPerformVectorScalarAdditionUsingAdditionOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2 = test_Vector1 + 3.f;
	EXPECT_EQ(Vector2f(4.f,5.f),test_Vector2);
}

TEST(Vector2f, canPerformVectorScalarSubtractionUsingSubtractionOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2 = test_Vector1 - 3.f;
	EXPECT_EQ(Vector2f(-2.f,-1.f),test_Vector2);
}

TEST(Vector2f, canPerformVectorScalarMultiplicationUsingMultiplicationOperator)
{
	Vector2f test_Vector1(1.f,2.f);
	Vector2f test_Vector2 = test_Vector1 * 3.f;
	EXPECT_EQ(Vector2f(3.f,6.f),test_Vector2);
}

TEST(Vector2f, canPerformVectorScalarDivisionUsingDivisionOperator)
{
	Vector2f test_Vector1(2.f,4.f);
	Vector2f test_Vector2 = test_Vector1 / 2.f;
	EXPECT_EQ(Vector2f(1.f,2.f),test_Vector2);
}

TEST(Vector2f, canAddTwoVectorsUsingPlusEqualToOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2(3.f,4.f);
	EXPECT_EQ(Vector2f(4.f,6.f),test_Vector1 += test_Vector2);
}

TEST(Vector2f, canSubtractTwoVectorsUsingMinusEqualToOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2(3.f, 4.f);
	EXPECT_EQ(Vector2f(-2.f,-2.f),test_Vector1 -= test_Vector2);
}

TEST(Vector2f, canMultiplyTwoVectorsUsingMultiplyEqualToOperator)
{
	Vector2f test_Vector1(1.f, 2.f);
	Vector2f test_Vector2(3.f,4.f);
	EXPECT_EQ(Vector2f(3.f,8.f),test_Vector1 *= test_Vector2);
}

TEST(Vector2f, canPerformVectorScalarAdditionUsingPlusEqualToOperator)
{
	Vector2f test_Vector(1.f, 2.f);
	EXPECT_EQ(Vector2f(4.f,5.f),test_Vector += 3.f);
}

TEST(Vector2f, canPerformVectorScalarSubtractionUsingMinusEqualToOperator)
{
	Vector2f test_Vector(1.f, 2.f);
	EXPECT_EQ(Vector2f(-2.f,-1.f),test_Vector -= 3.f);
}

TEST(Vector2f, canPerformVectorScalarMultiplicationUsingMultiplyEqualToOperator)
{
	Vector2f test_Vector(1.f,2.f);
	EXPECT_EQ(Vector2f(3.f,6.f),test_Vector *= 3.f);
}

TEST(Vector2f, canPerformVectorScalarDivisionUsingDivideEqualToOperator)
{
	Vector2f test_Vector(2.f,4.f);
	EXPECT_EQ(Vector2f(1.f,2.f),test_Vector /= 2.f);
}