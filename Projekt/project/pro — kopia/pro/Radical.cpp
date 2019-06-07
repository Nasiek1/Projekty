#include "Radical.h"

Radical::Radical()
	:Operator(" th root ")
{

}
Radical::Radical(Radical&& move)
{
	character = std::move(move.character);
}
Radical::~Radical()
{
}
