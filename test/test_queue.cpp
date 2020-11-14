#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue_with_positive_size)
{
    ASSERT_NO_THROW(Queue<int> q(3));
}

TEST(Queue, cant_create_queue_with_too_large_size)
{
    ASSERT_ANY_THROW(Queue<int> q(MAX_VECTOR_SIZE + 1));
}

TEST(Queue, cant_create_queue_with_negative_size)
{
    ASSERT_ANY_THROW(Queue<int> q(-3));
}

TEST(Queue, can_get_size)
{
    Queue<int> q(3);

    EXPECT_EQ(3, q.size());
}

TEST(Queue, can_get_front)
{
    Queue<int> q(3);
    q[0] = 1; q[1] = 2; q[2] = 3;

    EXPECT_EQ(1, q.front());
}

TEST(Queue, cant_get_front_of_empty_queue)
{
    Queue<int> q(0);

    ASSERT_ANY_THROW(q.front());
}

TEST(Queue, can_get_back)
{
    Queue<int> q(3);
    q[0] = 1; q[1] = 2; q[2] = 3;

    EXPECT_EQ(3, q.back());
}

TEST(Queue, cant_get_back_of_empty_queue)
{
    Queue<int> q(0);

    ASSERT_ANY_THROW(q.back());
}

TEST(Queue, can_push_element_with_repacking)
{
    Queue<int> q(3);
    q[0] = 1; q[1] = 2; q[2] = 3;

    ASSERT_NO_THROW(q.push(4));
}

TEST(Queue, can_push_element_without_repacking)
{
    Queue<int> q(3);
    q[0] = 1; q[1] = 2; q[2] = 3;
    q.pop();

    ASSERT_NO_THROW(q.push(4));
}

TEST(Queue, cant_push_element_when_the_memory_is_end)
{
    Queue<int> q(MAX_VECTOR_SIZE);

    ASSERT_ANY_THROW(q.push(4));
}

TEST(Queue, can_pop_element)
{
    Queue<int> q(3);
    q[0] = 1; q[1] = 2; q[2] = 3;

    ASSERT_NO_THROW(q.pop());
}

TEST(Queue, cant_pop_element_when_queue_is_empty)
{
    Queue<int> q(0);

    ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, queue_is_empty)
{
    Queue<int> q(0);

    EXPECT_EQ(true, q.empty());
}

TEST(Queue, queue_is_not_empty)
{
    Queue<int> q(3);

    EXPECT_EQ(false, q.empty());
}

TEST(Queue, queue_is_full)
{
    Queue<int> q(3);
    q[0] = 1; q[1] = 2; q[2] = 3;

    EXPECT_EQ(true, q.full());
}

TEST(Queue, queue_is_not_full)
{
    Queue<int> q(4);
    q[0] = 1; q[1] = 2; q[2] = 3; q[3] = 4;
    q.push(5);

    EXPECT_EQ(false, q.full());
}