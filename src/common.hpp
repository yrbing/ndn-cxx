/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/**
 * Copyright (c) 2013-2014,  Regents of the University of California.
 * All rights reserved.
 *
 * This file is part of ndn-cxx library (NDN C++ library with eXperimental eXtensions).
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 *
 * This file licensed under New BSD License.  See COPYING for detailed information about
 * ndn-cxx library copyright, permissions, and redistribution restrictions.
 */

#ifndef NDN_COMMON_HPP
#define NDN_COMMON_HPP

#include "ndn-cxx-config.hpp"
#include <stdint.h>
// TODO: Is stddef.h portable?
#include <stddef.h>
#include <unistd.h>

// Standard headers to precompile

#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <map>
#include <sstream>
#include <fstream>
#include <exception>
#include <map>

// Other useful headers to precompile
#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/utility.hpp>

#include <boost/iostreams/detail/ios.hpp>
#include <boost/iostreams/categories.hpp>
#include <boost/iostreams/stream.hpp>

#if defined(__GNUC__) || defined(__clang__)
#define DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED(func) __declspec(deprecated) func
#else
#pragma message("DEPRECATED not implemented")
#define DEPRECATED(func) func
#endif

#ifdef NDN_CXX_HAVE_CXX11

#if defined(__GNUC__)
#  if !defined(__GXX_EXPERIMENTAL_CXX0X__) && __cplusplus < 201103L
#    error "NDN-CXX library is configured and compiled in C++11 mode, but the current compiler is not C++11 enabled"
#  endif // !defined(__GXX_EXPERIMENTAL_CXX0X__) && __cplusplus < 201103L
#endif // defined(__GNUC__)

#if defined(__clang__) && __cplusplus < 201103L
#  error "NDN-CXX library is configured and compiled in C++11 mode, but the current compiler is not C++11 enabled"
#endif // defined(__clang__) && (__cplusplus < 201103L)


#include <memory>
#include <functional>

namespace ndn {

namespace ptr_lib = std;
namespace func_lib = std;

using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::enable_shared_from_this;

using std::static_pointer_cast;
using std::dynamic_pointer_cast;
using std::const_pointer_cast;

using std::function;
using std::bind;
using std::placeholders; // _1, _2, ..

} // namespace ndn


#else

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/make_shared.hpp>

#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace ndn {

namespace ptr_lib = boost;
namespace func_lib = boost;

using boost::shared_ptr;
using boost::weak_ptr;
using boost::make_shared;
using boost::enable_shared_from_this;

using boost::static_pointer_cast;
using boost::dynamic_pointer_cast;
using boost::const_pointer_cast;

using boost::function;
using boost::bind;

} // namespace ndn

#endif // NDN_CXX_HAVE_CXX11

namespace ndn {

using boost::noncopyable;

}

#include "util/time.hpp"

#endif
