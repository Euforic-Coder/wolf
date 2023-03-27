#ifndef HAS_H
#define HAS_H

bool has(std::string s, std::string other){
    if(s.length() <= other.length()){
        for(unsigned short int i = 0; i <= (other.length() - s.length()); ++i){
            std::string substr = other.substr(i, s.length());
            if(substr == s){
                return true;
            }
        }
    }else if(s == other){
        return true;
    }
    return false;
}

bool has(char c, std::string s){
    for(unsigned short int i = 0; i < s.length(); ++i){
        if(s[i] == c){
            return true;
        }
    }
    return false;
}

bool has(std::string s, std::vector<std::string> vec){
    for(unsigned short i = 0; i < vec.size(); ++i){
        if(s == vec[i]){
            return true;
        }
    }
    return false;
}

#endif // HAS_H
