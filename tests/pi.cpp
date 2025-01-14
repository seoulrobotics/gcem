/*################################################################################
  ##
  ##   Copyright (C) 2016-2020 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

// g++-mp-7 -O3 -Wall -std=c++11 -fconstexpr-depth=20 -fconstexpr-steps=1271242 -I./../include log.cpp -o log.test -framework Accelerate

#define TEST_PRINT_PRECISION_1 6
#define TEST_PRINT_PRECISION_2 18

#ifndef _WIN32
#define TEST_ERR_TOL 1e-7
#endif

#include "gcem_tests.hpp"
#include <math.h>

float naive_pi_mult(float mult)
{
  return M_PIf32 * mult;
}
float naive_pi_div(float mult)
{
  return M_PIf32 / mult;
}
int main()
{
    print_begin("pi");

    //

    GCEM_TEST_EXPECTED_VAL(gcem::pi_mul, M_PI_2f32, 0.5f);
    GCEM_TEST_EXPECTED_VAL(gcem::pi_mul, M_PI_4f32, 0.25f);
    GCEM_TEST_EXPECTED_VAL(gcem::pi_mul, M_PIf32, 1.0f);
    GCEM_TEST_COMPARE_VALS(gcem::pi_mul, naive_pi_mult, 1.5f);
    GCEM_TEST_COMPARE_VALS(gcem::pi_mul, naive_pi_mult, 1231.1f);
    GCEM_TEST_COMPARE_VALS(gcem::pi_mul, naive_pi_mult, -122133123.1f);
    // GCEM_TEST_COMPARE_VALS(gcem::pi_mul, naive_pi_mult, 0);
    GCEM_TEST_COMPARE_VALS(gcem::pi_mul, naive_pi_mult, std::numeric_limits<float>::quiet_NaN());
    GCEM_TEST_COMPARE_VALS(gcem::pi_mul, naive_pi_mult, std::numeric_limits<float>::infinity());
    GCEM_TEST_COMPARE_VALS(gcem::pi_mul, naive_pi_mult, -std::numeric_limits<float>::infinity());

    GCEM_TEST_EXPECTED_VAL(gcem::pi_div, M_PI_2f32, 2.0f);
    GCEM_TEST_EXPECTED_VAL(gcem::pi_div, M_PI_4f32, 4.0f);
    GCEM_TEST_EXPECTED_VAL(gcem::pi_div, M_PIf32, 1.0f);
    GCEM_TEST_COMPARE_VALS(gcem::pi_div, naive_pi_div, 1.5f);
    GCEM_TEST_COMPARE_VALS(gcem::pi_div, naive_pi_div, 1231.1f);
    GCEM_TEST_COMPARE_VALS(gcem::pi_div, naive_pi_div, -122133123.1f);
    // GCEM_TEST_COMPARE_VALS(gcem::pi_div, naive_pi_div, 0);
    GCEM_TEST_COMPARE_VALS(gcem::pi_div, naive_pi_div, std::numeric_limits<float>::quiet_NaN());
    GCEM_TEST_COMPARE_VALS(gcem::pi_div, naive_pi_div, std::numeric_limits<float>::infinity());
    GCEM_TEST_COMPARE_VALS(gcem::pi_div, naive_pi_div, -std::numeric_limits<float>::infinity());
    static_assert(gcem::pi<float>() == M_PIf32);
    static_assert(gcem::pi<double>() == M_PIf64);
    static_assert(gcem::pi<long double>() == M_PIf64x);

    print_final("pi");

    return 0;
}
