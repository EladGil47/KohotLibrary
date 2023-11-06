#ifndef KOHOT_HPP
#define KOHOT_HPP

#include "groups_collection.hpp"
#include "paths.hpp"

class Kohot
{
public:
	Kohot();

	std::shared_ptr<GroupsCollection> getGroupsCollection();

	/**
	 * @brief Load groups from Paths::GROUPS_FILE_PATH to m_groups_collection
	 */
	void loadGroups();

	/**
	 * @brief save m_groups_collection on Paths::GROUPS_FILE_PATH
	 */
	void saveGroups();

	AppPaths app_path;

private:
	std::shared_ptr<GroupsCollection> m_groups_collection;
};

#endif //KOHOT_HPP
