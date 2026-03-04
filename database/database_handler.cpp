#include "database_handler.h"

//prywatne







//publiczne
void database::init(int rows, std::string name)
{
    number_of_rows = rows;
    database_name = name;

    read_from_file();
}

void database::add_record(std::vector<std::string> data)
{


    db.push_back(data);


    number_of_records++;

}

void database::read_record()
{
    for (int i = 0; i < number_of_records; i++)
    {
        for (int j = 0; j < number_of_rows; j++)
        {
            std::cout << db[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void database::save_to_file()
{
    std::ofstream F(database_name + ".txt");
    for (int i = 0; i < number_of_records; i++)
    {
        for (int j = 0; j < db[0].size(); j++)
        {
            F << db[i][j] << "  ";
        }
        F << "\n";
    }
    F.close();
}

void database::read_from_file()
{   
    std::string line;
    std::ifstream F(database_name + ".txt");
    

    if (F.is_open())
    {
        while (getline(F, line))
        {
            std::stringstream ss(line);
            std::vector<std::string> row;
            std::string value;
            while (ss >> value) {
                row.push_back(value);
            }
            if (!row.empty())
            {
                db.push_back(row);
                number_of_records++;
                //for (std::string x : row) 
                //{
                //    std::cout << x << "-";
                //}
            }

        }
        F.close();
    }
}







