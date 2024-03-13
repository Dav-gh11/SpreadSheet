#ifndef SPREADSHEET
#define SPREADSHEET
#include <iostream>
#include "SpreadSheetCell.h"

class Spreadsheet
{
public:
    Spreadsheet(int rows, int columns);
    ~Spreadsheet();

    void setCellValue(int row, int column, const std::string &value);
    std::string getCellValue(int row, int column) const;
    int rowCount() const { return m_row; }
    int columnCount() const { return m_column; }
    void addRow();
    void addColumn();
    void removeRow();
    void removeColumn();
    void m_print() const;
    SpreadsheetCell getCell(int row, int column) const;
    void setCell(int row, int column, const std::string &value);

private:
    SpreadsheetCell **m_table;
    int m_row;
    int m_column;
};

Spreadsheet::Spreadsheet(int rows, int columns)
    : m_row(rows), m_column(columns)
{
    m_table = new SpreadsheetCell *[m_row];
    for (int i = 0; i < m_row; ++i)
    {
        m_table[i] = new SpreadsheetCell[m_column];
    }
}

Spreadsheet::~Spreadsheet()
{
    for (int i = 0; i < m_row; ++i)
    {
        delete[] m_table[i];
    }
    delete[] m_table;
}

void Spreadsheet::setCellValue(int row, int column, const std::string &value)
{
    if (row >= 0 && row < m_row && column >= 0 && column < m_column)
    {
        m_table[row][column].setStringValue(value);
    }
}

std::string Spreadsheet::getCellValue(int row, int column) const
{
    if (row >= 0 && row < m_row && column >= 0 && column < m_column)
    {
        return m_table[row][column].getStringValue();
    }
    return "";
}

void Spreadsheet::addRow()
{
    SpreadsheetCell **newTable = new SpreadsheetCell *[m_row + 1];
    for (int i = 0; i < m_row; ++i)
    {
        newTable[i] = m_table[i];
    }
    newTable[m_row] = new SpreadsheetCell[m_column];
    ++m_row;
    delete[] m_table;
    m_table = newTable;
}

void Spreadsheet::addColumn()
{
    for (int i = 0; i < m_row; ++i)
    {
        SpreadsheetCell *newRow = new SpreadsheetCell[m_column + 1];
        for (int j = 0; j < m_column; ++j)
        {
            newRow[j] = m_table[i][j];
        }
        delete[] m_table[i];
        m_table[i] = newRow;
    }
    ++m_column;
}

void Spreadsheet::removeRow()
{
    if (m_row <= 0) return;

    delete[] m_table[m_row - 1];
    --m_row;
}

void Spreadsheet::removeColumn()
{
    if (m_column <= 0) return;

    for (int i = 0; i < m_row; ++i)
    {
        SpreadsheetCell *newRow = new SpreadsheetCell[m_column - 1];
        for (int j = 0; j < m_column - 1; ++j)
        {
            newRow[j] = m_table[i][j];
        }
        delete[] m_table[i];
        m_table[i] = newRow;
    }
    --m_column;
}

SpreadsheetCell Spreadsheet::getCell(int row, int column) const
{
    if (row >= 0 && row < m_row && column >= 0 && column < m_column)
    {
        return m_table[row][column];
    }
    return SpreadsheetCell();  
}

void Spreadsheet::setCell(int row, int column, const std::string &value)
{
    setCellValue(row, column, value);
}

void Spreadsheet::m_print() const
{
    for (int j = 0; j < m_column; ++j)
    {
        std::cout << "|------";  
    }
    std::cout << "|" << std::endl;

    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_column; ++j)
        {
            std::string cell = m_table[i][j].getStringValue();
            std::cout << "| " << cell;
            for (int l = cell.length(); l < 5; ++l)
                std::cout << " ";
        }
        std::cout << "|" << std::endl;

        for (int j = 0; j < m_column; ++j)
        {
            std::cout << "|------"; 
        }
        std::cout << "|" << std::endl;
    }
}



#endif