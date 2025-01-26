#include "Customer.hpp"

Customer::Customer(const std::string& name, const std::string& phoneNum, const std::string& bankInfo)
    : name(name), phoneNum(phoneNum), bankInfo(bankInfo) {}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getPhoneNum() const {
    return phoneNum;
}

std::string Customer::getBankInfo() const {
    return bankInfo;
}

void Customer::setName(const std::string& name) {
    this->name = name;
}

void Customer::setPhoneNum(const std::string& phoneNum) {
    this->phoneNum = phoneNum;
}

void Customer::setBankInfo(const std::string& bankInfo) {
    this->bankInfo = bankInfo;
}


