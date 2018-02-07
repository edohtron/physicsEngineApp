#include "Sphere.h"

//Sphere::Sphere()
//{
//}

Sphere::Sphere(glm::vec2 position, glm::vec2 velocity, 
	float mass, float radius, glm::vec4 colour) :
	Rigidbody(SPHERE, position, velocity, 0, mass)
{
	m_radius = radius;
	m_colour = colour;
}

void Sphere::makeGizmo()
{
	aie::Gizmos::add2DCircle(getPosition(), getRadius(), getMass(), getColour());
}

bool Sphere::checkCollision(PhysicsObject * pOther)
{
	return false;
}

Sphere::~Sphere()
{
}
