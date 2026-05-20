#include <gtest/gtest.h>
#include <sstream>
#include "Point.h"
#include "Vector2D.h"

using namespace VectorLib;

TEST(PointTest, DefaultConstructor) {
    Point p;
    EXPECT_DOUBLE_EQ(p.getX(), 0.0);
    EXPECT_DOUBLE_EQ(p.getY(), 0.0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point p(3.5, 7.2);
    EXPECT_DOUBLE_EQ(p.getX(), 3.5);
    EXPECT_DOUBLE_EQ(p.getY(), 7.2);
}

TEST(PointTest, SetX) {
    Point p;
    p.setX(5.0);
    EXPECT_DOUBLE_EQ(p.getX(), 5.0);
}

TEST(PointTest, SetY) {
    Point p;
    p.setY(10.0);
    EXPECT_DOUBLE_EQ(p.getY(), 10.0);
}

TEST(PointTest, EqualityOperator) {
    Point p1(2, 3);
    Point p2(2, 3);
    Point p3(2, 4);
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointTest, InequalityOperator) {
    Point p1(2, 3);
    Point p2(2, 4);
    EXPECT_TRUE(p1 != p2);
    EXPECT_FALSE(p1 != Point(2, 3));
}

TEST(PointTest, AdditionWithScalar) {
    Point p(2, 3);
    Point result = p + 1.5;
    EXPECT_DOUBLE_EQ(result.getX(), 3.5);
    EXPECT_DOUBLE_EQ(result.getY(), 4.5);
}

TEST(PointTest, SubtractionWithScalar) {
    Point p(5, 7);
    Point result = p - 2.0;
    EXPECT_DOUBLE_EQ(result.getX(), 3.0);
    EXPECT_DOUBLE_EQ(result.getY(), 5.0);
}

TEST(PointTest, AdditionOfPoints) {
    Point p1(2, 3);
    Point p2(4, 5);
    Point result = p1 + p2;
    EXPECT_DOUBLE_EQ(result.getX(), 6.0);
    EXPECT_DOUBLE_EQ(result.getY(), 8.0);
}

TEST(PointTest, SubtractionOfPoints) {
    Point p1(5, 8);
    Point p2(2, 3);
    Point result = p1 - p2;
    EXPECT_DOUBLE_EQ(result.getX(), 3.0);
    EXPECT_DOUBLE_EQ(result.getY(), 5.0);
}

TEST(PointTest, StreamOutput) {
    Point p(2.5, 3.7);
    std::stringstream ss;
    ss << p;
    EXPECT_EQ(ss.str(), "(2.5; 3.7)");
}

TEST(PointTest, StreamInput) {
    std::stringstream ss("4.2 5.8");
    Point p;
    ss >> p;
    EXPECT_DOUBLE_EQ(p.getX(), 4.2);
    EXPECT_DOUBLE_EQ(p.getY(), 5.8);
}

TEST(PointTest, ToString) {
    Point p(1, 2);
    EXPECT_EQ(p.toString(), "(1; 2)");
}

// ==================== Тесты для класса Vector2D ====================

TEST(Vector2DTest, DefaultConstructor) {
    Vector2D v;
    EXPECT_DOUBLE_EQ(v.length(), 0.0);
    EXPECT_DOUBLE_EQ(v.getStart().getX(), 0.0);
    EXPECT_DOUBLE_EQ(v.getStart().getY(), 0.0);
    EXPECT_DOUBLE_EQ(v.getEnd().getX(), 0.0);
    EXPECT_DOUBLE_EQ(v.getEnd().getY(), 0.0);
}

TEST(Vector2DTest, ConstructorWithPoints) {
    Point start(0, 0);
    Point end(3, 4);
    Vector2D v(start, end);
    EXPECT_DOUBLE_EQ(v.length(), 5.0);
    EXPECT_EQ(v.getStart(), start);
    EXPECT_EQ(v.getEnd(), end);
}

TEST(Vector2DTest, ConstructorWithNumbers) {
    Vector2D v(0, 0, 6, 8);
    EXPECT_DOUBLE_EQ(v.length(), 10.0);
}

TEST(Vector2DTest, Length) {
    Vector2D v(0, 0, 1, 1);
    EXPECT_DOUBLE_EQ(v.length(), std::sqrt(2.0));
}

TEST(Vector2DTest, GetCoordinates) {
    Vector2D v(1, 2, 4, 7);
    Point coords = v.getCoordinates();
    EXPECT_DOUBLE_EQ(coords.getX(), 3.0);
    EXPECT_DOUBLE_EQ(coords.getY(), 5.0);
}

TEST(Vector2DTest, EqualityOperator) {
    Vector2D v1(0, 0, 2, 3);
    Vector2D v2(0, 0, 2, 3);
    Vector2D v3(0, 0, 4, 5);
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
}

TEST(Vector2DTest, InequalityOperator) {
    Vector2D v1(0, 0, 2, 3);
    Vector2D v2(0, 0, 4, 5);
    EXPECT_TRUE(v1 != v2);
    EXPECT_FALSE(v1 != Vector2D(0, 0, 2, 3));
}

TEST(Vector2DTest, Addition) {
    Vector2D v1(0, 0, 2, 0);
    Vector2D v2(0, 0, 0, 3);
    Vector2D result = v1 + v2;
    EXPECT_DOUBLE_EQ(result.getCoordinates().getX(), 2.0);
    EXPECT_DOUBLE_EQ(result.getCoordinates().getY(), 3.0);
    EXPECT_DOUBLE_EQ(result.length(), std::sqrt(4.0 + 9.0));
}

TEST(Vector2DTest, Subtraction) {
    Vector2D v1(0, 0, 5, 5);
    Vector2D v2(0, 0, 2, 1);
    Vector2D result = v1 - v2;
    EXPECT_DOUBLE_EQ(result.getCoordinates().getX(), 3.0);
    EXPECT_DOUBLE_EQ(result.getCoordinates().getY(), 4.0);
}

TEST(Vector2DTest, MultiplicationByScalar) {
    Vector2D v(0, 0, 2, 3);
    Vector2D result = v * 2.5;
    EXPECT_DOUBLE_EQ(result.getCoordinates().getX(), 5.0);
    EXPECT_DOUBLE_EQ(result.getCoordinates().getY(), 7.5);
}

TEST(Vector2DTest, AngleBetweenVectors) {
    Vector2D v1(0, 0, 1, 0);
    Vector2D v2(0, 0, 0, 1);
    double angle = Vector::angleBetween(v1, v2);
    EXPECT_NEAR(angle, 3.14159 / 2, 1e-5);
}

TEST(Vector2DTest, ParallelVectorsAngle) {
    Vector2D v1(0, 0, 2, 0);
    Vector2D v2(0, 0, 3, 0);
    double angle = Vector::angleBetween(v1, v2);
    EXPECT_NEAR(angle, 0.0, 1e-9);
}

TEST(Vector2DTest, OppositeVectorsAngle) {
    Vector2D v1(0, 0, 2, 0);
    Vector2D v2(0, 0, -1, 0);
    double angle = Vector::angleBetween(v1, v2);
    EXPECT_NEAR(angle, 3.14159, 1e-5);
}

TEST(Vector2DTest, AngleWithZeroVector) {
    Vector2D v1(0, 0, 2, 0);
    Vector2D v2(0, 0, 0, 0);
    double angle = Vector::angleBetween(v1, v2);
    EXPECT_DOUBLE_EQ(angle, 0.0);
}

TEST(Vector2DTest, StaticReadFromStream) {
    std::stringstream ss("1 2 4 6");
    Vector2D v = Vector2D::readFromStream(ss);
    EXPECT_DOUBLE_EQ(v.getStart().getX(), 1.0);
    EXPECT_DOUBLE_EQ(v.getStart().getY(), 2.0);
    EXPECT_DOUBLE_EQ(v.getEnd().getX(), 4.0);
    EXPECT_DOUBLE_EQ(v.getEnd().getY(), 6.0);
}

TEST(Vector2DTest, StaticToString) {
    Vector2D v(0, 0, 3, 4);
    std::string str = Vector2D::toString(v);
    EXPECT_FALSE(str.empty());
    EXPECT_NE(str.find("length = 5"), std::string::npos);
}

TEST(Vector2DTest, StreamOutput) {
    Vector2D v(0, 0, 3, 4);
    std::stringstream ss;
    ss << v;
    EXPECT_NE(ss.str().find("length = 5"), std::string::npos);
}

TEST(Vector2DTest, VectorCollection) {
    std::vector<Vector2D> vectors;
    vectors.push_back(Vector2D(0, 0, 1, 0));
    vectors.push_back(Vector2D(0, 0, 0, 1));
    vectors.push_back(Vector2D(0, 0, 1, 1));
    
    EXPECT_DOUBLE_EQ(vectors[0].length(), 1.0);
    EXPECT_DOUBLE_EQ(vectors[1].length(), 1.0);
    EXPECT_DOUBLE_EQ(vectors[2].length(), std::sqrt(2.0));
}
