
inline std::istream & operator>> (std::istream & in, PlayerEntry & e) {
    //    getline(in, e.name);
    in>>e.year_born;
    in>>e.category;
    in.get();
    getline(in, e.paid);
    return in;
}

inline std:: ostream & operator<< (std::ostream & out, const PlayerEntry & e) {
    out<< e.name << std::endl << e.year_born << std::endl << e.category<< std::endl << e.paid << std::endl;
    return out;
}
