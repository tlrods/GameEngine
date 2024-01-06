#pragma once
#include "EngineState.h"

class DebugState : public EngineState
{

public:

	DebugState(StateType eType) : EngineState(eType), m_eType(eType) {};
	~DebugState() {};

	virtual bool Initialize() override;
	virtual bool Update() override;
	virtual bool Render() override;
	virtual bool Shutdown() override;

	virtual StateType GetType() override;

private:

	StateType m_eType;
};