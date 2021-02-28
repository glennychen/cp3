// https://leetcode.com/problems/logger-rate-limiter/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//C++11 local static variable can be initialized, lasting life time of the program, and thread-safe (initilized once?)
class Logger {

public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto iter = string_timestamp.find(message);
        if (iter==string_timestamp.end()){
            string_timestamp[message]=timestamp;
            return true;
        }

        if (string_timestamp[message]+10<=timestamp){ // <=, at most every 10 second
            string_timestamp[message]=timestamp;
            return true;
        }
        return false;
    }

    unordered_map<string, int> string_timestamp;

};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

int main()
{
    Logger* obj = new Logger();
    bool param_1 = obj->shouldPrintMessage(100,"bug");
    bool param_2 = obj->shouldPrintMessage(111,"bug");
    delete obj;
    return 0;
}
