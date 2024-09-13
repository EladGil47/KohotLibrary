#include "kohot.hpp"
#include "json_utils.hpp"

#include <iostream>

namespace groups_json_keys
{
static constexpr const char* GROUPS          = "Groups";
static constexpr const char* NAME            = "Name";
static constexpr const char* TEAMS           = "Teams";
static constexpr const char* PLAYERS_IN_TEAM = "Players_in_team";
static constexpr const char* PLAYERS         = "Players";
static constexpr const char* ID              = "Id";
static constexpr const char* RATE            = "Rate";
static constexpr const char* ROLE            = "Role";
} // namespace groups_json_keys

Kohot::Kohot()
{
    loadGroups();
    auto m_settings = Settings(m_app_path.getSettingsFilePath());
}

std::shared_ptr<GroupsCollection> Kohot::getGroupsCollection()
{
    return m_groups_collection;
}

void Kohot::loadGroups()
{
    m_groups_collection = std::make_shared<GroupsCollection>();

    nlohmann::json groups_data;
    JsonUtils::deserializeToJson(m_app_path.getGroupsFilePath().c_str(), groups_data);

    for (const auto& group : groups_data[groups_json_keys::GROUPS])
    {
        const Group::Config group_config = {
            static_cast<uint16_t>(m_groups_collection->getSize()),
            group[groups_json_keys::NAME].get<std::string>(),
            group[groups_json_keys::TEAMS].get<uint16_t>(),
            group[groups_json_keys::PLAYERS_IN_TEAM].get<uint16_t>(),
        };
        std::shared_ptr<Group> group_ptr = std::make_shared<Group>(group_config);

        uint16_t player_id = 0;
        for (const auto& player : group[groups_json_keys::PLAYERS])
        {
            const Player::Config player_config = {
                player_id++,
                player[groups_json_keys::NAME].get<std::string>(),
                player[groups_json_keys::RATE].get<double>(),
                Player::toPlayerRole(player[groups_json_keys::ROLE].get<std::string>())};
            std::shared_ptr<Player> additional_player = std::make_shared<Player>(player_config);
            group_ptr->addPlayerToCollection(additional_player);
        }
        m_groups_collection->addItem(group_ptr);
    }
}

void Kohot::saveGroups()
{
    nlohmann::json data;

    nlohmann::json& groups_array = data[groups_json_keys::GROUPS];
    groups_array                 = nlohmann::json::array();

    uint16_t group_index = 0;
    for (std::shared_ptr<Group> group : m_groups_collection->getCollection())
    {
        nlohmann::json& json_group = groups_array[group_index];

        json_group[groups_json_keys::ID]              = group->getId();
        json_group[groups_json_keys::NAME]            = group->getName();
        json_group[groups_json_keys::TEAMS]           = group->getTeamsAmount();
        json_group[groups_json_keys::PLAYERS_IN_TEAM] = group->getPlayersInTeamAmount();

        nlohmann::json& players_array = json_group[groups_json_keys::PLAYERS];
        players_array                 = nlohmann::json::array();

        uint16_t player_index = 0;
        for (std::shared_ptr<Player> player : group->getPlayersCollection().getCollection())
        {
            nlohmann::json& json_player = players_array[player_index];

            json_player[groups_json_keys::ID]   = player->getId();
            json_player[groups_json_keys::NAME] = player->getName();
            json_player[groups_json_keys::RATE] = player->getRate();
            json_player[groups_json_keys::ROLE] = player->getRoleText();

            player_index++;
        }
        group_index++;
    }

    JsonUtils::serializeJson(data, m_app_path.getGroupsFilePath().c_str());
}
