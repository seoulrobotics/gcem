/*
 * compile-time pi multiples
 */

#pragma once


template<typename T>
constexpr
T
pi_mul(const T x)
noexcept
{
    return (T(GCEM_PI) * x);
}
template<typename T>
constexpr
T
pi_div(const T x)
noexcept
{
    return( pi_mul(T(1)/ x) );
}




