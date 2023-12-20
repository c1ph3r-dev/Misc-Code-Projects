#include "../include/team.h"
#include "../include/player.h"

#include <iostream>

namespace JRAMPERSAD
{
	Player* Team::GetPlayerByName(const std::string& name) const
	{
        for(auto player : Players)
            if(player->GetName() == name) return player;

        std::cout << "Player does not exist, please check spelling\n";
        return nullptr;
    }

	void Team::AddPlayer(Player& player)
	{
        Players.push_back(&player);
    }

	void Team::RemovePlayer(Player& player)
	{
		RemoveItemFromVector(Players, player);
	}

	void Team::SetPlayerShirtNumber(std::string PlayerName, const unsigned short& PlayerNumber)
	{
		if(auto player = GetPlayerByName(PlayerName))
			player->SetShirtNumber(PlayerNumber);
	}
}