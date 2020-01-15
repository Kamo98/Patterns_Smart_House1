#pragma once
#include "AbstractSubSystem.h"
#include "CommandFactory.h"
#include "Command.h"
#include "UserScript.h"
#include "SmartLampAdapter.h"
#include "HumidityMeter.h"

class SummerSystem : public AbstractSubSystem
{
public:
	SummerSystem(CommandFactory *_commandFactory);
	~SummerSystem();

	// Унаследовано через AbstractSubSystem
	virtual void buildClimateSystem() override;
	virtual void buildSecureSystem() override;
	virtual void buildLightingSystem() override;
};

