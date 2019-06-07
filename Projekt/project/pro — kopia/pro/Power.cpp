#include "Power.h"

Power::Power()
	:Operator("^")
{

}
Power::Power(Power&& move)
{
	character = std::move(move.character);
}
Power::~Power()
{
}
