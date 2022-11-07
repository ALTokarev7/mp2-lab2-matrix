#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> A(5);
	A[1][1] = 3;
	A[2][2] = 5;
	A[4][3] = 7;
	TDynamicMatrix<int> B(A);
	EXPECT_EQ(A, B);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> A(5);
	A[1][1] = 3;
	A[2][2] = 5;
	A[4][3] = 7;
	TDynamicMatrix<int> B(A);
	B[4][4] = 9;
	A[4][4] = 11;
	EXPECT_NE(A[4][4], B[4][4]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> A(5);
	EXPECT_EQ(A.size(), 5);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> A(3);
	ASSERT_NO_THROW(A[2][2] = 7;);
	EXPECT_EQ(A[2][2], 7);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
 TDynamicMatrix<int> A(3);
 ASSERT_ANY_THROW(A.at(-1,2) = 7;);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
  TDynamicMatrix<int> A(3);
  ASSERT_ANY_THROW(A.at(1,-1) = 7;);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> A(3);
	ASSERT_NO_THROW(A = A);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 7;
	TDynamicMatrix<int> B(3);
	B[1][1] = 9;
	B = A;
	EXPECT_EQ(A, B);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> A(3);
	TDynamicMatrix<int> B(5);
	B = A;
	EXPECT_EQ(B.size(), A.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> A(5);
	A[1][1] = 7;
	TDynamicMatrix<int> B(3);
	B = A;
	EXPECT_EQ(A, B);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 7;
	A[2][2] = 3;
	TDynamicMatrix<int> B(3);
	B[1][1] = 7;
	B[2][2] = 3;
	EXPECT_EQ(A == B, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 7;
	A[2][2] = 3;
	EXPECT_EQ(A == A, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> A(3);
	TDynamicMatrix<int> B(5);
	EXPECT_EQ(A == B, false );
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 7;
	A[2][2] = 3;
	TDynamicMatrix<int> B(3);
	B[1][1] = 4;
	B[2][2] = 1;
	TDynamicMatrix<int> C(3);
	C[1][1] = 11;
	C[2][2] = 4;
	TDynamicMatrix<int> E(5);
	E = A + B;
	EXPECT_EQ(E, C);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 7;
	A[2][2] = 3;
	TDynamicMatrix<int> B(5);
	B[1][1] = 4;
	B[2][2] = 1;
	ASSERT_ANY_THROW(A + B);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 7;
	A[2][2] = 3;
	TDynamicMatrix<int> B(3);
	B[1][1] = 4;
	B[2][2] = 1;
	TDynamicMatrix<int> C(3);
	C[1][1] = 3;
	C[2][2] = 2;
	TDynamicMatrix<int> E(5);
	E = A - B;
	EXPECT_EQ(E, C);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> A(3);
	A[1][1] = 7;
	A[2][2] = 3;
	TDynamicMatrix<int> B(5);
	B[1][1] = 4;
	B[2][2] = 1;
	ASSERT_ANY_THROW(A - B);
}


