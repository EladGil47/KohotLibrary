#include "paths.hpp"

#include <filesystem>

static constexpr const char* GROUPS_JSON   = "Data/groups.json";
static constexpr const char* TEAMS_JSON    = "Data/teams.json";
static constexpr const char* SETTINGS_JSON = "Data/settings.json";

AppPaths::AppPaths()
{
    setDefaultPaths();
}

void AppPaths::setGroupsFilePath(const std::string& relative_path)
{
    m_groups_file = std::filesystem::absolute(relative_path);
}

void AppPaths::setTeamsFilePath(const std::string& relative_path)
{
    m_teams_file = std::filesystem::absolute(relative_path);
}

void AppPaths::setSettingsFilePath(const std::string& relative_path)
{
    m_settings_file = std::filesystem::absolute(relative_path);
}

std::string AppPaths::getGroupsFilePath() const
{
    return m_groups_file;
}

std::string AppPaths::getTeamsFilePath() const
{
    return m_teams_file;
}

std::string AppPaths::getSettingsFilePath() const
{
    return m_settings_file;
}

void AppPaths::setDefaultPaths()
{
    std::filesystem::path current_path = std::filesystem::current_path();

    m_groups_file   = std::filesystem::absolute(current_path / GROUPS_JSON);
    m_teams_file    = std::filesystem::absolute(current_path / TEAMS_JSON);
    m_settings_file = std::filesystem::absolute(current_path / SETTINGS_JSON);
}
