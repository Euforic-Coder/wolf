#ifndef FROM_H
#define FROM_H

#include <iostream>
#include <vector>
#include <fstream>

std::string from(std::vector<std::string> vec, char seperator = ' '){
    std::string buffer;
    for(int i = 0; i < vec.size(); ++i){
        buffer = buffer + seperator + vec[i];
    }
    return buffer;
}

std::vector<std::string> from(std::string s, char delimiter){
    std::vector<std::string> buffer;
    int pos = 0, len = 0;
    for(int i = 0; i < s.length(); ++i){
        char c = s[i];
        if(c == delimiter){
            buffer.push_back(s.substr(pos, len));
            len = 0;
            pos = i + 1;
        }else if (i == s.length() - 1){
            int end = s.length() - pos;
            buffer.push_back(s.substr(pos, end));
        } else {
            len++;
        }
    }
    return buffer;
}

std::vector<std::string> from(std::string file, bool lines){
    std::ifstream ifs(file);
    std::string buffer;
    std::vector<std::string> vec;
    if(lines){
        while(std::getline(ifs, buffer)){
            vec.push_back(buffer);
        }
    }else{
        while(ifs >> buffer){
            vec.push_back(buffer);
        }
    }
    return vec;
}

#endif // FROM_H
