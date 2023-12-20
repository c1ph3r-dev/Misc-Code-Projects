#ifndef JRAMPERSAD_FOOTBALL_LEAGUE_H
#define JRAMPERSAD_FOOTBALL_LEAGUE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ostream>
#include <sstream>

#include "utils.h"
#include "game.h"

namespace JRAMPERSAD
{
	class Team;

	struct Stats
	{
		unsigned int games_played = 0;
		unsigned int wins = 0;
		unsigned int draws = 0;
		unsigned int losses = 0;
		unsigned int goals_scored = 0;
		unsigned int goals_conceded = 0;
		int goals_difference = 0;
		unsigned int pts = 0;

		void Update(bool bDraw, bool bWin = false, unsigned int Goals_Scored = 0, unsigned int Goals_Conceded = 0)
		{
			if(bDraw) draws++;
			else if(bWin) wins++;
			else losses++;

			goals_scored += Goals_Scored;
			goals_conceded += Goals_Conceded;
			goals_difference = goals_scored - goals_conceded;

			pts = (wins * 3) + draws;
		}

		friend bool operator<(const Stats& lhs, const Stats& rhs)
		{
			if (rhs.pts < lhs.pts) return true;
				
			if (rhs.goals_difference == lhs.goals_difference)
			{
				return (rhs.goals_scored < lhs.goals_scored);
			}
			else
			{
				return (rhs.goals_difference < lhs.goals_difference);
			}
		}

		friend std::ostream &operator<<(std::ostream &os, const Stats &obj)
		{
			std::stringstream ss;

			ss << obj.wins << '\t';
			ss << obj.draws << '\t';
			ss << obj.losses << '\t';
			ss << obj.goals_scored << '\t';
			ss << obj.goals_conceded << '\t';
			ss << obj.goals_difference << '\t';
			ss << obj.pts << '\n';

			os << ss.str();
			return os;
		}
	};

	struct Table
	{
		std::vector<std::pair<Team*, Stats>> Standings;		
		void SortStandings()
		{
			auto sortbysec = [](const std::pair<Team*, Stats>& a,
				const std::pair<Team*, Stats>& b)
				{
					return (a.second < b.second);
				};

			std::sort(Standings.begin(), Standings.end(), sortbysec);
		}

		Stats GetPosition(int pos) const {return Standings[pos].second;}

		friend std::ostream &operator<<(std::ostream &os, const Table &tb);
	};

	class League
	{
		std::string Name;
		size_t TotalNoOfTeams;
		std::vector<Team*> Teams;
		Table LeagueTable;

	public:
		League(const std::string& LeagueName, size_t TotalNumOfTeams = 20) : Name(LeagueName), TotalNoOfTeams(TotalNumOfTeams) 
		{
			Teams.reserve(TotalNumOfTeams);
		}
		void InitializeLeague(const std::vector<Team*>& teams);
		void GamePlayed(Game* game);

		GETTER_FUNC(Table, LeagueTable)

	};
}

#endif // JRAMPERSAD_FOOTBALL_LEAGUE_H