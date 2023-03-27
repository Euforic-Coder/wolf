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
                if (!is_directory(*it)){
                    files.push_back(current_path);
                }else{
                    get_files(current_path);
                }
                it++;
            }
        }
    }catch(...){}
}

// Calculate score of match
int calculate(const string& s, const string& other){
    int score = 0;
    vector<string> buffer = funnel(s);
    for(int i = 0; i < buffer.size(); ++i){
        string part = buffer[i];
        if(has(part, other)){
            score += (part.length() * part.length());
        }
    }
    return score;
}

// Calculate percentage of match
void match(const path& p){

    string file = p.filename().generic_string();
    float full = calculate(search, search);
    float perc = calculate(search, file);
    float calc = (perc / full) * 100;
    if(calc > 75){
        cout << p.generic_string() << endl;
    }

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

    // Collect files
    get_files(location);

    // Iterate through files
    for(path file : files){
        match(file.generic_string());
    }
    return 0;
}
