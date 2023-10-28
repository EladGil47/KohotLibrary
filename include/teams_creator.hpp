#ifndef KOHOT_TEAMS_CREATOR_HPP
#define KOHOT_TEAMS_CREATOR_HPP

#include <vector>
#include <memory>

#include "player.hpp"
#include "team.hpp"
#include "paths.hpp"



class TeamsCreator 
{
public:
	static std::shared_ptr<std::vector<std::shared_ptr<Team>>> createTeams(std::vector<std::shared_ptr<Player>> players, const uint16_t teams_amount, const uint16_t players_in_team_amount);
	static void serializeTeams(std::shared_ptr<std::vector<std::shared_ptr<Team>>> teams,const char * file_path = Paths::TEAMS_FILE_PATH);
};

#endif //KOHOT_TEAMS_CREATOR_HPP
