#pragma once

class IEngineState
{

public:

	enum class StateType { Menu = 1, Debug = 2 };

	IEngineState() {};
	virtual ~IEngineState() {};

	virtual bool Initialize() = 0;
	virtual bool Update() = 0;
	virtual bool Render() = 0;
	virtual bool Shutdown() = 0;

	virtual StateType GetType() = 0;

private:

};