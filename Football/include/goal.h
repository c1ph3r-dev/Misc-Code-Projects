#ifndef JRAMPERSAD_FOOTBALL_GOAL_H
#define JRAMPERSAD_FOOTBALL_GOAL_H

namespace JRAMPERSAD
{
	struct SGoal
    {
		unsigned short TimeScored;
		class Player* Scorer;
		Player* Assister;
        SGoal(unsigned short time, Player* scorer, Player* assister = nullptr) : TimeScored(time), Scorer(scorer), Assister(assister) {}
		~SGoal() = default;
    };
}

#endif // JRAMPERSAD_FOOTBALL_GOAL_H