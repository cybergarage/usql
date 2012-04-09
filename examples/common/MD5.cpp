/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <iomanip>
#include <iostream>
#include <strstream>

#include <stdio.h>
#include <string.h>

#include <openssl/md5.h>

#include "MD5.h"

using namespace std;

std::string &uSQL::MD5::hash(const std::string &string, std::string &buf)
{
    unsigned char md5Digest[MD5_DIGEST_LENGTH];
    char md5DigestString[(MD5_DIGEST_LENGTH*2) + 1];
    
    ::MD5((unsigned char*)string.c_str(), strlen(string.c_str()), md5Digest);

    char hexString[3];
    for (int n=0; n<MD5_DIGEST_LENGTH; n++) {
        snprintf(hexString, sizeof(hexString), "%02X", md5Digest[n]);
        md5DigestString[(n*2)+0] = hexString[0];
        md5DigestString[(n*2)+1] = hexString[1];
    }
    md5DigestString[sizeof(md5DigestString)-1] = '\0';
    
    buf = md5DigestString;
    
    return buf;
}
