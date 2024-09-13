#ifndef KOHOT_GROUP_HPP
#define KOHOT_GROUP_HPP

#include "players_collection.hpp"

class Group
{
public:
    struct Config
    {
        uint16_t    id;
        std::string name;
        uint16_t    teams_amount           = 0;
        uint16_t    players_in_team_amount = 0;
    };

    Group(const Group::Config& config);
    Group& operator=(const Group& other_group);

    PlayersCollection getPlayersCollection();

    uint16_t getTeamsAmount();
    uint16_t getPlayersInTeamAmount();
    void     setId(uint16_t id);

    Group::Config getConfig();
    std::string   getName();
    uint16_t      getId();

    void setConfig(const Group::Config& config);
    void setPlayersCollection(PlayersCollection players_collection);
    void setName(std::string name);

    void changeName();

    void displayGroup();

    void   addPlayer();
    void   deletePlayer(size_t index);
    size_t getNumOfPlayers();

    std::shared_ptr<Player> getPlayerByName(std::string name);

    void setRateById(uint16_t id, double rate);
    void setNameById(uint16_t id, const std::string& name);
    void setIdById(uint16_t id, uint16_t new_id);

    void addPlayerToCollection(std::shared_ptr<Player> player);
    void deletePlayerFromCollectionById(uint16_t id);

private:
    Group::Config     m_config;
    PlayersCollection m_players_collection;
};

#endif // KOHOT_GROUP_HPP
