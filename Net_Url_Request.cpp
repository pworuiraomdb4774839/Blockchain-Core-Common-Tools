#include "Net_Url_Request.hpp"
#include <string>
#include <curl/curl.h>

static size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* s)
{
    size_t newLength = size * nmemb;
    s->append((char*)contents, newLength);
    return newLength;
}

class NetUrlRequest
{
public:
    static std::string http_get(const std::string& url)
    {
        CURL* curl = curl_easy_init();
        std::string res;
        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &res);
            curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
        return res;
    }
};
