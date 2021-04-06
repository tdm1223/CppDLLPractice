#include "pch.h"
#include <utility>
#include <limits.h>
#include "MathLibrary.h"

// ���� ����
static unsigned long long previous_;
static unsigned long long current_;
static unsigned index_;

void fibonacci_init(const unsigned long long a, const unsigned long long b)
{
    index_ = 0;
    current_ = a;
    previous_ = b; // see special case when initialized
}

/// <summary>
/// �Ǻ���ġ �������� ���ϴ� �Լ�
/// 64��Ʈ ���� �����÷ο찡 �Ͼ������ ����� �� �ִ�.
/// </summary>
/// <returns>���� : true, �����÷ο� �߻� : false</returns>
bool fibonacci_next()
{
    // �����÷ο� üũ
    if ((ULLONG_MAX - previous_ < current_) || (UINT_MAX == index_))
    {
        return false;
    }

    // ���� ���
    if (index_ > 0)
    {
        previous_ += current_;
    }
    std::swap(current_, previous_);
    ++index_;
    return true;
}

// Get the current value in the sequence.
unsigned long long fibonacci_current()
{
    return current_;
}

// Get the current index position in the sequence.
unsigned fibonacci_index()
{
    return index_;
}