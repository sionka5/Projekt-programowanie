#pragma once
#include <string>
#include <iostream>
#include <fstream> 
#include <sstream>

//dla latwiejszej edycji
const std::string main_file_name = "pojazdy.txt";
const int max_records = 20;
const int columns = 5;

class baza_pojazdow {
private:
    int number_of_records = 0;
    std::string db[max_records][columns];
    std::string temp_db[max_records][columns];
    void save_to_file(std::string database_to_save[][columns], std::string file_name = main_file_name);
    void read_from_file(std::string target_database[][columns], std::string file_name = main_file_name);

public:
    baza_pojazdow(); // funkcja wywolywana przy imporcie
    void add_record(std::string data[]);
    void read_record();
    void update_file();
};