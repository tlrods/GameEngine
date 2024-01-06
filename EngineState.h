#pragma once
#include "IEngineState.h"

class EngineState : public IEngineState
{

public:
	
	EngineState() = delete;
	EngineState(IEngineState::StateType& eType) : m_eType(eType), m_pPreviousState(nullptr) {};
	~EngineState() { delete m_pPreviousState; };

	virtual bool Initialize() override;
	virtual bool Update() = 0;
	virtual bool Render() = 0;
	virtual bool Shutdown() override;

	virtual IEngineState::StateType GetType() override;
	virtual IEngineState* GetPrevious() override;
	virtual void SetPrevious(IEngineState& pPrev) override;

private:

	IEngineState* m_pPreviousState;
	IEngineState::StateType m_eType;
};