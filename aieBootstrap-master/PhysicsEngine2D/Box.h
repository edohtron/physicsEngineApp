#pragma once
#include "Rigidbody.h"
#include <Gizmos.h>

class Box : public Rigidbody
{
public:
	Box(glm::vec2 position, glm::vec2 velocity,
		float mass, glm::vec4 colour, float elasticity);
	~Box();

	virtual void makeGizmo();
	virtual bool checkCollision(PhysicsObject* pOther);

	glm::vec2 m_extents;		//halfedge lengths
	glm::vec4 m_colour;

	//store local x, y axes of box based on angle of rotation
	glm::vec2 m_localX;
	glm::vec2 m_localY;

};

