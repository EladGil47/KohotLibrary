
#include "groups_manager_menu.hpp"
#include "kohot.hpp"

int main(int argc, char *argv[]) {

  int ret_val;
  Kohot kohot;
  kohot.loadGroups();
  std::shared_ptr<GroupsCollection> groups_collection = kohot.getGroupsCollection();
  GroupsManagerMenu groups_manager_menu(groups_collection);
  ret_val = groups_manager_menu.handle() ? EXIT_SUCCESS : EXIT_FAILURE;
  return ret_val;
}
