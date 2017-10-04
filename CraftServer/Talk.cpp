#include "Talk.h"

Talk::Talk(Client client, va_list args)
{
	text = args;
}