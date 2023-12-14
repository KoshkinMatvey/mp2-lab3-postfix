#include "Postfix.h"
#include <gtest.h>

using namespace std;

TEST(TArithmeticExpression, can_create_empty_postfix)
{
	ASSERT_NO_THROW(TArithmeticExpression p);
}

TEST(TArithmeticExpression, can_create_definite_postfix)
{
	string infixExpression = "1 + 3 + 5";
	ASSERT_NO_THROW(TArithmeticExpression p(infixExpression));
}

TEST(TArithmeticExpression, is_infix_correct)
{
	string infixExpression = "1 + 2 + 3";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.getInfix(), "1 + 2 + 3");
}

TEST(TArithmeticExpression, can_get_infix)
{
	string infixExpression = "1 + 2 + 3";
	TArithmeticExpression p(infixExpression);
	ASSERT_NO_THROW(p.getInfix());
}

TEST(TArithmeticExpression, is_postfix_correct)
{
	string infixExpression = "1 + 2 + 3";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.getPostfix(), "1 2 + 3 + ");
}

TEST(TArithmeticExpression, is_simple_expression_calculate_correct)
{
	string infixExpression = "3 + 5 + 7";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.calculate(), 15);
}

TEST(TArithmeticExpression, is_brackets_operator_correct)
{
	string infixExpression = "2 * (5 + 10)";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.calculate(), 30);
}

TEST(TArithmeticExpression, is_minus_operator_correct)
{
	string infixExpression = "2 - 2";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.calculate(), 0);
}

TEST(TArithmeticExpression, is_plus_operator_correct)
{
	string infixExpression = "1 + 3";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.calculate(), 4);
}

TEST(TArithmeticExpression, is_div_operator_correct)
{
	string infixExpression = "(20 + 30) / (3 + 2)";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.calculate(), 10);
}

TEST(TArithmeticExpression, is_mul_operator_correct)
{
	string infixExpression = "2 * 2";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.calculate(), 4);
}

TEST(TArithmeticExpression, is_float_num_calculate_correct)
{
	string infixExpression = "1.34 + 2.67";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.calculate(), 4.01);
}

TEST(TArithmeticExpression, is_complex_expression_calculate_correct)
{
	string infixExpression = "((1.5 + 2.7) + 7) * (2.5 + 5)";
	TArithmeticExpression p(infixExpression);
	ASSERT_EQ(p.calculate(), 84);
}

TEST(TArithmeticExpression, can_get_operands)
{
	string infixExpression = "1 + 2 + 3";
	TArithmeticExpression p(infixExpression);
	ASSERT_NO_THROW(p.getOperands());
}

TEST(TArithmeticExpression, cant_calculate_invalid_expression)
{
	string infixExpression = "1+";
	TArithmeticExpression p(infixExpression);
	ASSERT_ANY_THROW(p.calculate());
}






