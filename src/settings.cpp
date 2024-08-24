#include "settings.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace SettingsKeys
{
static constexpr const char* TEAMS_RANGE           = "TeamsRange";
static constexpr const char* PLAYERS_IN_TEAM_RANGE = "PlayersInTeamRange";
static constexpr const char* PLAYER_RATE_RANGE     = "PlayerRateRange";

} // namespace SettingsKeys

static const std::vector<int32_t> PLAYERS_IN_TEAM_RANGE_DEFAULT{1, 11};
static const std::vector<int32_t> TEAMS_RANGE_DEFAULT{2, 4};
static const std::vector<int32_t> PLAYER_RATE_RANGE_DEFAULT{1, 7};

nlohmann::json       Settings::m_settings_json;
std::vector<int32_t> Settings::m_players_in_team_range = PLAYERS_IN_TEAM_RANGE_DEFAULT;
std::vector<int32_t> Settings::m_teams_range           = TEAMS_RANGE_DEFAULT;
std::vector<int32_t> Settings::m_player_rate_range     = PLAYER_RATE_RANGE_DEFAULT;

Settings::Settings(const std::string& file_path)
    : m_file_path(std::filesystem::absolute(file_path))
{
    load();
}

void Settings::load()
{
    if (std::filesystem::exists(m_file_path))
    {
        std::ifstream file(m_file_path);
        if (file.is_open())
        {
            try
            {
                file >> m_settings_json;
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error parsing JSON: " << e.what() << std::endl;
            }
        }
        else
        {
            std::cerr << "Unable to open file: " << m_file_path << std::endl;
        }
    }
    initTeamRange();
    initPlayersInTeamRange();
}

void Settings::initTeamRange()
{
    try
    {
        m_teams_range = m_settings_json.at(SettingsKeys::TEAMS_RANGE).get<std::vector<int32_t>>();
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cerr << "Error accessing 'TeamsRange' in JSON: " << e.what() << std::endl;
    }
}

void Settings::initPlayersInTeamRange()
{
    try
    {
        m_players_in_team_range = m_settings_json.at(SettingsKeys::PLAYERS_IN_TEAM_RANGE).get<std::vector<int32_t>>();
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cerr << "Error accessing 'PlayersInTeamRange' in JSON: " << e.what() << std::endl;
    }
}

void Settings::initPlayerRateRange()
{
    try
    {
        m_players_in_team_range = m_settings_json.at(SettingsKeys::PLAYER_RATE_RANGE).get<std::vector<int32_t>>();
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cerr << "Error accessing 'PlayerRateRange' in JSON: " << e.what() << std::endl;
    }
}
