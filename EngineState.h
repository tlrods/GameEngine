#pragma once
#include "IEngineState.h"

class Player;

class EngineState : public IEngineState
{

public:
	
	EngineState() = delete;
	EngineState(IEngineState::StateType& eType) : m_eType(eType) {};
	~EngineState() {};

	virtual bool Initialize() override;
	virtual bool Update() = 0;
	virtual bool Render() = 0;
	virtual bool Shutdown() override;

	virtual IEngineState::StateType GetType() override;
	virtual Player* GetRenderData() = 0;

private:

	IEngineState::StateType m_eType;
};