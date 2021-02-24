// https://leetcode.com/problems/goal-parser-interpretation/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string interpret(string command) {
    string output;
    //for(const auto& c: command) { //bug: use iter to traverse 1 or more, not every single char
    //while(iter!=command.end()) {
    for(auto iter=command.begin();iter!=command.end();) {
        if (*iter=='G') {
            //output.push_back("G"); //why?
            output += "G";
            ++iter;
        } else {
            if (*(iter+1) == ')'){
                output += "o";
                iter += 2;
            } else {
                output += "al";
                iter += 4;
            }
        }
    }
    return output;
}

int main() {
    string command = "G()(al)";
    interpret(command);
    command = "(al)G(al)()()G";
    interpret(command);
    return 0;
}
