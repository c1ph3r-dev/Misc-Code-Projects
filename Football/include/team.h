#ifndef JRAMPERSAD_FOOTBALL_TEAM_H
#define JRAMPERSAD_FOOTBALL_TEAM_H

// STD Lib includes
#include <string>
#include <vector>

// Internal includes
#include "utils.h"

namespace JRAMPERSAD
{
	class Player;

	class Team
	{
    	std::string TeamName;
		std::string ShortName;
    	std::vector<Player*> Players;
	
		public:
    	Team(std::string name, std::string shortName) : TeamName(name), ShortName(shortName) {}
    	Player* GetPlayerByName(const std::string& name) const;
    	void AddPlayer(Player& player);
		void RemovePlayer(Player& player);
    	void SetPlayerShirtNumber(std::string PlayerName, const unsigned short& PlayerNumber);
	
		inline std::string GetShortName() const { return ShortName; }

    	CLASS_ACCESSORS(std::string, TeamName)
    	GETTER_FUNC(std::vector<Player*>, Players)
	}; 
}

#endif // JRAMPERSAD_FOOTBALL_TEAM_H