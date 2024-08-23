#ifndef KOHOT_APP_PATHS_HPP
#define KOHOT_APP_PATHS_HPP

#include <filesystem> // C++17 filesystem library
#include <string>

class AppPaths
{
public:
    std::string groupsFilePath;
    std::string teamsFilePath;

    // Constructor to initialize members with default values
    AppPaths()
    {
        setDefaultPaths();
    }

    void setGroupsFilePath(const std::string& relativePath)
    {
        groupsFilePath = getAbsolutePath(relativePath);
    }

    void setTeamsFilePath(const std::string& relativePath)
    {
        teamsFilePath = getAbsolutePath(relativePath);
    }

    std::string getGroupsFilePath() const
    {
        return groupsFilePath;
    }

    std::string getTeamsFilePath() const
    {
        return teamsFilePath;
    }

private:
    // Function to set default paths
    void setDefaultPaths()
    {
        // Get the current working directory
        std::filesystem::path currentPath = std::filesystem::current_path();

        // Set default paths based on the current working directory
        groupsFilePath = getAbsolutePath(currentPath / "Data/groups.json");
        teamsFilePath  = getAbsolutePath(currentPath / "Data/teams.json");
    }

    // Function to get absolute path
    std::string getAbsolutePath(const std::filesystem::path& relativePath) const
    {
        // Convert relative path to absolute path
        return std::filesystem::absolute(relativePath).string();
    }
};

#endif // KOHOT_APP_PATHS_HPP
