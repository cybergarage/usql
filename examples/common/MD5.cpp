/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <openssl/md5.h>
#include <strstream>

#include "MD5.h"

using namespace std;

std::string &uSQL::MD5::hash(const std::string &string, std::string &buf)
{
    unsigned char md5Digest[MD5_DIGEST_LENGTH];
    
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, string.c_str(), strlen(string.c_str()));
    MD5_Final(md5Digest, &ctx);
    
    strstream md5String;
    for (int n=0; n<MD5_DIGEST_LENGTH; n++) {
        char hexString[3];
        snprintf(hexString, sizeof(hexString), "%02X", (int)md5Digest[n]);
        md5String << hexString;
    }
    buf = md5String.str();
    
    return buf;
}
