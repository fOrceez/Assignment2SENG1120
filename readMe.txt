First of all: Please try compiling with fpermissive

Unfortunately, my program only seems to compile on my OSX. It will compile in Terminal of OSX, it will also compile on Cygwin, but throws a segfault error while expanding the tree (I assume this is due to Cygwin's constrictions). 

Please note that after inserting the 'O' player's move, it is extremely slow in calculating the move to take for the AI (player 'X'). On my machine, it took a good 4 or 5 minutes. However, the time in calculating the AI's move exponentially decreases as the game goes on. Due to time constrictions, I was unable to optimise my program further.  (Rather than getting a random number and checking if it's 'valid' all the time, I would make it choose from an int array of 'available moves', which would be stored in the Board class.)

I hope you will take into consideration of Cywgin's constrictions and test this on another platform if possible. If a live-demonstration of my program is possible with my machine (with an archived file from Blackboard or a copy that has not been edited after the due date), that would be very much appreciated.
Sorry for the trouble,
Jeremy