#include "AddToFavsCommand.h"

AddToFavsCommand::AddToFavsCommand(unsigned id) : Command(), id(id) {}

void AddToFavsCommand::execute()
{
	s.addToFavs(id);
}


