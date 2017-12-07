#include "list.h"

#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <map>
using std::pair;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;

void PlayerList::read_file()
{
    cout << "file name: ";
    cin >> file_name;
    cout << "season year: ";
    cin >> current_year;
    while (cin.fail()) {
        cout << "Error. Not an integer. Try again" << endl;
        cin.clear();
        cin.ignore();
        cin >> current_year;
    }
    ifstream ifs(file_name);
    if (!ifs) return;
    
    string temp_name;
    while (getline(ifs, temp_name)) {
        PlayerEntry new_entry;
        new_entry.name = temp_name;
        ifs >> new_entry;
        t_entries.insert({new_entry.name, new_entry});
    }
    itr_current_entry = t_entries.begin();
}

void PlayerList::write_file() {
    ofstream ofs(file_name);
    int i = 0;
    for (itr_current_entry = t_entries.begin(); itr_current_entry != t_entries.end(); itr_current_entry++) {
        ofs << itr_current_entry -> second;
    }
}

void PlayerList:: categorize(const string & new_file_name,const string & category)
{
    ofstream ofs(new_file_name);
    for  (itr_current_entry = t_entries.begin(); itr_current_entry != t_entries.end(); itr_current_entry++) {
        if (itr_current_entry->second.category == category)
            ofs << itr_current_entry -> second;
    }
}

void PlayerList::edit_current()
{
    char option;
    bool answer = false;
    cout << "~~~~~~~~~~~~~~~\nname  year  registration \n~~~~~~~~~~~" << endl << "choice: ";
    while (!answer) {
        cin >> option;
        switch(option) {
            case 'n' : {
                cout<< "name: " ;
                string new_name = "";
                getline (cin,new_name);
                getline (cin, new_name);
                itr_current_entry -> second.name = new_name;
                answer = true;
                break;
            }
            case 'y' : {
                cout << "Year of Birth ";
                int year;
                cin >> year;
                string new_category = "";
                category (year, new_category);
                if (new_category != "none") {
                    itr_current_entry -> second.year_born = year;
                    itr_current_entry -> second.category = new_category;
                } else { cout << "Can not edit player information." << endl; }
                answer = true;
                break;
            }
            case 'r' : {
                cout << "Paid? [y/n] ";
                bool valid = false;
                char status = ' ';
                cin >> status;
                string registration_status = "";
                paid (status, valid, registration_status);
                itr_current_entry -> second.paid = registration_status;
                answer = true;
                break;
            }
        }
    }
    cout << endl;
    display_current_entry();
}

string & PlayerList::category(const int & birth_year, std::string &category)
{
    int age = current_year - birth_year;
    string category_num = "0";
    
    if (age < 4 || age > 16) {
        cout << "Player isn't in the age range" << endl;
        category = "none";
    } else {
        if (age < 6) {
            category_num = "6";
        } else if (age < 8) {
            category_num = "8";
        } else if (age < 10) {
            category_num = "10";
        } else if (age < 12) {
            category_num = "12";
        } else if (age < 14) {
            category_num = "14";
        } else if (age < 17) {
            category_num = "17";
        }
        category = "U" + category_num;
    }
    
    return category;
}

string & PlayerList::paid (char answer, bool & valid, string & registration_status)
{
    switch (answer) {
        case 'y' : {
            registration_status = "paid";
            valid = true;
            break;
        }
        case 'n' : {
            registration_status = "not paid";
            valid = true;
            break;
        }
    }
    return registration_status;
}

