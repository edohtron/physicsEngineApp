#include "Rigidbody.h"



//Rigidbody::Rigidbody()
//{
//}

Rigidbody::Rigidbody(ShapeType shapeID, glm::vec2 position,
	glm::vec2 velocity, float rotation, float mass) :
	PhysicsObject(SPHERE)
{

}

void Rigidbody::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	applyForce(gravity * m_mass * timeStep);
	m_position += m_velocity * timeStep;
}

void Rigidbody::debug()
{
}

void Rigidbody::applyForce(glm::vec2 force)
{
	m_velocity += force / m_mass;
}

void Rigidbody::applyForceToActor(Rigidbody * actor2, glm::vec2 force)
{
	this->applyForce(-force);
	actor2->applyForce(force);
}

Rigidbody::~Rigidbody()
{
}
