#ifndef HELPMENU_H
#define HELPMENU_H

#include <iostream>
#include <vector>

struct Option{
    Option(std::string argument, std::string description, bool primary){
        this->argument = argument;
        this->description = description;
        this->primary = primary;
    }
    std::string argument, description;
    bool primary = false;
};

class HelpMenu{
public:
    HelpMenu(std::string program);
    void add_usage(std::string usage);
    void add_option(std::string argument, std::string description, bool primary);
    void add_example(std::string example);
    void print();
private:
    std::string program, usage, example;
    std::vector<Option> options;
    bool flag_usage = false, flag_options = false, flag_example = false;
};

HelpMenu::HelpMenu(std::string program){
    this->program = program;
}

// Add usage
void HelpMenu::add_usage(std::string usage){
    flag_usage = true;
    this->usage = usage;
}

// Add option
void HelpMenu::add_option(std::string argument, std::string description, bool primary = false){
    flag_options = true;
    Option option(argument, description, primary);
    options.push_back(option);
}

// Add example
void HelpMenu::add_example(std::string example){
    flag_example = true;
    this->example = example;
}

// Print helpmenu
void HelpMenu::print(){
    std::cout << program << std::endl << std::endl;
    if(flag_usage){
        std::cout << "USAGE:" << std::endl;
        std::cout << usage << std::endl << std::endl;
    }

    if(flag_options){
        std::cout << "OPTIONS:" << std::endl;
        for(int i = 0; i < options.size(); ++i){
            Option option = options[i];
            std::string temp = option.argument + "\t" + option.description;
            if(option.primary){
                std::cout << colored(temp, Green, Bold) << std::endl;
            }else{
                std::cout << temp << std::endl;
            }
        }
        std::cout << std::endl;
    }

    if(flag_example){
        std::cout << "EXAMPLE:" << std::endl;
        std::cout << example << std::endl << std::endl;
    }
}

#endif // HELPMENU_H
