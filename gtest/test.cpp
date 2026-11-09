#include "pch.h"

#include "D:\Git\tmp\mp2-lab3-stack\stack.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TEST(TStack, can_create_stack_with_positive_length) {
    ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, can_create_stack_with_default_length) {
    ASSERT_NO_THROW(TStack<int> s);
}

TEST(TStack, cannot_create_a_stack_of_zero_size) {
    ASSERT_THROW(TStack<int> s(0), out_of_range);
}

TEST(TStack, cannot_create_stack_with_negative_length) {
    ASSERT_THROW(TStack<int> s(-5), out_of_range);
}

TEST(TStack, cannot_create_stack_with_too_large_length) {
    ASSERT_THROW(TStack<int> s(100000001), out_of_range);
}

TEST(TStack, can_create_copied_stack) {
    TStack<int> s1(5);
    s1.push(10);

    ASSERT_NO_THROW({ TStack<int> s2_temp(s1); });
    TStack<int> s2(s1);
    EXPECT_EQ(s1, s2);
}

TEST(TStack, move_constructor_moves_elements) {
    TStack<int> s(2);
    s.push(1);
    s.push(2);
    TStack<int> s1(move(s));
    ASSERT_EQ(s1.pop(), 2);
    ASSERT_EQ(s1.pop(), 1);
    ASSERT_TRUE(s1.IsEmpty());
}

TEST(TStack, move_constructor_zeroed_out_the_original_element) {
    TStack<int> s(5);
    s.push(1);
    s.push(2);
    TStack<int> s1(move(s));
    ASSERT_TRUE(s.IsEmpty());
}

TEST(TStack, can_move_the_empty_stack) {
    TStack<int> s(5);
    TStack<int> s1 = move(s);
    ASSERT_TRUE(s1.IsEmpty());
}

TEST(TStack, move_operator_moves_elements) {
    TStack<int> s1(5), s2(3);
    s1.push(1);
    s1.push(2);
    s2.push(3);
    s2 = move(s1);
    ASSERT_EQ(s2.pop(), 2);
    ASSERT_EQ(s2.pop(), 1);
    ASSERT_TRUE(s2.IsEmpty());
}

TEST(TStack, move_operator_zeroed_out_the_original_element) {
    TStack<int> s1(5), s2(3);
    s1.push(1);
    s2 = move(s1);
    ASSERT_TRUE(s1.IsEmpty());
}

TEST(TStack, move_operator_is_assigned_to_itself) {
    TStack<int> s(5);
    s.push(10);
    ASSERT_NO_THROW(s = move(s));
    ASSERT_FALSE(s.IsEmpty());
    ASSERT_EQ(s.top(), 10);
}

TEST(TStack, new_stack_is_empty) {
    TStack<int> s(5);
    EXPECT_TRUE(s.IsEmpty());
    EXPECT_FALSE(s.IsFull());
}

TEST(TStack, stack_with_elements_is_not_empty) {
    TStack<int> s(5);
    s.push(1);
    EXPECT_FALSE(s.IsEmpty());
}

TEST(TStack, full_stack_is_full) {
    TStack<int> s(2);
    s.push(1);
    s.push(2);
    EXPECT_TRUE(s.IsFull());
    EXPECT_FALSE(s.IsEmpty());
}

TEST(TStack, can_push_element) {
    TStack<int> s(5);
    ASSERT_NO_THROW(s.push(42));
}

TEST(TStack, can_push_and_pop_element) {
    TStack<int> s(5);
    s.push(42);
    EXPECT_EQ(42, s.pop());
}

TEST(TStack, stack_order_is_lifo) {
    TStack<int> s(3);
    s.push(1);
    s.push(2);
    s.push(3);

    EXPECT_EQ(3, s.pop());
    EXPECT_EQ(2, s.pop());
    EXPECT_EQ(1, s.pop());
}

TEST(TStack, cannot_push_into_full_stack) {
    TStack<int> s(1);
    s.push(1);
    ASSERT_ANY_THROW(s.push(2));
}

TEST(TStack, cannot_pop_from_empty_stack) {
    TStack<int> s(5);
    ASSERT_ANY_THROW(s.pop());
}

TEST(TStack, can_get_element_from_the_top_of_the_stack_without_modifying_the_stack) {
    TStack<int> s(3);
    s.push(10);
    s.push(20);
    EXPECT_EQ(20, s.top());
    EXPECT_FALSE(s.IsEmpty());
    EXPECT_EQ(20, s.pop());
}

TEST(TStack, cannot_get_top_element_from_an_empty_stack) {
    TStack<int> s(5);
    ASSERT_ANY_THROW(s.top());
}

TEST(TStack, can_clear_stack) {
    TStack<int> s(5);
    s.push(1);
    s.push(2);

    s.Clr();

    EXPECT_TRUE(s.IsEmpty());
}

TEST(TStack, equal_stacks_are_equal) {
    TStack<int> s1(3);
    s1.push(10);
    s1.push(20);

    TStack<int> s2(3);
    s2.push(10);
    s2.push(20);

    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 != s2);
}

TEST(TStack, different_stacks_are_not_equal) {
    TStack<int> s1(3);
    s1.push(10);

    TStack<int> s2(3);
    s2.push(20);

    EXPECT_FALSE(s1 == s2);
    EXPECT_TRUE(s1 != s2);
}

TEST(TStack, can_assign_stack_to_itself) {
    TStack<int> s(5);
    s.push(1);

    ASSERT_NO_THROW(s = s);
}

TEST(TStack, can_assign_stacks_of_same_size) {
    TStack<int> s1(3);
    s1.push(5);

    TStack<int> s2(3);
    s2 = s1;

    EXPECT_EQ(s1, s2);
}

TEST(TStack, can_assign_stacks_of_different_size) {
    TStack<int> s1(5);
    s1.push(5);

    TStack<int> s2(2);
    s2 = s1;

    EXPECT_EQ(s1, s2);
}
