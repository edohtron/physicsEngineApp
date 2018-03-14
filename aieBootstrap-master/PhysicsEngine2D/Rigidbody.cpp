#include "Rigidbody.h"



//Rigidbody::Rigidbody()
//{
//}

Rigidbody::Rigidbody(ShapeType shapeID, glm::vec2 position,
	glm::vec2 velocity, float rotation, float mass) :
	PhysicsObject(shapeID)
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

void Rigidbody::setVelocity(glm::vec2 vel)
{
	m_velocity = vel;
}

void Rigidbody::resolveCollision(Rigidbody* actor2)
{
	glm::vec2 normal = glm::normalize(actor2->getPosition() - m_position);
	glm::vec2 normal2 = glm::normalize(m_position - actor2->getPosition());

	glm::vec2 relativeVelocity = actor2->getVelocity() - m_velocity;
	glm::vec2 relativeVelocity2 = getVelocity() - actor2->getVelocity();

	float elasticity = 1;

	//float j = glm::dot(-(1 + elasticity) * (relativeVelocity), normal) /
	//	glm::dot(normal, normal * ((1 / m_mass) + 1 / actor2->getMass()));

	//float k = glm::dot(-(1 + elasticity) * (relativeVelocity2), normal2) /
	//	glm::dot(normal2, normal2 * ((1 / actor2->getMass()) + 1 / m_mass));
	
	float j = glm::dot(m_velocity, normal);
	float l = glm::dot(actor2->m_velocity, normal);

	if (j > l)
	{
		float mass1 = m_mass;
		float mass2 = actor2->m_mass;

		//glm::vec2 force = normal * j;
		glm::vec2 force = (1.0f + elasticity) * mass1 * mass2 /
			(mass1 + mass2) * (j - l) * normal;

		//applyForceToActor(actor2, force);
		applyForce(-force);
		actor2->applyForce(force);
	}


}

Rigidbody::~Rigidbody()
{
}

