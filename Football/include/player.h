#ifndef JRAMPERSAD_FOOTBALL_PLAYER_H
#define JRAMPERSAD_FOOTBALL_PLAYER_H

// STD Lib includes
#include <string>
#include <vector>

// Internal includes
#include "utils.h"


namespace JRAMPERSAD
{
  class Player
  {
  private:
    std::string Name;
    EPosition Position;
    class Team* TeamPlayedFor;
    unsigned short ShirtNumber;
    std::vector<Team*> TeamHistory;
    unsigned int NoOfGoals;
    unsigned int NoOfAssists;
  public:
    Player() = default;
    Player(std::string name, EPosition position) : 
    Name(name), Position(position), TeamPlayedFor(nullptr), ShirtNumber(0), NoOfGoals(0), NoOfAssists(0)
    {}

    void Transfer(Team& NewTeam);
    inline void GoalScored() { NoOfGoals++; }
    inline void AddAssist() { NoOfAssists++; }

    GETTER_FUNC(std::string, Name)
    CLASS_ACCESSORS(EPosition, Position)
    GETTER_FUNC(Team*, TeamPlayedFor)
    CLASS_ACCESSORS(unsigned short, ShirtNumber)
    GETTER_FUNC(unsigned int, NoOfGoals)
    GETTER_FUNC(unsigned int, NoOfAssists)

    inline Team* GetTeamFromHistory(int Index) const { return TeamHistory[Index]; }
  };
}

#endif // JRAMPERSAD_FOOTBALL_PLAYER_H