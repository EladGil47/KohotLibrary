#include "settings.hpp"
#include <fstream>

namespace SettingsKeys
{
static constexpr const char* TEAMS_RANGE           = "TeamsRange";
static constexpr const char* PLAYERS_IN_TEAM_RANGE = "PlayersInTeamRange";

} // namespace SettingsKeys

Settings::Settings(const std::string& file_path)
    : m_file_path(std::filesystem::absolute(file_path))
{
    m_use_deafult = !load();
}

bool Settings::load()
{
    if (std::filesystem::exists(m_file_path))
    {
        std::ifstream file(m_file_path);
        if (file.is_open())
        {
            file >> m_settings_json;
            file.close();
            return true;
        }
    }
    return false;
}

bool Settings::save() const
{
    std::ofstream file(m_file_path);
    if (file.is_open())
    {
        file << m_settings_json.dump(4); // Pretty print with 4 spaces indentation
        file.close();
        return true;
    }
    return false;
}

std::vector<int32_t> Settings::getTeamRange() const
{
    std::vector<int32_t> teams_range = m_use_deafult ? m_teams_range : m_settings_json[SettingsKeys::TEAMS_RANGE].get<std::vector<int32_t>>();
    return teams_range;
}

std::vector<int32_t> Settings::getPlayersInTeamRange() const
{
    std::vector<int32_t> players_in_team_range = m_use_deafult ? m_players_in_team_range : m_settings_json[SettingsKeys::PLAYERS_IN_TEAM_RANGE].get<std::vector<int32_t>>();
    return players_in_team_range;
}
