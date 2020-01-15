#pragma once
#include "AbstractSubSystem.h"
#include "CommandFactory.h"
#include "Command.h"
#include "UserScript.h"
#include "WarmFloor.h"
#include "SmartLampAdapter.h"

class WinterSubSystem : public AbstractSubSystem
{
public:
	WinterSubSystem(CommandFactory *_commandFactory);
	~WinterSubSystem();

	// ������������ ����� AbstractSubSystem
	virtual void buildClimateSystem() override;
	virtual void buildSecureSystem() override;
	virtual void buildLightingSystem() override;
};

