#include "pch.h"
#include <utility>
#include <limits.h>
#include "MathLibrary.h"

// 정적 변수
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
/// 피보나치 다음값을 구하는 함수
/// 64비트 기준 오버플로우가 일어날때까지 계산할 수 있다.
/// </summary>
/// <returns>성공 : true, 오버플로우 발생 : false</returns>
bool fibonacci_next()
{
    // 오버플로우 체크
    if ((ULLONG_MAX - previous_ < current_) || (UINT_MAX == index_))
    {
        return false;
    }

    // 기저 사례
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