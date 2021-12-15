#include "classes/util.h"
#include <algorithm>

//credit: https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
std::string Util::asciiToLower(std::string str){
    std::transform(str.begin(), str.end(), str.begin(),[](unsigned char c){return std::tolower(c); }
    );

    return str;
}