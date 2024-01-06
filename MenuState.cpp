#include "MenuState.h"

bool MenuState::Initialize()
{

	return false;
}

bool MenuState::Update()
{
	return false;
}

bool MenuState::Render()
{
	return false;
}

bool MenuState::Shutdown()
{
	return false;
}

IEngineState::StateType MenuState::GetType()
{
	return IEngineState::StateType::Menu;
}