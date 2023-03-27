#ifndef HELPMAKER_H
#define HELPMAKER_H

#include <iostream>
#include <vector>

struct Entry {
std::string argument, alternative, description;
};

class HelpMaker {
public:
	HelpMaker(std::string name);
	void add_usage(std::string usage);
    void add_argument(std::string argument, std::string description, std::string alternative = "");
	void add_example(std::string example);
	void print();
private:
	std::string name, usage;
	std::vector<Entry> entries;
	std::vector<std::string> examples;
    bool has_entry = false, has_usage = false, has_example = false;
};

HelpMaker::HelpMaker(std::string name){
	this->name = name;
}

void HelpMaker::add_usage(std::string usage){
	has_usage = true;
	this->usage = usage;
}


void HelpMaker::add_argument(std::string argument, std::string description, std::string alternative){
	has_entry = true;
	Entry entry;
	entry.argument = argument;
	entry.description = description;
	entry.alternative = alternative;
	entries.push_back(entry);
}

void HelpMaker::add_example(std::string example){
	has_example = true;
	examples.push_back(example);
}

void HelpMaker::print(){
	std::cout << " " << name << std::endl << std::endl;
	
	if(has_usage){
		std::cout << " USAGE:" << std::endl << " " << usage << std::endl << std::endl;
	}

	if(has_entry){
		std::cout << " OPTIONS:" << std::endl;
		for(int i = 0; i < entries.size(); ++i){
			Entry entry = entries[i];
			std::cout << " " << entry.argument << "\t" << entry.description << std::endl;
		}
		std::cout << std::endl;
	}

	if(has_example){
		std::cout << " EXAMPLE:" << std::endl;
		for(int i = 0; i < examples.size(); ++i){
			std::cout << " " << examples[i] << std::endl;
		}
	}
}

#endif // HELPMAKER_H
