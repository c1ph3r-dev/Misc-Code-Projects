#include "../include/league.h"

#include "../include/team.h"

namespace JRAMPERSAD
{
	void League::InitializeLeague(const std::vector<Team*>& teams) 
		{ 
			for(auto& team : teams) 
			{
				Teams.push_back(team);
				LeagueTable.Standings.push_back({team, Stats{}});
			}
		}

	void League::GamePlayed(Game* game)
		{
			auto winningTeam = game->EndGame();
			if(winningTeam == nullptr)
			{
				for(auto& [team, stats] : LeagueTable.Standings)
				{
					if(team == game->GetTeam1())
					{
						stats.games_played++;
						stats.Update(true, true, game->GetTeam1Goals().size(), game->GetTeam2Goals().size());
					}
					else if(team == game->GetTeam2())
					{
						stats.games_played++;
						stats.Update(true, false, game->GetTeam2Goals().size(), game->GetTeam1Goals().size());
					}
				}
			}
			else if (game->GetTeam1() == winningTeam)
			{
				for(auto& [team, stats] : LeagueTable.Standings)
				{
					if(team == game->GetTeam1())
					{
						stats.games_played++;
						stats.Update(false, true, game->GetTeam1Goals().size(), game->GetTeam2Goals().size());
					}
					else if(team == game->GetTeam2())
					{
						stats.games_played++;
						stats.Update(false, false, game->GetTeam2Goals().size(), game->GetTeam1Goals().size());
					}
				}
			}
			else
			{
				for(auto& [team, stats] : LeagueTable.Standings)
				{
					if(team == game->GetTeam1())
					{
						stats.games_played++;
						stats.Update(false, false, game->GetTeam1Goals().size(), game->GetTeam2Goals().size());
					}
					else if(team == game->GetTeam2())
					{
						stats.games_played++;
						stats.Update(false, true, game->GetTeam2Goals().size(), game->GetTeam1Goals().size());
					}
				}
			}

			LeagueTable.SortStandings();
		}

	std::ostream &operator<<(std::ostream &os, const Table &tb)
	{
		int pos = 1;
		os << "Pos\t" << "Team\t" << "Wins\t" << "Draws\t" << "Loss\t" << "GF\t" << "GA\t" << "GD\t" << "Pts\n";
		for(const auto& [team, stats] : tb.Standings)
		{
			std::stringstream ss;
			ss << pos << '\t';
			pos++;
			ss << team->GetShortName() << '\t';
			os << ss.str();
			os << stats;
		}
		return os;
	}
}