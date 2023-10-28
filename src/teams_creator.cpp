#include "teams_creator.hpp"
#include "players_sorter.hpp"

#include "json_utils.hpp"

#include <iostream>

std::shared_ptr<std::vector<std::shared_ptr<Team>>> TeamsCreator::createTeams(std::vector<std::shared_ptr<Player>> players, const uint16_t teams_amount, const uint16_t players_in_team_amount)
{

    std::shared_ptr<std::vector<std::shared_ptr<Team>>> m_teams = std::make_shared<std::vector<std::shared_ptr<Team>>>();

    for (uint16_t team_index = 0; team_index < teams_amount; team_index++) {
        m_teams->push_back(std::make_shared<Team>(team_index));
    }

	PlayersSorter::sortBySortOption(players, PlayersSorter::SortOptions::RATE);

	int i = 0;
	bool directLeft = true;
	for (int player_index = 0;player_index < players_in_team_amount; player_index++)
	{
		if (directLeft)
		{
			for (uint16_t team_index = 0; team_index < teams_amount;team_index++)
			{
				(*m_teams)[team_index]->addPlayer(players[i]);

				if (team_index == teams_amount-1)
				{
					directLeft = false;
				}
				i++;
			}
		}
		else
		{
			for (int team_index = teams_amount-1; team_index >= 0;team_index--)
			{
				(*m_teams)[team_index]->addPlayer(players[i]);
				if (team_index == 0)
				{
					directLeft = true;
				}
				i++;
			}
		}
	}

	return m_teams;
}

void TeamsCreator::serializeTeams(std::shared_ptr<std::vector<std::shared_ptr<Team>>> teams,const char * file_path)
{
	nlohmann::json data;

	nlohmann::json& teams_array = data["Teams"];
	teams_array = nlohmann::json::array();

	uint16_t team_index = 0;
	for (std::shared_ptr<Team> team : *teams)
	{
		nlohmann::json& json_team = teams_array[team_index];

		json_team["Id"] = team->getId();
		json_team["Name"] = team->getName();

		nlohmann::json& players_array = json_team["Players"];
		players_array = nlohmann::json::array();
			
		uint16_t player_index = 0;
		for (std::shared_ptr<Player> player : team->getPlayersCollection()->getCollection())
		{
			nlohmann::json& json_player = players_array[player_index];

			json_player["Id"] = player->getId();
			json_player["Name"] = player->getName();
			json_player["Role"] = player->getRoleText();

			player_index++;
		}
		team_index++; 
	}

	JsonUtils::serializeJson(data, file_path);

}
