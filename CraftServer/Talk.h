#pragma once
#include "Client.h"
#include <stdarg.h>
#include <string>

using namespace std;
class Talk
{
public:
	Talk(Client, va_list args);




private:
	string text;
};