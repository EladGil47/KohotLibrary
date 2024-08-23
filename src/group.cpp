#include "group.hpp"
#include <iostream>

Group::Group(const Group::Config& config)
{
    setConfig(config);
}

Group& Group::operator=(const Group& other_group)
{
    if (this == &other_group)
        return *this; // Self-assignment check

    // Copy Config member (since it contains a const member, it cannot be directly assigned)
    setConfig(other_group.m_config);
    setPlayersCollection(other_group.m_players_collection);

    return *this;
}

uint16_t Group::getPlayersInTeamAmount()
{
    return m_config.players_in_team_amount;
}

uint16_t Group::getTeamsAmount()
{
    return m_config.teams_amount;
}

void Group::addPlayer()
{
    m_players_collection.createItem();
}

void Group::deletePlayer(size_t index)
{
    m_players_collection.deleteItem(index);
}

size_t Group::getNumOfPlayers()
{
    return m_players_collection.getSize();
}

PlayersCollection& Group::getPlayersCollectionRef()
{
    return m_players_collection;
}

PlayersCollection Group::getPlayersCollection()
{
    return m_players_collection;
}

void Group::changeName()
{
    std::string new_name;
    std::cout << "Please enter name :  ";
    std::cin >> new_name;
    setName(new_name);
}

void Group::setName(std::string name)
{
    m_config.name = name;
}

void Group::setId(uint16_t id)
{
    m_config.id = id;
}

std::string Group::getName()
{
    return m_config.name;
}

uint16_t Group::getId()
{
    return m_config.id;
}

Group::Config Group::getConfig()
{
    return m_config;
}

void Group::displayGroup()
{
    std::cout << getName() << ":" << std::endl;
    m_players_collection.display();
}

void Group::setConfig(const Group::Config& config)
{
    m_config.id                     = config.id;
    m_config.name                   = config.name;
    m_config.teams_amount           = config.teams_amount;
    m_config.players_in_team_amount = config.players_in_team_amount;
}

void Group::setPlayersCollection(PlayersCollection players_collection)
{
    m_players_collection = players_collection;
}

std::shared_ptr<Player> Group::getPlayerByName(std::string name)
{
    std::shared_ptr<Player> ret_player = nullptr;
    for (std::shared_ptr<Player> player : getPlayersCollection().getCollection())
    {
        if (player->getName() == name)
        {
            ret_player = player;
        }
    }
    return ret_player;
}
