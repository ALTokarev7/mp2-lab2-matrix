#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  TDynamicVector<int> v(5);
  v[1] = 7;
  v[3] = 999;
  TDynamicVector<int> vCopy(v);
  EXPECT_EQ(v, vCopy);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
  TDynamicVector<int> v(5);
  v[1] = 7;
  TDynamicVector<int> vCopy(v);
  v[3] = 999;
  EXPECT_EQ(v[3] == 999, true);
  EXPECT_EQ(vCopy[3] != 999, true);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
  TDynamicVector<int> v(4);
  ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
  TDynamicVector<int> v(4);
  ASSERT_ANY_THROW(v.at(5));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
  TDynamicVector<int> v(4);
  v[2] = 2;
  v[3] = 3;
  ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(4);
  v[2] = 2;
  v[3] = 3;
  ASSERT_NO_THROW(v1 = v);
  EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(5);
  v1 = v;
  EXPECT_EQ(v1.size(), 4);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
  TDynamicVector<int> v(4);
  TDynamicVector<int> v1(5);
  v.at(1) = 777;
  v.at(2) = 999;
  v1 = v;
  EXPECT_EQ(v1, v);
}
 

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
  TDynamicVector<int> v(7);
  TDynamicVector<int> v1(7);
  v.at(1) = 777;
  v.at(3) = 888;
  v.at(5) = 999;
  v1.at(1) = 777;
  v1.at(3) = 888;
  v1.at(5) = 999;
  EXPECT_EQ(v == v1, true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
  TDynamicVector<int> v(7);
  v.at(1) = 777;
  v.at(3) = 888;
  v.at(5) = 999;
  EXPECT_EQ(v == v, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
  TDynamicVector<int> v(7);
  TDynamicVector<int> v1(8);
  v.at(1) = 777;
  v.at(3) = 888;
  v1.at(1) = 777;
  v1.at(3) = 888;
  EXPECT_NE(v, v1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
  TDynamicVector<int> v(3);
  TDynamicVector<int> v1(3);
  v[0] = 7;
  v[1] = 7;
  v[2] = 7;
  v1 = v1 + 7;
  EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  TDynamicVector<int> v(3);
  TDynamicVector<int> v1(3);
  v[0] = -7;
  v[1] = -7;
  v[2] = -7;
  v1 = v1 - 7;
  EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
  TDynamicVector<int> v(3);
  int arr[3] = { 2,2,2 };
  TDynamicVector<int> v1(arr,3);
  v[0] = 6;
  v[1] = 6;
  v[2] = 6;
  v1 = v1 * 3;
  EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
  int arr[3] = { 7,7,7 };
  int arr1[3] = { 4,4,4 };
  int arr2[3] = { 3,3,3 };

  TDynamicVector<int> v(arr, 3);
  TDynamicVector<int> v1(arr1, 3);
  TDynamicVector<int> v2(arr2, 3);
  EXPECT_EQ(v, v1 + v2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(7);
  ASSERT_ANY_THROW(v + v1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  int arr[3] = { 1,1,1 };
  int arr1[3] = { 4,4,4 };
  int arr2[3] = { 3,3,3 };

  TDynamicVector<int> v(arr, 3);
  TDynamicVector<int> v1(arr1, 3);
  TDynamicVector<int> v2(arr2, 3);
  EXPECT_EQ(v, v1 - v2);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(7);
  ASSERT_ANY_THROW(v - v1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
  int arr1[3] = { 4,4,4 };
  int arr2[3] = { 3,3,3 };

  TDynamicVector<int> v1(arr1, 3);
  TDynamicVector<int> v2(arr2, 3);
  EXPECT_EQ(36, v1 * v2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(7);
  ASSERT_ANY_THROW(v * v1);
}

