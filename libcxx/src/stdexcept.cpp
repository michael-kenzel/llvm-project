//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <__verbose_abort>
#include <stdexcept>
#include <string>

#ifdef _LIBCPP_ABI_VCRUNTIME
#  include "support/runtime/stdexcept_vcruntime.ipp"
#else
#  include "support/runtime/stdexcept_default.ipp"
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

_LIBCPP_NORETURN void __throw_runtime_error(const char* msg) {
#ifndef _LIBCPP_HAS_NO_EXCEPTIONS
  throw runtime_error(msg);
#else
  _LIBCPP_VERBOSE_ABORT("runtime_error was thrown in -fno-exceptions mode with message \"%s\"", msg);
#endif
}

_LIBCPP_END_NAMESPACE_STD


#include "include/refstring.h"

static_assert(sizeof(std::__libcpp_refstring) == sizeof(const char *), "");

namespace std  // purposefully not using versioning namespace
{

logic_error::~logic_error() noexcept {}

const char*
logic_error::what() const noexcept
{
    return __imp_.c_str();
}

runtime_error::~runtime_error() noexcept {}

const char*
runtime_error::what() const noexcept
{
    return __imp_.c_str();
}

domain_error::~domain_error() noexcept {}
invalid_argument::~invalid_argument() noexcept {}
length_error::~length_error() noexcept {}
out_of_range::~out_of_range() noexcept {}

range_error::~range_error() noexcept {}
overflow_error::~overflow_error() noexcept {}
underflow_error::~underflow_error() noexcept {}

}  // std
