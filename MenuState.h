#pragma once
#include "EngineState.h"

class MenuState : public EngineState
{

public:

	MenuState(StateType eType) : EngineState(eType), m_eType(eType) {};
	~MenuState() {};

	virtual bool Initialize() override;
	virtual bool Update() override;
	virtual bool Render() override;
	virtual bool Shutdown() override;

	virtual StateType GetType() override;

private:

	StateType m_eType;
};