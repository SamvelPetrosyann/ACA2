
#include <iostream>
#include <fstream>
#include <string>

union Data 
{
    int intValue;
    double doubleValue;
    char stringValue[100];
};

enum class DataType 
{ 
    INTEGER, DOUBLE, STRING 
    
};

bool isInteger(const std::string& str)
{
    if (str.empty())
    {
        return false;
    }
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}

bool isDouble(const std::string& str)
{
    bool dotSeen = false;

    if (str.empty())
    {
        return false;
    }

    for(int i = 0; i < str.length(); ++i) 
    {
        if (str[i] == '.') 
        {
            if (dotSeen) 
            {
                return false; 
            }
            dotSeen = true;
        } 
        else if (str[i] < '0' || str[i] > '9') 
        {
            return false;
        }
    }

    return dotSeen; 
}

DataType getType(const std::string& str) 
{
    if (isInteger(str)) 
    {
        return DataType::INTEGER;
    } 
    else if (isDouble(str)) 
    {
        return DataType::DOUBLE;
    } 
    else 
    {
        return DataType::STRING;
    }
}

int main()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) 
    {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line)) 
    {
        Data data;
        switch (getType(line)) 
        {
            case DataType::INTEGER:
                data.intValue = std::stoi(line);
                std::cout << "Integer: " << data.intValue << std::endl;
                break;
            case DataType::DOUBLE:
                data.doubleValue = std::stod(line);
                std::cout << "Double: " << data.doubleValue << std::endl;
                break;
            case DataType::STRING:
                std::cout << "String: " << line << std::endl;
                break;
        }
    }
    inputFile.close();

    return 0;
}
