

#ifndef soccer_player_h
#define soccer_player_h

class Player
{
public:
    void run();
    
private:
    void display_menu() const;
    void execute (char command, bool & done);
    PlayerList entry_list;
};

#endif /* soccer_player_h */
