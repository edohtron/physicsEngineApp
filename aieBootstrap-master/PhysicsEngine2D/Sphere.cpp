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

bool Sphere::checkCollision(PhysicsObject * pOther) //override?
{
	return false;
}

Sphere::~Sphere()
{
}
