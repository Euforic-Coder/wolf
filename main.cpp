#include <iostream>
#include <filesystem>
#include <vector>
#include <cmath>
#include "uforia/uforia.h"

using namespace std;
using namespace std::filesystem;

string search;
path location;

// Collect all files from given path
vector<path> files;

void get_files(path p){
    try{
        if(exists(p) && is_directory(p) && !is_symlink(p)){
            directory_iterator it(p);
            while(it != directory_iterator{}){
                path current_path(*it);
                if (!is_directory(*it) && is_regular_file(*it)){
                    files.push_back(current_path);
                    DEBUG(current_path.generic_string());
                }else{
                    get_files(current_path);
                }
                it++;
            }
        }
    }catch(...){}
}

int calculate(const string& s, const string& other){
    int score;
    vector<string> buffer = funnel(s);
    for(int i = 0; i < buffer.size(); ++i){
        string part = buffer[i];
        if(has(part, other)){
            score += (part.length() * part.length());
        }
    }
    return score;
}

void match(const path& p){

    // Grab filename
    string file = p.filename().generic_string();
    DEBUG(file);
    float full = calculate(search, search);
    float perc = calculate(p.generic_string(), search);
    float calc = (perc / full) * 100;
    string temp = colored(search, Red, Bold) + " Full = " + to_string(full) + " Perc = " + to_string(perc) + " Calc = " + to_string(calc);
    DEBUG(temp);

}

int main(int argc, char *argv[]){

    // Check if 2 arguments are given
    if (argc < 3){
        error("Wrong arguments given", true);
    }
    if(argv[1]){
        search = argv[1];
    }else{
        error("No argument given", true);
    }

    if(argv[2]){
        location = argv[2];
    }else{
        location = "./";
    }

    DEBUG(search);
    DEBUG(location);

    get_files(location);
    for(path file : files){
        DEBUG(file.generic_string());
        match(file.generic_string());
    }
    return 0;
}
