#include "../include/league.h"
#include "../include/player.h"
#include "../include/team.h"

#include <iostream>

using namespace JRAMPERSAD;

int main()
{
	Player p;

	Team team1("Tottenham", "TOT"), team2("Bayern Munich", "BAY"), team3("Chelsea", "CHE"), team4("Arsenal", "ARS"), team5("West Ham", "WHU");
	std::vector<Team*> teams;
	teams.push_back(&team1);
	teams.push_back(&team2);
	teams.push_back(&team3);
	teams.push_back(&team4);
	teams.push_back(&team5);
	League TestLeague("Test", 5);
	TestLeague.InitializeLeague(teams);

	NEW_GAME(Game1, team2, team4);
	Game1.GoalScored(true, 1, &p);
	Game1.GoalScored(false, 75, &p);
	Game1.GoalScored(true, 89, &p);
	

	NEW_GAME(Game2, team3, team1);
	Game2.GoalScored(true, 1, &p);
	Game2.GoalScored(false, 12, &p);
	Game2.GoalScored(false, 75, &p);
	Game2.GoalScored(true, 89, &p);
	
	TestLeague.GamePlayed(&Game2);
	TestLeague.GamePlayed(&Game1);
	auto s = TestLeague.GetLeagueTable();
	std::cout << s << std::endl;

	return 0;
}