#pragma once
#include "Structures.cpp"

class Map
{
	private:
		Level currentLevel;

		/*!
		 * @brief this is the height and width of the view that will be displayed
		 */
		View view;

	public:
		/*!
		 * empty default constructor
		 */
		Map() {}

		/*!
		 * takes in the snapshot of the map
		 */
		Map(View v)
		{
			currentLevel.height = 16;
			currentLevel.width = 16;
			currentLevel.map = new char[currentLevel.height * currentLevel.width];

			char temp[256] =
			{
				'W','W','W','V','W','W','W','W','W','W','W','W','W','W','W','W',
				'W','c','W','V','W','B',' ',' ',' ','W',' ',' ',' ',' ',' ','W',
				'W',' ','W','V','W','B','W','W',' ','W',' ','W','W','W',' ','W',
				'W',' ','W','V','W','B','W',' ',' ','W',' ','W','V','W',' ','W',
				'W',' ','W','W','W','B','W',' ','W','W',' ','W','V','W',' ','W',
				'W',' ',' ',' ',' ','B','W',' ','W','W',' ','W','W','W',' ','W',
				'W','W','W',' ','W','W','W',' ','W','W',' ',' ',' ','W',' ','W',
				'W',' ',' ',' ',' ',' ','W',' ','W','W','W','W',' ','W',' ','W',
				'W',' ','W','W','W',' ','W',' ',' ',' ',' ',' ',' ','W',' ','W',
				'W',' ','W','V','W',' ','W','W','W','W','W','W',' ','W',' ','W',
				'W',' ','W','V','W',' ',' ',' ',' ','W','V','W',' ','W',' ','W',
				'W',' ','W','V','W','W','W','W',' ','W','V','W',' ','W',' ','W',
				'W',' ','W','V','V','V','V','W',' ','W','V','W',' ','W',' ','W',
				'W',' ','W','W','W','W','V','W',' ','W','W','W',' ','W',' ','W',
				'W',' ',' ',' ',' ','W','V','W',' ',' ',' ',' ',' ','W',' ','W',
				'W','W','W','W','W','W','V','W','W','W','W','W','W','W','W','W'
			};

			//fills the map object with values
			for (short index = 0; index < (currentLevel.height * currentLevel.width); index++)
			{
				currentLevel.map[index] = temp[index];
			}

			view = v;
		}

		void setView(View v)
		{
			view = v;
		}

		/*!
		 * @brief Grabs a snapshot of the map
		 */
		void getView(char* array, short x, short y)
		{
			//for the size of the snapshot
			for (short index = 0; index < (view.width * view.height); index++)
			{
				//if the value is out of the bounds of the map it is Void
				if ( outOfBounds( (x + index % view.width), (y + index / view.width) ) )
				{
					array[index] = 'V';
				}
				//otherwise get the value of the space from the map
				else
				{
					array[index] = currentLevel.map[(x + (y * currentLevel.width)) + (index % view.width) + (index / view.width * currentLevel.width)];
				}
			}
		}

		/*!
		 * @brief check if an x,y coordinate is open for a user to enter
		 */
		bool const spaceIsOpen(short x, short y)
		{
			return !outOfBounds(x,y) && spaceTypeOpen(currentLevel.map[ x + (y * currentLevel.width) ]);
		}

		/*!
		 * @brief Checks if a type of space is open
		 */
		bool const spaceTypeOpen(char type)
		{
			switch(type)
			{
				case ' ':
					return true;
				default:
					return false;
			}
		}

		/*!
		 * @brief checks if an x,y coord is outside of the array bounds
		 */
		bool const outOfBounds(short x, short y)
		{
			return x < 0 || x >= currentLevel.width || y < 0 || y >= currentLevel.height;
		}

		/*!
		 * @brief sets the value of a tile
		 */
		void setTile(char value, short x, short y)
		{
			currentLevel.map[x + (y * currentLevel.width) ] = value;
		}
};
