#include "Player.h"
#include "Helpers.h"
#include "InputManager.h"
#include "Components.h"

Player::Player() : m_pPosition(nullptr),  m_pCollider(nullptr), m_pPerceptible(nullptr), m_pPhysics(nullptr), m_fSpeed(0.005f)
{
    m_pPosition = new Position();
    m_pCollider = new Collider();
    m_pPerceptible = new Perceptible();
    m_pPhysics = new Physics();

    m_pPosition->m_x = 0;
    m_pPosition->m_y = 0;
}

Player::~Player()
{
    SAFE_DELETE(m_pPosition);
    SAFE_DELETE(m_pCollider);
    SAFE_DELETE(m_pPerceptible);
    SAFE_DELETE(m_pPhysics);
}

void Player::Update()
{
    if (InputManager::GetInstance()->GetKeyPressed(KeyCode::W))
    {
        m_pPosition->m_y += m_fSpeed;
    }
    if (InputManager::GetInstance()->GetKeyPressed(KeyCode::A))
    {
        m_pPosition->m_x -= m_fSpeed;
    }
    if (InputManager::GetInstance()->GetKeyPressed(KeyCode::S))
    {
        m_pPosition->m_y -= m_fSpeed;
    }
    if (InputManager::GetInstance()->GetKeyPressed(KeyCode::D))
    {
        m_pPosition->m_x += m_fSpeed;
    }
}

void Player::Render()
{
    m_pPerceptible->m_pColor->m_r = m_pPerceptible->m_pColor->m_r >= 1.0f ? 0.0f : m_pPerceptible->m_pColor->m_r += m_fSpeed;
    m_pPerceptible->m_pColor->m_g = m_pPerceptible->m_pColor->m_g >= 1.0f ? 0.0f : m_pPerceptible->m_pColor->m_g += m_fSpeed;
    m_pPerceptible->m_pColor->m_b = m_pPerceptible->m_pColor->m_b >= 1.0f ? 0.0f : m_pPerceptible->m_pColor->m_b += m_fSpeed;
}
