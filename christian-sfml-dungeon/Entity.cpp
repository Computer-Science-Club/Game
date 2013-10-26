#pragma once
#include <iostream>

/*!
 * @brief this is a 'thing' in a level
 * Walls, Water, Lava
 * things that are attached to the level
 * these are NOT interactive
 *
 * These will be stored in an array
 */
struct LevelEntity
{
	/*!
	 * @brief this is the tile number of the icon that represents this entity
	 */
	short tileNumber;

	/*!
	 * @brief character used to represent this entity
	 */
	char levelChar;

	/*!
	 * @brief this is the type of the terrain that this represents
	 * e.g. Wall, Lava, Water, Void
	 */
	char type;
};

/*!
 * @brief Stuff not attached to the level
 * Characters, Beasts, Chests, Doors
 * things that may or may not move around
 * these ARE interactive
 *
 * These will be store in a double linked list
 */
class InteractiveEntity
{
private:
	/*!
	 * @brief Entity's position in x plane
	 */
	short x;

	/*!
	 * @brief Entity's position in y plane
	 */
	short y;
	
	/*!
	 * @brief this is the tile number of the icon that represents this entity
	 */
	short tileNumber;

	/*!
	 * @brief character used to represent this entity
	 */
	char levelChar;

	/*!
	 * @brief This stores how the entity will move
	 */
	char movementStyle;

	/*!
	 * @brief number of types Entity can cross
	 */
	short movementTypesLength;

	/*!
	 * @brief This stores they types of Level Entities that this Entity can move over
	 */
	char * movementTypes;

	/*!
	 * @brief next node in linked list
	 */
	InteractiveEntity * nextInteractiveEntity;

	/*!
	 * @brief previous node in linked list
	 */
	InteractiveEntity * previousInteractiveEntity;

public:
	/*!
	 * @brief default constructor
	 */
	InteractiveEntity () {}

	/*!
	 * @brief complete constructor
	 */
	InteractiveEntity (
		short startX, short startY,
		short startTileNumber,
		char  startLevelChar,
		char  startMovementStyle,
		short startMovementTypesLength, char * startMovementTypes,
		InteractiveEntity * startNextInteractiveEntity,
		InteractiveEntity * startPreviousInteractiveEntity
		)
	{
		x = startX;
		y = startY;
		tileNumber = startTileNumber;
		levelChar = startLevelChar;
		movementStyle = startMovementStyle;
		movementTypesLength = startMovementTypesLength;
		movementTypes = startMovementTypes;
		nextInteractiveEntity = startNextInteractiveEntity;
		previousInteractiveEntity = startPreviousInteractiveEntity;
	}

	/*!
	 * @brief this is how the Entity moves
	 */
	void movement()
	{
		switch (movementStyle)
		{
			case 'n':
				//This Entity Does Not Move
				break;
			case 'k':
				//This Entity moves base on key commands
				break;
			case 'b':
				//This Entity does basic movement, mving blindly toward the user (will be blocked by walls)
				break;
			case 'p':
				//This Entity will patrol, between two points
				break;
			case 'a':
				//This Entity has advance movement, uses a path finding algorithm to move quickly toward you
				break;
			default:
				std::cout << "Warning: movementStyle " << movementStyle << " is not recognized" << std::endl;
		}
	}

	/*!
	 * @brief initiates an interaction with another Entity
	 */
	void initiateInteract()
	{
		//TODO figure out how this works
	}

	/*!
	 * @brief responds to an interaction from another Entity
	 */
	void reactToInteraction()
	{
		//TODO figure out how this works
	}
};

/*!
 * @brief Effects, Ranged Attacks and the likes
 * Magic, Arrows, Javalins, Boosts
 * These are temporary and are quickly destroyed
 *
 * TODO figure out how this will be stored
 */
struct ParticleEntity
{
	/*!
	 * this is the tile number of the icon that represents this entity
	 */
	short tileNumber;

	//TODO figure out how particle will work
};
