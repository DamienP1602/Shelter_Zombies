#pragma once

#define S_APPEND(name) name + to_string(GetUniqueID())

static int GetUniqueID()
{
	static int _id = 0;
	return _id++;
}
