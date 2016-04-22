#ifndef SALE_DATA_H
#define SALE_DATA_H
#include <string>
#include <iostream>
using namespace std;
class Sales_Data {
    extern friend Sales_Data add(const Sales_Data&, const Sales_Data&);
    extern friend std::ostream &print(std::ostream&, const Sales_Data&);
    extern friend std::istream &read(std::istream&, Sales_Data&);
public:
    Sales_Data() = default;
    Sales_Data(std::istream &);
    /*explicit */Sales_Data(const std::string &s) :bookNo(s) {}
    Sales_Data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_Data &combine(const Sales_Data &);
    std::string isbn() const { return bookNo; }
private:
    double avg_price() const { return units_sold ? revenue / units_sold : 0; }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
extern Sales_Data add(const Sales_Data&, const Sales_Data&);
extern std::ostream &print(std::ostream&, const Sales_Data&);
extern std::istream &read(std::istream&, Sales_Data&);
#endif