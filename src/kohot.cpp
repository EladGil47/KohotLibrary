#include "kohot.hpp"

#include "json_utils.hpp"

#include <iostream>

Kohot::Kohot()
{
	m_groups_collection = std::make_shared<GroupsCollection>();
}

std::shared_ptr<GroupsCollection> Kohot::getGroupsCollection()
{
	return m_groups_collection;
}

void Kohot::loadGroups()
{
	nlohmann::json groups_data;
	JsonUtils::deserializeToJson(app_path.getGroupsFilePath().c_str(), groups_data);

	for (const auto& group : groups_data["Groups"]) {
			const Group::Config group_config = {
				static_cast<uint16_t>(m_groups_collection->getSize()),
				group["Name"].get<std::string>(),
				group["Teams"].get<uint16_t>(),
				group["Players_in_team"].get<uint16_t>(),
			};
			std::shared_ptr<Group> group_ptr = std::make_shared <Group>(group_config);

			uint16_t player_id = 0;
			for (const auto& player : group["Players"])
			{
				const Player::Config player_config = {
				player_id++,
				player["Name"].get<std::string>(),
				player["Rate"].get<double>(),
				Player::toPlayerRole( player["Role"].get<std::string>())
				};
				std::shared_ptr<Player> additional_player = std::make_shared<Player>(player_config);
				group_ptr->getPlayersCollectionRef().addItem(additional_player);
			}
			m_groups_collection->addItem(group_ptr);
		}
}

void Kohot::saveGroups() {
	nlohmann::json data;

	nlohmann::json& groups_array = data["Groups"];
	groups_array = nlohmann::json::array();

	uint16_t group_index = 0;
	for (std::shared_ptr<Group> group : m_groups_collection->getCollection())
	{
		nlohmann::json& json_group = groups_array[group_index];

		json_group["Id"] = group->getId();
		json_group["Name"] = group->getName();
		json_group["Teams"] = group->getTeamsAmount();
		json_group["Players_in_team"] = group->getPlayersInTeamAmount();

		nlohmann::json& players_array = json_group["Players"];
		players_array = nlohmann::json::array();
			
		uint16_t player_index = 0;
		for (std::shared_ptr<Player> player : group->getPlayersCollectionRef().getCollection())
		{
			nlohmann::json& json_player = players_array[player_index];

			json_player["Id"] = player->getId();
			json_player["Name"] = player->getName();
			json_player["Rate"] = player->getRate();
			json_player["Role"] = player->getRoleText();

			player_index++;
		}
		group_index++; 
	}

	JsonUtils::serializeJson(data, app_path.getGroupsFilePath().c_str());
}

