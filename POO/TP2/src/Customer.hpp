#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>

class Customer {
private:
    std::string name;
    std::string phoneNum;
    std::string bankInfo;

public:
    Customer(const std::string& name, const std::string& phoneNum, const std::string& bankInfo);
    std::string getName() const;
    std::string getPhoneNum() const;
    std::string getBankInfo() const;
    void setName(const std::string& name);
    void setPhoneNum(const std::string& phoneNum);
    void setBankInfo(const std::string& bankInfo);
    
};

#endif // CUSTOMER_HPP
