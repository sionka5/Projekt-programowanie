#include "database.h"

//prywatne

//przy imporcie pobierz dane z pliku 
baza_pojazdow::baza_pojazdow() 
{
    read_from_file(db);
}

void baza_pojazdow::add_record(std::string data[])
{
    for (int i = 0; i < columns; i++)
    {
        db[number_of_records][i] = data[i];
    }
            
    number_of_records++;
            
}

void baza_pojazdow::read_record()
{
    for (int i = 0; i < number_of_records; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << db[i][j] << " ";
        }
        std::cout << std::endl;
    }
          
}

void baza_pojazdow::save_to_file(std::string database_to_save[][columns], std::string file_name)
{
    std::ofstream F(file_name);
    for (int i = 0; i < number_of_records; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            F << database_to_save[i][j] << "  ";
        }
        F << "\n";
    }
    F.close();
}

void baza_pojazdow::read_from_file(std::string target_database[][columns], std::string file_name)
{
    std::string line;
    std::ifstream F(file_name);
    while (getline(F, line))
    {
        std::istringstream ss(line);
        std::string d;
        int number_of_columns = 0;

        while (ss >> d && number_of_columns < columns)
        {
            target_database[number_of_records][number_of_columns] = d;
            number_of_columns++;
        }
        number_of_records++;
    }
    F.close();
}

//publiczne

void baza_pojazdow::update_file()
{
    //do dopracowania bledy przy odczycie wynikajace z roznicy ilosci linijek w backupie i normalnym pliku
    //docelowo update pliku po kazdym zapisie
    //read_from_file(temp_db);
    //save_to_file(temp_db, "backup_pojazdy.txt");
    
    save_to_file(db);
}


