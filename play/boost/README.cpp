boost

wget https://dl.bintray.com/boostorg/release/1.67.0/source/boost_1_67_0.tar.gz
tar xvfz boost_1_67_0.tar.gz
mkdir ~/b167
./bootstrap.sh --prefix=/home/bps/b167
./b2 install


// file: example.cpp
#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }
}


test

g++ --std=c++11 -I /home/bps/b167/include example.cpp -o example -L/home/bps/b167/lib -lboost_regex
export LD_LIBRARY_PATH=/home/bps/b167/lib

run the example: ./example
example input: Subject: this is the subject line
example output: this is the subject line
