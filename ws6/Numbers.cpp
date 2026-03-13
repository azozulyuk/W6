
/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: 6
Filename: Numbers.cpp
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
#include "Numbers.h"
#include <fstream>
#include <iomanip>

using namespace std;

namespace seneca {



 

    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    Numbers::Numbers(const Numbers& src) {
        setEmpty();
        m_isOriginal = false;

        if (!src.isEmpty()) {
            m_numCount = src.m_numCount;
            m_numbers = new double[m_numCount];

            for (size_t i = 0; i < m_numCount; i++) {
                m_numbers[i] = src.m_numbers[i];
            }
        }
    }

    Numbers& Numbers::operator=(const Numbers& src) {

        if (this != &src) {

            delete[] m_numbers;
            m_numbers = nullptr;

            if (!src.isEmpty()) {

                m_numCount = src.m_numCount;
                m_numbers = new double[m_numCount];

                for (size_t i = 0; i < m_numCount; i++) {
                    m_numbers[i] = src.m_numbers[i];
                }
            }
        }

        return *this;
    }

    size_t Numbers::numberCount() const {

        ifstream file(m_filename);
        size_t count = 0;
        char ch;

        while (file.get(ch)) {
            if (ch == '\n') {
                count++;
            }
        }

        return count;
    }

    bool Numbers::load() {

        bool ok = false;

        if (m_numCount > 0) {

            m_numbers = new double[m_numCount];

            ifstream file(m_filename);

            size_t i = 0;

            while (file && i < m_numCount) {

                file >> m_numbers[i];

                if (file) {
                    i++;
                }
            }

            if (i == m_numCount) {
                ok = true;
            }
            else {
                delete[] m_numbers;
                setEmpty();
            }
        }

        return ok;
    }

    void Numbers::save() const {

        if (m_isOriginal && !isEmpty()) {

            ofstream file(m_filename);

            for (size_t i = 0; i < m_numCount; i++) {
                file << m_numbers[i] << endl;
            }
        }
    }

    Numbers& Numbers::operator+=(double value) {

        if (!isEmpty()) {

            double* temp = new double[m_numCount + 1];

            for (size_t i = 0; i < m_numCount; i++) {
                temp[i] = m_numbers[i];
            }

            m_numCount++;

            temp[m_numCount - 1] = value;

            delete[] m_numbers;

            m_numbers = temp;

            sort();
        }

        return *this;
    }

    ostream& Numbers::display(ostream& ostr) const {

        if (isEmpty()) {

            ostr << "Empty list";

        }
        else {

            ostr << fixed << setprecision(2);

            ostr << "=========================" << endl;

            if (m_isOriginal)
                ostr << m_filename << endl;
            else
                ostr << "*** COPY ***" << endl;

            for (size_t i = 0; i < m_numCount; i++) {

                ostr << m_numbers[i];

                if (i != m_numCount - 1) {
                    ostr << ", ";
                }
            }

            ostr << endl;

            ostr << "-------------------------" << endl;

            ostr << "Total of " << m_numCount << " number(s)" << endl;

            ostr << "Largest number:  " << max() << endl;

            ostr << "Smallest number: " << min() << endl;

            ostr << "Average:         " << average() << endl;

            ostr << "=========================";
        }

        return ostr;
    }

    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    }

    istream& operator>>(istream& istr, Numbers& N) {

        double value;

        if (istr >> value) {
            N += value;
        }

        return istr;
    }

}