#include <iostream>
#include "uforia.h"

using namespace std;

int main()
{
    vector<string> vec_s;
    vec_s.push_back("Apple");
    vec_s.push_back("Banana");
    vec_s.push_back("Cherry");

    string from_vector = from(vec_s);

    // Check string from(vector<string>, bool)
    bulletin("Check string from(vector<string>)", from_vector.length() == 20);

    // Check vector<string> from(string, bool)
    string fruits = "Apple Banana Cherry";
    vector<string> vec = from(fruits, ' ');
    bulletin("Check vector<string> from(string, char)", vec.size() == 3);

    // vector<string> from(string, bool)
    vector<string> from_file = from("/home/demonic/uforia/fruits.txt", false);
    bulletin("Check vector<string> from(file, bool)", from_file.size() == 3);

    // has(string, string)
    bulletin("Check has(string, string)", has("world", "Hello world!"));

    // has(char, string)
    bulletin("Check has(char, string)", has('p', "Apple"));

    // has(string, vector<string>)
    bulletin("Check has(string, vector<string>)", has("Apple", vec_s));

    

    return 0;
}
