#include "AABB.h"



AABB::AABB(glm::vec2 position, glm::vec2 velocity,
	float mass, glm::vec4 colour) :
	Rigidbody(aabb, position, velocity, 0, mass)
{

}


AABB::~AABB()
{
}
