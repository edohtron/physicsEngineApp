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

	m_position = position;
	m_velocity = velocity;
	m_mass = mass;

	makeGizmo();
}

void Sphere::makeGizmo()
{


	aie::Gizmos::add2DCircle(m_position, m_radius, 32, m_colour);
}

bool Sphere::checkCollision(PhysicsObject * pOther)
{
	return false;
}


Sphere::~Sphere()
{
}
