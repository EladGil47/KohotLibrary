#ifndef KOHOT_TEAM_HPP
#define KOHOT_TEAM_HPP

#include "players_collection.hpp"

class Team
{
public:
    Team();

    Team(uint16_t id);
    std::shared_ptr<PlayersCollection> getPlayersCollection();
    void                               addPlayer(std::shared_ptr<Player> player);
    void                               removePlayer(uint16_t player_id);

    void replacePlayer(uint16_t player_index_in_team_list, std::shared_ptr<Player> new_player);
    void cleanPlayer(uint16_t player_index_in_team_list);

    double      getAverageRate();
    void        setName(std::string name);
    void        setId(uint16_t id);
    size_t      getNumOfPlayers();
    uint16_t    getId();
    std::string getName();

    void displayTeam();

private:
    std::shared_ptr<PlayersCollection> m_players_collection;
    std::string                        m_name;
    uint16_t                           m_id;
};

#endif // KOHOT_TEAM_HPP