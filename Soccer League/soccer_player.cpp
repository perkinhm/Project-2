

inline void Player::display_menu() const
{
    using std::cout;
    using std::endl;
    using std::string;
    
    string long_separator(40, '~');
    string short_separator(10, '~');
    
    cout << long_separator << endl
    << "Menu:\nsearch   add    list   new   quit \n"
    << short_separator << endl;
    
}
