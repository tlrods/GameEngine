#pragma once
#include "EngineState.h"

class DebugState : public EngineState
{

public:

	DebugState(StateType eType) : EngineState(eType), m_eType(eType), m_pPreviousState(nullptr) {};
	~DebugState() { delete m_pPreviousState; };

	virtual bool Initialize() override;
	virtual bool Update() override;
	virtual bool Render() override;
	virtual bool Shutdown() override;

	virtual StateType GetType() override;
	virtual IEngineState* GetPrevious() override;
	virtual void SetPrevious(IEngineState& pPrev) override;

private:

	IEngineState* m_pPreviousState;
	StateType m_eType;
};