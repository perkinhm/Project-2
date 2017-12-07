
#ifndef player_data_h
#define player_data_h

#include <fstream>
#include <string>

class player_data {
public:
    player_data() : name("no name"), year_born(0), category("no category"), paid("can't be determine") {};
    player_data(const std::string & name0, const int & year_born0, const std::string & category0, std::string paid0) : name(name0), year_born(year_born0), category(category0), paid(paid0) {};
    
    std::string name;
    int year_born;
    std::string category;
    std::string paid;
};

#endif /* player_data_h */
