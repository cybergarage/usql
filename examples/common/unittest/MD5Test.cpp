/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <openssl/md5.h>
#include "MD5.h"

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(MD5Test)
{
  string digest;
  MD5::hash("http://www.cybergarage.org", digest);
  BOOST_CHECK_MESSAGE((digest.length() == (MD5_DIGEST_LENGTH * 2)), digest << " (" << digest.length() << ") != " << (MD5_DIGEST_LENGTH*2));
}
