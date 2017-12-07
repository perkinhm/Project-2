//list.h

#include <iostream>
#include <map>
#include <string>

#include "player_data.h"

class PlayerList
{
public:
    PlayerList() : itr_current_entry(t_entries.end()) {}
    void set_file_name(const std::string & n) {file_name = n;}
    void set_current_year (const int & y) { current_year = y; }
    void add (const std::string & name, const int & year_born, const std::string & category, const std::string & paid);
    void display_current_entry () const;
    void edit_current ();
    void find (const std::string & name);
    void read_file ();
    void write_file ();
    void categorize(const std::string & new_file_name, const std::string & category);
    bool empty() const { return t_entries.empty(); }
    std::string & category(const int & birth_year, std::string &category);
    std::string & paid(char answer, bool & valid, std::string & registration_status);
    void new_season();
private:
    std::map<std::string, PlayerEntry> t_entries;
    std::map<std::string, PlayerEntry>::iterator itr_current_entry;
    std::string file_name;
    int current_year = 0;
};

inline void PlayerList::new_season()
{
    t_entries.erase(t_entries.begin(), t_entries.end());
}

inline void PlayerList::add(const std::string & name, const int & year_born, const std::string & category, const std::string & paid)
{
    auto result = t_entries.insert( {name,{name, year_born, category, paid}});
    itr_current_entry= result.first;
    display_current_entry();
}

inline void PlayerList::display_current_entry () const
{
    if (t_entries.empty()) return;
    std::cout << itr_current_entry -> second << std::endl;
}

inline void PlayerList::find(const std::string & name)
{
    auto itr = t_entries.find(name);
    if (itr != t_entries.end()) {itr_current_entry = itr;}
    else {std::cout << "Player was not found ";}
    display_current_entry();
}

