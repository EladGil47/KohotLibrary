#ifndef KOHOT_LIBRARY_SETTINGS_HPP
#define KOHOT_LIBRARY_SETTINGS_HPP

#include <filesystem>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

class Settings
{
public:
    Settings(const std::string& file_path);

    // Accessor methods
    static const std::vector<int32_t>& getPlayersInTeamRange()
    {
        return m_players_in_team_range;
    }
    static const std::vector<int32_t>& getTeamsRange()
    {
        return m_teams_range;
    }
    static const nlohmann::json& getSettingsJson()
    {
        return m_settings_json;
    }

    static const std::vector<int32_t>& getPlayerRateRange()
    {
        return m_player_rate_range;
    }

private:
    void load();
    void initTeamRange();
    void initPlayersInTeamRange();
    void initPlayerRateRange();

    bool save() const;

    static nlohmann::json m_settings_json;
    std::filesystem::path m_file_path;

    static std::vector<int32_t> m_teams_range;
    static std::vector<int32_t> m_players_in_team_range;
    static std::vector<int32_t> m_player_rate_range;
};

#endif // KOHOT_LIBRARY_SETTINGS_HPP
