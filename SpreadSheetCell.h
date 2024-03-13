#ifndef SPREADSHEETCELL
#define SPREADSHEETCELL
#include <iostream>
#include <string>
#include <cstdlib> 

class SpreadsheetCell
{
public:
    SpreadsheetCell() : value("") {}
    SpreadsheetCell(const std::string &val) : value(val) {}

    void setStringValue(const std::string &val) 
    {
        value = val;
    }
    
    std::string getStringValue() const 
    {
        return value;
    }

    int getIntValue() const 
    {
        return std::stoi(value);
    }

    double getDoubleValue() const 
    {
        return std::stod(value);
    }

private:
    std::string value;
};

#endif  