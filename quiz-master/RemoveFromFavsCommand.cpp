#include "RemoveFromFavsCommand.h"

RemoveFromFavsCommand::RemoveFromFavsCommand(unsigned id) : Command(), id(id) {}

void RemoveFromFavsCommand::execute()
{
	s.removeFromFavs(id);
}
