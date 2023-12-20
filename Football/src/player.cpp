#include "../include/player.h"

namespace JRAMPERSAD
{
	void Player::Transfer(Team& NewTeam)
  	{
		TeamPlayedFor = &NewTeam;
  		TeamHistory.push_back(&NewTeam);
	}
}