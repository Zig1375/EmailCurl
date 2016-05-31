#ifndef EmaillHelpers_h
#define EmaillHelpers_h

#import <curl/curl.h>

#define CURL_TRUE  1
#define CURL_FALSE 0

extern inline CURLcode curlHelperSetOptUseSSL(CURL *curl) {
    return curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_TRY);
}

extern inline CURLcode curlHelperSetOptBool(CURL *curl, CURLoption option, int yesNo) {
    return curl_easy_setopt(curl, option, yesNo == CURL_TRUE ? 1L : 0L);
}

extern inline CURLcode curlHelperSetOptHeaders(CURL *curl, CURLoption option, struct curl_slist *headers) {
    return curl_easy_setopt(curl, option, headers);
}

extern inline CURLcode curlHelperSetOptInt(CURL *curl, CURLoption option, long data) {
    return curl_easy_setopt(curl, option, data);
}

extern inline CURLcode curlHelperSetOptString(CURL *curl, CURLoption option, char *data) {
    return curl_easy_setopt(curl, option, data);
}

extern inline CURLcode curlHelperSetOptReadFunc(CURL *curl, size_t (*read_cb) (char *buffer, size_t size, size_t nitems, void *userdata)) {
    return curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_cb);
}

extern inline CURLcode curlHelperSetOptReadData(CURL *curl, void *userData) {
    return curl_easy_setopt(curl, CURLOPT_READDATA, userData);
}

extern inline CURLcode curlHelperGetInfoCString(CURL *curl, CURLINFO info, char **data) {
    return curl_easy_getinfo(curl, info, data);
}


extern inline CURLcode curlHelperGetInfoLong(CURL *curl, CURLINFO info, long *data) {
    return curl_easy_getinfo(curl, info, data);
}


#endif /* EmaillHelpers_h */