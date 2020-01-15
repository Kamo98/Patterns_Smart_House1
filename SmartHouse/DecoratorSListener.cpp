#include "DecoratorSListener.h"



DecoratorSListener::DecoratorSListener(ISensorListener *sub)
{
	subject = sub;
}


DecoratorSListener::~DecoratorSListener()
{
}
