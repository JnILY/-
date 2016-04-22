#include "Sales_Data.h"
Sales_Data& Sales_Data::combine(const Sales_Data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
istream &read(istream &is, Sales_Data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_Data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price() << std::endl;
    return os;
}
Sales_Data add(const Sales_Data &lhs, const Sales_Data &rhs)
{
    Sales_Data sum = lhs;
    sum.combine(rhs);
    return sum;
}
Sales_Data::Sales_Data(std::istream &is)
{
    read(is, *this);
}