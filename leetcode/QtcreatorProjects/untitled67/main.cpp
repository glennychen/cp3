#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

// Encodes a URL to a shortened URL.

unordered_map<string, string> um;

string encode(string longUrl) {
    hash<string> h;
    auto v=h(longUrl);
    string s=to_string(v).substr(0,6);
    um.insert({s, longUrl});
    return "http://tinyurl.com/"+s;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
    string s=shortUrl.substr(shortUrl.rfind('/')+1);
    auto longUrl=um[s];
    return longUrl;
}
int main()
{
    string s=encode("abc");
    string ss=decode(s);
    return 0;
}
