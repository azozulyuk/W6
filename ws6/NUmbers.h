
/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: 6
Filename: NUmber.h
-----------------------------------------------------------
Author: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/03/13  Completing code
V0.8    2025/03/14  Debugged DMA
V0.9    -         Asked prof for help for XYZ
V1.0    2026/03/15  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function main,ect.
-----------------------------------------------------------
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_NUMBERS_H
#define SENECA_NUMBERS_H

#include <iostream>

namespace seneca {

    class Numbers {
  double* m_numbers{};
char* m_filename{};
bool m_isOriginal{};
 size_t m_numCount{};

 bool isEmpty() const;
  void setEmpty();
   void setFilename(const char* filename);
void sort();
  double max() const;
double min() const;
double average() const;
size_t numberCount() const;
bool load();
  void save() const;
public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers& src);
        Numbers& operator=(const Numbers& src);
        ~Numbers();

      Numbers& operator+=(double value);

     std::ostream& display(std::ostream& ostr) const;
    };

  std::ostream& operator<<(std::ostream& os, const Numbers& N);
  std::istream& operator>>(std::istream& istr, Numbers& N);

}

#endif