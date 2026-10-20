#include <gtest/gtest.h>
#include "Task1.h"
#include "Task2.h"
#include "Matrix.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

//Task1

TEST(Task1Test, ReplacesMinAbsInEachColumn)
{
    Matrix<int> m(3, 3);
    m(0,0)= 5; m(0,1)=-4; m(0,2)= 7;
    m(1,0)=-2; m(1,1)= 1; m(1,2)=-8;
    m(2,0)= 3; m(2,1)= 2; m(2,2)= 3;

    Task1 task(m);
    task.solve();

    const Matrix<int>& r = task.getMatrix();
    EXPECT_EQ(r(1,0), 0);
    EXPECT_EQ(r(1,1), 0);
    EXPECT_EQ(r(2,2), 0);
    EXPECT_EQ(r(0,0), 5);
    EXPECT_EQ(r(2,0), 3);
}

TEST(Task1Test, SingleColumn)
{
    Matrix<int> m(2, 1);
    m(0,0) = 10;
    m(1,0) = -3;

    Task1 task(m);
    task.solve();
    EXPECT_EQ(task.getMatrix()(1,0), 0);
    EXPECT_EQ(task.getMatrix()(0,0), 10);
}

//Task2

TEST(Task2Test, RemovesColumnsWhereFirstGreaterThanLast)
{
    Matrix<int> m(3, 4);
    m(0,0)=5; m(0,1)=1; m(0,2)=7; m(0,3)=9;
    m(1,0)=0; m(1,1)=0; m(1,2)=0; m(1,3)=0;
    m(2,0)=2; m(2,1)=4; m(2,2)=7; m(2,3)=1;

    Task2 task(m);
    task.solve();

    const Matrix<int>& r = task.getMatrix();
    ASSERT_EQ(r.getCols(), 2);
    EXPECT_EQ(r(0,0), 1);
    EXPECT_EQ(r(0,1), 7);
    EXPECT_EQ(r(2,0), 4);
    EXPECT_EQ(r(2,1), 7);
}

TEST(Task2Test, NoRemoval)
{
    Matrix<int> m(2, 2);
    m(0,0)=1; m(0,1)=2;
    m(1,0)=5; m(1,1)=5;

    Task2 task(m);
    task.solve();
    EXPECT_EQ(task.getMatrix().getCols(), 2);
}

// Matrix

TEST(MatrixTest, AssignmentAndIndex)
{
    Matrix<int> a(2, 2);
    a(0,0)=1; a(0,1)=2; a(1,0)=3; a(1,1)=4;

    Matrix<int> b;
    b = a;
    EXPECT_EQ(b(1,1), 4);

    b(0,0) = 100;
    EXPECT_EQ(a(0,0), 1); 
}

TEST(MatrixTest, ShiftLeftRight)
{
    Matrix<int> m(3, 1);
    m(0,0)=1; m(1,0)=2; m(2,0)=3;

    m << 1;
    EXPECT_EQ(m(0,0), 2);
    EXPECT_EQ(m(2,0), 1);

    m >> 1;
    EXPECT_EQ(m(0,0), 1);
    EXPECT_EQ(m(2,0), 3);
}

TEST(MatrixTest, GeneratorFill)
{
    ConstantGenerator gen(42);
    Matrix<int> m(2, 3);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            m(i, j) = gen.generate();

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            EXPECT_EQ(m(i, j), 42);
}
