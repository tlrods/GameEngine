#include "Components.h"
#include "Helpers.h"

Perceptible::Perceptible() 
{
	m_pColor = new Color(0.0f, 0.25f, 0.5f, 1.0f);
}

Perceptible::~Perceptible()
{
	SAFE_DELETE(m_pColor);
}
