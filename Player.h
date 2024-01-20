#pragma once
#include "Object.h"

class Collider;
class Perceptible;
class Physics;

class Player : public Object
{
public:

	Player();
	~Player();

	virtual void Update();
	virtual void Render();

	virtual ObjectType GetType(void) const { return BaseObject; }

	Position* GetPosition(void) const { return m_pPosition; }
	Collider* GetCollider(void) const { return m_pCollider; }
	Perceptible* GetPerceptible(void) const { return m_pPerceptible; }
	Physics* GetPhysics(void) const { return m_pPhysics; }


private:
	Position* m_pPosition;
	Collider* m_pCollider;
	Perceptible* m_pPerceptible;
	Physics* m_pPhysics;
	float m_fSpeed; //TODO consolodate this into a velocity?
};