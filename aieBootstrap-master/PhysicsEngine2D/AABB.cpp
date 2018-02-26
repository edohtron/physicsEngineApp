#include "AABB.h"



AABB::AABB(glm::vec2 position, glm::vec2 velocity,
	float mass, glm::vec2 extents, glm::vec4 colour) :
	Rigidbody(aabb, position, velocity, 0, mass)
{
	m_position = position;
	m_velocity = velocity;
	m_mass = mass;
	m_colour = colour;
	m_extents = extents;
	makeGizmo();
}

AABB::~AABB()
{
}

void AABB::makeGizmo()
{
	aie::Gizmos::add2DAABBFilled(m_position, m_extents, m_colour);
}

bool AABB::checkCollision(PhysicsObject * pOther)
{
	return false;
}
