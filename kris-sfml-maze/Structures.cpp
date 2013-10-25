#pragma once
/*!
 * @brief stores the current snapshot, previous snapshot and the size of the snapshot
 */
struct View
{
	char * current;
	char * previous;
	short height;
	short width;
};

/*!
 * Stores the array of the map as well as the height and width
 */
struct Level
{
	char * map;
	short height;
	short width;
};

/*!
 * stores the coordinates of the Player
 */
struct Player
{
	short x;
	short y;
};
