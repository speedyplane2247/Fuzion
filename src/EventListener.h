#pragma once

#include "Hacks/aimbot.h"
#include "Hacks/hitmarkers.h"
#include "Hacks/eventlog.h"
#include "Hacks/namestealer.h"
#include "Hacks/resolver.h"
#include "Hacks/spammer.h"
#include "Hacks/valvedscheck.h"
#include "Hacks/skinchanger.h"

class EventListener : public IGameEventListener2
{
public:
	EventListener(std::vector<const char*> events)
	{
		for (auto& it : events)
			gameEvents->AddListener(this, it, false);
	}

	~EventListener()
	{
		gameEvents->RemoveListener(this);
	}

	void FireGameEvent(IGameEvent* event)
	{
		Aimbot::FireGameEvent(event);
		Hitmarkers::FireGameEvent(event);
		Eventlog::FireGameEvent(event);		
		NameStealer::FireGameEvent(event);
		Resolver::FireGameEvent(event);
		Spammer::FireGameEvent(event);
		ValveDSCheck::FireGameEvent(event);
		SkinChanger::FireGameEvent(event);
	}

	int GetEventDebugID() override
	{
		return EVENT_DEBUG_ID_INIT;
	}
};
