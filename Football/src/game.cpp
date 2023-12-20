#include "../include/game.h"

namespace JRAMPERSAD
{
	Game::Game(Team& team1, Team& team2) : Team1(&team1), Team2(&team2), bInProgress(true)
	{
	}

	Team* Game::GetWinner() const
	{
		if(Team1Goals.size() == Team2Goals.size()) return nullptr;

		return Team1Goals.size() > Team2Goals.size() ? Team1 : Team2;
	}

	Team* Game::EndGame()
	{
		bInProgress = false;
		return GetWinner();
	}

	void Game::GoalScored(bool bIsTeam1, unsigned short TimeScored, Player* Scorer, Player* Assister)
	{
		if(!bInProgress) return;

		if(bIsTeam1)
			Team1Goals.push_back(SGoal(TimeScored, Scorer, Assister));
		else
			Team2Goals.push_back(SGoal(TimeScored, Scorer, Assister));
	}
}