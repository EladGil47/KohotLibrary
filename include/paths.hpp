#ifndef KOHOT_APP_PATHS_HPP
#define KOHOT_APP_PATHS_HPP

#include <string>

class AppPaths
{
public:
    AppPaths();

    void setGroupsFilePath(const std::string& relative_path);
    void setTeamsFilePath(const std::string& relative_path);
    void setSettingsFilePath(const std::string& relative_path);

    std::string getGroupsFilePath() const;
    std::string getTeamsFilePath() const;
    std::string getSettingsFilePath() const;

private:
    void setDefaultPaths();

    std::string m_groups_file;
    std::string m_teams_file;
    std::string m_settings_file;
};

#endif // KOHOT_APP_PATHS_HPP
