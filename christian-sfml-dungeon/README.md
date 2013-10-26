GAME
=====
###This Design
This is a prototype design,
its goal is to offer a possible strucutal design for the game.
And allow for a Request for Comment to,
find flaws, purpose enhancements, and add features.

###Reasoning Behind Design

##Entities
To give the map and characters more versitility,
They could be represented as structures or simple classes.
Keeping the information packed nicely together.
And keeping fuctionality seperate from event handler/renderer

##Entity Types
There are
* Level Entities
* Interactive Entities
* Particle Entities

##Map Entities being Structure
Since walls and lakes don't move, and don't interact.
Preventing them from having logic keeps code shorter and simpler.
Traps, Doors, and Chests should be interactive Entities.

##Interactive Entities being stored in a Linked List
The idea here is to form a chain or a loop,
since Mosters, Allies, and you Character all need to have time to move/interact.
Creating a double linked list can create a repeatible queue.
You go first, then monster 1, then monster 2, then Ally, etc...
This could used for turn based,
OR it could also be used as a simple way to ensure that bots and players,
get a portion of time, in real time to handle logic.

##So... Particles
No Idea how these will work, or how they will be stored.
They are just a logical extension for future milestones in the game.
