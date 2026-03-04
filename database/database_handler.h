#pragma once
#include <string>
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>

class database {
private:
    int number_of_rows = 0;
    int number_of_records = 0;
    std::string database_name;

    std::vector<std::vector<std::string>> db;

public:
    void init(int rows, std::string name);
    void add_record(std::vector<std::string> data);
    void read_record();
    void save_to_file();
    void read_from_file();
};