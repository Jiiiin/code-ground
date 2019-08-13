#include"Sales_data.h"
Sales_data::Sales_data(std::istream &is)
{
    double price;
    is>>(*this).bookNo>>(*this).units_sold>>price;
    (*this).revenue=price*(*this).units_sold;
    //与前三行功能相同
    //read(is,*this);
} 
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold+=rhs.units_sold;
    revenue+=rhs.revenue;
    return *this;
}
/* double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
} */
Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum=lhs;
    sum.combine(rhs);
    return sum;
}
std::ostream &print(std::ostream &os,const Sales_data &item)
{
    os<<item.bookNo<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}
std ::istream &read(std::istream &is,Sales_data &item)
{
    double price=0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}



