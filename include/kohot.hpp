#ifndef KOHOT_HPP
#define KOHOT_HPP

#include "groups_collection.hpp"
#include "paths.hpp"
#include "settings.hpp"

class Kohot
{
public:
    Kohot();

    std::shared_ptr<GroupsCollection> getGroupsCollection();
    std::shared_ptr<Settings>         getSettings();

    void loadGroups();
    void saveGroups();

    void loadSettings();

private:
    std::shared_ptr<GroupsCollection> m_groups_collection;
    AppPaths                          m_app_path;
    std::shared_ptr<Settings>         m_settings;
};

#endif //KOHOT_HPP
