#include "Box.h"

Box::Box(glm::vec2 position, glm::vec2 velocity, 
		float mass, glm::vec4 colour, float elasticity) :
	Rigidbody(BOX, position, velocity, 0, mass)
{
}


Box::~Box()
{
}

void Box::makeGizmo()
{
}

bool Box::checkCollision(PhysicsObject * pOther)
{
	return false;
}
