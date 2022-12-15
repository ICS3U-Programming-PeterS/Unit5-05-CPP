// Copyright (c) 2022 Peter Sobowale All rights reserved.
//
// Created by: Peter Sobowale
// Created on: December 6, 2022
// This program asks the user for their mailing information
// and then displays their mailing address formatted

#include <algorithm>
#include <iostream>

// Formats the user's information into a mailing address
std::string Format_Address(std::string name, std::string streetNumber,
                           std::string streetName, std::string city,
                           std::string province, std::string postalCode,
                           std::string apartmentNumber = "") {
    // Declared Variable
    std::string mailingAddress;

    // Concatenates the name to the mailing address (with some carriage returns)
    mailingAddress += "\n" + name + "\n";

    // Checks if the user lives inside of an apartment
    if (apartmentNumber != "") {
        // Adds the apartment number to the mailing address
        mailingAddress += apartmentNumber + "-";
    }

    // Concatenates user's street number, street name, city,
    // province and postal code to the mailing address
    mailingAddress += streetNumber + " " + streetName + "\n";
    mailingAddress += city + " " + province + " " + postalCode;

    // Converts the mailing address to uppercase
    std::transform(mailingAddress.begin(), mailingAddress.end(),
                   mailingAddress.begin(), ::toupper);

    // Returns formatted mailing address to main()
    return mailingAddress;
}

int main() {
    // Declared Variables
    std::string userName, userApartment, userApartmentNum, userStreetNum;
    std::string userStreetName, userCity, userProvince, userPostalCode;
    std::string userMailingAddress;

    // Asks user for their full name
    std::cout << "Enter your full name (ex. Van Nguyen): ";
    std::getline(std::cin, userName);

    // Asks user if they live inside of an apartment
    std::cout << "Do you live in an apartment? (y/n): ";
    std::getline(std::cin, userApartment);

    // Converts user's apartment answer to uppercase
    std::transform(userApartment.begin(), userApartment.end(),
                   userApartment.begin(), ::toupper);

    // IF the user lives inside of an apartment
    if (userApartment == "Y") {
        // Asks user for their apartment number
        std::cout << "Enter your apartment number (ex. 1A, 1B, 2B): ";
        std::getline(std::cin, userApartmentNum);
    }

    // Asks user for their street number
    std::cout << "Enter your street number: ";
    std::getline(std::cin, userStreetNum);

    // Asks user for their street
    std::cout << "Enter your Street Name (ex. Clarence St, Cloudfield Lane): ";
    std::getline(std::cin, userStreetName);

    // Asks user for their city
    std::cout << "Enter your City Name (ex. Toronto): ";
    std::getline(std::cin, userCity);

    // Asks user for their province
    std::cout << "Enter your province in abbreviated form (ex. ON, AL): ";
    std::getline(std::cin, userProvince);

    // Asks user for their postal code
    std::cout << "Enter your postal code (ex. K1S 0E7): ";
    std::getline(std::cin, userPostalCode);

    // Calls function to format a canadian mailing address
    userMailingAddress = Format_Address(userName, userStreetNum, userStreetName,
                                        userCity, userProvince, userPostalCode,
                                        userApartmentNum);

    // Displays to user their formatted
    std::cout << "Your mailing address formatted: "
              << userMailingAddress << std::endl;
}
