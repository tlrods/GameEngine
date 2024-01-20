#pragma once

struct Position;

class Object
{
public:
	enum ObjectType {
		BaseObject = 0, PlayerObject = 1, AIObject = 2, SceneryObject = 3
	};

	Object();
	~Object();

	virtual void Update();
	virtual void Render();

	virtual ObjectType GetType(void) const { return BaseObject; }

private:

};
