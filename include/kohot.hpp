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

    void loadGroups();
    void saveGroups();

    void loadSettings();

private:
    std::shared_ptr<GroupsCollection> m_groups_collection;
    AppPaths                          m_app_path;
};

#endif //KOHOT_HPP
