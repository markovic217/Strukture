#include "ScatterObject.h"



ScatterObject::ScatterObject():HashObject()
{
	status = 0;
}


ScatterObject::ScatterObject(char* k, char* v, int ko) :HashObject(k, v, ko)
{
	status = 0;
}

ScatterObject::ScatterObject(ScatterObject const& obj):HashObject(obj)
{
	status = obj.status;
}

ScatterObject& ScatterObject::operator = (ScatterObject const& obj)
{
	if (this != &obj)
	{
		(HashObject&)(*this) = obj;
		status = obj.status;
	}
	return *this;
}

