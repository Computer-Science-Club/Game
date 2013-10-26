#pragma once
#include "Entity.cpp"

/*!
 * @brief This stores a level
 */
struct Level
{
	/*!
	 * @brief number of entities used to represent this level
	 */
	short levelEntityLength;
	/*!
	 * @brief array that actually stores the level entities
	 */
	LevelEntity * levelEntities;

	/*!
	 * @brief the hieght of the map being stored
	 */
	short mapHieght;

	/*!
	 * @brief the width of the map
	 */
	short mapWidth;

	/*!
	 * @brief array of pointers to the LevelEntities stored in the levelEntities array
	 */
	 //TODO this could also be stored as a short array with the number representing the index of the entity in the levelEntities Array
	LevelEntity ** map;

	/*!
	 * @brief stores the size of the double linked list of interactive entities
	 */
	short interactiveEntityLength;

	/*!
	 * @brief stores a pointer to the first Entity in the double linked list
	 */
	InteractiveEntity * head;

	/*!
	 *
	 */
	InteractiveEntity * tail;
};
