#pragma once
#include "EngineState.h"

class Player;

class DebugState : public EngineState
{

public:

	DebugState(StateType eType) : EngineState(eType), m_eType(eType), m_pPlayer(nullptr) {};
	~DebugState();

	virtual bool Initialize() override;
	virtual bool Update() override;
	virtual bool Render() override;
	virtual bool Shutdown() override;

	virtual StateType GetType() override;
	virtual Player* GetRenderData() {
		return m_pPlayer;
	};

private:

	StateType m_eType;
	Player* m_pPlayer;
};