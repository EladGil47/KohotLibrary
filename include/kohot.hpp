#ifndef KOHOT_HPP
#define KOHOT_HPP

#include "groups_collection.hpp"
class Kohot
{
public:

	std::shared_ptr<GroupsCollection> getGroupsCollection();

	/**
	 * @brief Load groups from Paths::GROUPS_FILE_PATH to m_groups_collection
	 */
	void loadGroups();

	/**
	 * @brief save m_groups_collection on Paths::GROUPS_FILE_PATH
	 */
	void saveGroups();

private:
	std::shared_ptr<GroupsCollection> m_groups_collection = std::make_shared<GroupsCollection>();
};

#endif //KOHOT_HPP
