#include <iostream>
#include <array>

using namespace std;

template <typename T, size_t SIZE>

class Queue
{
public:
    Queue() : front_(0), rear_(0), count_(0) {}

    bool empty() const
    {
        return count_ == 0;
    }

    bool full() const
    {
        return count_ == SIZE;
    }

    size_t size() const
    {
        return count_;
    }

    void push(const T &item)
    {
        if (!full())
        {
            items_[rear_] = item;
            rear_++;
            if (rear_ == SIZE)
            {
                rear_ = 0;
            }
            count_++;
        }
    }

    T &front()
    {
        return items_[front_];
    }

    const T &front() const
    {
        return items_[front_];
    }

    void pop()
    {
        if (!empty())
        {
            front_++;
            if (front_ == SIZE)
            {
                front_ = 0;
            }
            count_--;
        }
    }

private:
    array<T, SIZE> items_;
    size_t front_;
    size_t rear_;
    size_t count_;
};
