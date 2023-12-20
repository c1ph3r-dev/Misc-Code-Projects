#ifndef JRAMPERSAD_FOOTBALL_GAME_H
#define JRAMPERSAD_FOOTBALL_GAME_H

#include <vector>

#include "goal.h"

namespace JRAMPERSAD
{
	class Team;
	class Player;

	class Game
	{
		Team* Team1;
		std::vector<SGoal> Team1Goals;
		Team* Team2;
		std::vector<SGoal> Team2Goals;

		bool bInProgress;

		Team* GetWinner() const;
	public:
		Game(Team& team1, Team& team2);
		Team* EndGame();

		void GoalScored(bool bIsTeam1, unsigned short TimeScored, Player* Scorer, Player* Assister = nullptr);

		inline Team* GetTeam1() const { return Team1; }
		inline Team* GetTeam2() const { return Team2; }

		inline const std::vector<SGoal>& GetTeam1Goals() const { return Team1Goals; }
		inline const std::vector<SGoal>& GetTeam2Goals() const { return Team2Goals; }
	};

#define NEW_GAME(game_name, Team1, Team2) \
Game game_name = Game(Team1, Team2)

}
#endif // JRAMPERSAD_FOOTBALL_GAME_H