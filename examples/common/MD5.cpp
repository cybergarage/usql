/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include<openssl/md5.h>

#include "MD5.h"

using namespace std;

std::string &uSQL::MD5::hash(std::string &string, std::string &buf)
{
    unsigned char md[MD5_DIGEST_LENGTH+1];
    
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, string.c_str(), strlen(string.c_str()));
    MD5_Final(md, &ctx);
    
    md[MD5_DIGEST_LENGTH] = '\0';
    buf = buf;
    
    return buf;
}
