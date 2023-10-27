#include "team.hpp"

#include <iostream>

Team::Team() {
	m_players_collection = std::make_shared<PlayersCollection>();
	m_id = 0;
	m_name = std::to_string(m_id);
}

Team::Team(uint16_t id) {
	m_players_collection = std::make_shared<PlayersCollection>();
	m_id = id;
	m_name = std::to_string(m_id);
}

std::shared_ptr<PlayersCollection> Team::getPlayersCollection()
{
	return m_players_collection;
}

void Team::addPlayer(std::shared_ptr<Player> player)
{
	if (m_players_collection)
	{
		m_players_collection->addItem(player);
	}
}

void Team::removePlayer(uint16_t player_id)
{
	if (m_players_collection)
	{
		size_t player_index_in_team = m_players_collection->getIndexById(player_id);
		m_players_collection->deleteItem(player_index_in_team);
	}
}

void Team::setName(std::string name)
{
	m_name = name;
}

std::string Team::getName()
{
	return m_name;

}


void Team::setId(uint16_t id)
{
	m_id = id;
}

uint16_t Team::getId()
{
	return m_id;
}

size_t Team::getNumOfPlayers()
{
	return m_players_collection->getSize();
}

void Team::displayTeam()
{
	double rating_sum = 0;
	size_t num_of_players_in_team =  m_players_collection->getSize();
	for (std::uint16_t player_index = 0;player_index < num_of_players_in_team; player_index++)
	{
		std::shared_ptr<Player> player = m_players_collection->getItem(player_index);
		std::cout << player->getName() << std::endl;
		rating_sum += player ->getRate();
	}
	double average_rate = rating_sum / num_of_players_in_team;
	std::cout <<"Avarage Rate : " << average_rate  << std::endl;
}

double Team::getAverageRate()
{
	double rating_sum = 0;
	size_t num_of_players_in_team = m_players_collection->getSize();
	for (std::uint16_t player_index = 0; player_index < num_of_players_in_team; player_index++)
	{
		std::shared_ptr<Player> player = m_players_collection->getItem(player_index);
		rating_sum += player->getRate();
	}
	double average_rate = 0;
	if (num_of_players_in_team != 0)
	{
		average_rate = rating_sum / num_of_players_in_team;
	}
	return average_rate;
}