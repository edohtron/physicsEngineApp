#include "Rigidbody.h"

const float MIN_LINEAR_THRESHOLD = 0.02f;
const float MIN_ROTATIONAL_THRESHOLD = 0.02f;

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
	applyForce(gravity * m_mass * timeStep, getPosition());
	m_position += m_velocity * timeStep;
	m_velocity -= m_velocity * m_linearDrag * m_angularDrag * timeStep;

	m_rotation += m_angularVelocity * m_angularDrag * timeStep;
	m_angularVelocity -= m_angularVelocity * m_angularDrag * timeStep;

	if (length(m_velocity) < MIN_LINEAR_THRESHOLD) 
	{
		m_velocity = glm::vec2(0, 0);
	}

	if (abs(m_angularVelocity) < MIN_ROTATIONAL_THRESHOLD)
	{
		m_angularVelocity = 0;
	}

}

void Rigidbody::debug()
{
}

void Rigidbody::applyForce(glm::vec2 force, glm::vec2 pos)
{
	m_velocity += force / m_mass;
	m_angularVelocity += (force.y * pos.x - force.x * pos.y) / (m_moment);
}

//void Rigidbody::applyForceToActor(Rigidbody * actor2, glm::vec2 force)
//{
//	this->applyForce(-force);
//	actor2->applyForce(force);
//}

void Rigidbody::setVelocity(glm::vec2 vel)
{
	m_velocity = vel;
}

void Rigidbody::resolveCollision(Rigidbody* actor2, glm::vec2 contact, glm::vec2* collisionNormal)
{
	// FIND VECTOR between object centres, or use the provided direction of force
	//glm::vec2 normal = glm::normalize(actor2->getPosition() - m_position);
	glm::vec2 normal = collisionNormal ? *collisionNormal
		: glm::normalize(actor2->m_position - m_position);															
	
	// get vector of perpendiculat to the collision normal
	glm::vec2 perp(normal.y, -normal.x);

	// determine total velocity of contact pts for two objects
	// for linear and rotational
		
		// 'r' is radius from axis to application of force
	float r1 = glm::dot(contact - m_position, -perp);
	float r2 = glm::dot(contact - actor2->m_position, perp);
		// velocity of contact point on this object
	float v1 = glm::dot(m_velocity, normal) - r1 * m_rotation;
		// velocity of contact point on actor2
	float v2 = glm::dot(actor2->m_velocity, normal) + r2 * actor2->m_rotation;

	if (v1 > v2) // theyre moving closer
	{
		float mass1 = 1.0f / (1.0f / m_mass + (r1*r1) / m_moment);
		float mass2 = 1.0f / (1.0f / actor2->m_mass + (r2*r2) / actor2->m_moment);

		float elasticity = (m_elasticity + actor2->getElasticity()) / 2.0f;

		glm::vec2 force = (1.0f + elasticity) * mass1 * mass2 /
			(mass1 + mass2) * (v1 - v2) * normal;

		// apply equal and opposite forces
		applyForce(-force, contact - m_position);
		actor2->applyForce(force, contact - actor2->m_position);
	}

	//glm::vec2 relativeVelocity = actor2->getVelocity() - m_velocity;
	//
	//
	//
	//float j = glm::dot(-(1 + elasticity) * (relativeVelocity), normal) /
	//	glm::dot(normal, normal * ((1 / m_mass) + 1 / actor2->getMass()));
	//
	//	glm::vec2 force = normal * j;

		//applyForceToActor(actor2, force);
}

Rigidbody::~Rigidbody()
{
}

