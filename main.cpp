#include <iostream>
#include "SpreadSheet.h"

int main() 
{
    Spreadsheet sheet(5, 5);

    sheet.setCellValue(0, 0, "sheet");
    sheet.setCellValue(1, 1, "3.14");
    sheet.setCellValue(2, 2, "555");

    std::cout << "Original Row Count: " << sheet.rowCount() << std::endl;
    std::cout << "Original Column Count: " << sheet.columnCount() << std::endl;

    sheet.addRow();
    sheet.addColumn();

    std::cout << "After Adding Row and Column:" << std::endl;
    std::cout << "Row Count: " << sheet.rowCount() << std::endl;
    std::cout << "Column Count: " << sheet.columnCount() << std::endl;

    std::cout << "Value at (0, 0): " << sheet.getCellValue(0, 0) << std::endl;
    std::cout << "Value at (1, 1): " << sheet.getCellValue(1, 1) << std::endl;

    
    std::cout << "Spreadsheet Contents:" << std::endl;
    sheet.m_print();

    sheet.removeRow();
    sheet.removeColumn();

    std::cout << "After Removing Row and Column:" << std::endl;
    std::cout << "Row Count: " << sheet.rowCount() << std::endl;
    std::cout << "Column Count " << sheet.columnCount() << std::endl;

    return 0;
}
