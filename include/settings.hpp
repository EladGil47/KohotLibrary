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
    bool save() const;

    std::vector<int32_t> getTeamRange() const;
    std::vector<int32_t> getPlayersInTeamRange() const;

private:
    bool load();

    bool m_use_deafult;

    std::filesystem::path m_file_path;
    nlohmann::json        m_settings_json;

    std::vector<int32_t> m_teams_range{2, 4};
    std::vector<int32_t> m_players_in_team_range{1, 11};
};

#endif // KOHOT_LIBRARY_SETTINGS_HPP
