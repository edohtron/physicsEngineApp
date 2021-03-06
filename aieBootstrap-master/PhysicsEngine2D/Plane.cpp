#include "Plane.h"

Plane::Plane() 
	: PhysicsObject(ShapeType::PLANE) 
{
	m_distanceToOrigin = 0;
	m_normal = glm::vec2(0, 1);	
}

Plane::Plane(glm::vec2 normal, float distance)
	: PhysicsObject(ShapeType::PLANE)
{
	m_normal = normal;
	m_distanceToOrigin = distance;

	makeGizmo();
}


void Plane::fixedUpdate(glm::vec2 gravity, float timeStep)
{
}

void Plane::makeGizmo()
{
	float lineSegmentLength = 300;
	glm::vec2 centerPoint = m_normal * m_distanceToOrigin;

	//rotate normal through 90degrees around z
	glm::vec2 parallel(m_normal.y, -m_normal.x);
	glm::vec4 colour(1, 0, 0, 1);
	glm::vec2 start = centerPoint + (parallel * lineSegmentLength);
	glm::vec2 end = centerPoint - (parallel * lineSegmentLength);
	aie::Gizmos::add2DLine(start, end, colour);
}

void Plane::resetPosition()
{
}

void Plane::resolveCollision(Rigidbody * actor2, glm::vec2 contact)
{
	// plane not moving, relative velocity is actors2's velocity
	glm::vec2 vRel = actor2->getVelocity();
	float e = actor2->getElasticity();
	float j = glm::dot(-(1 + e) * (vRel), m_normal) / (1 / actor2->getMass());

	glm::vec2 force = m_normal * j;

	actor2->applyForce(force, contact - actor2->getPosition());


	/* OLD 
	glm::vec2 relativeVelocity = actor2->getVelocity();
	float elasticity = 1;

	//impulse to sphere
	float j = glm::dot(relativeVelocity , m_normal);

	glm::vec2 newVelocity = actor2->getVelocity() - (1 + elasticity) * j * m_normal;

	actor2->setVelocity(newVelocity);
	*/
	

}

Plane::~Plane()
{
}
