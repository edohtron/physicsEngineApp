#pragma once
#include "Rigidbody.h"
#include <Gizmos.h>
#include <vector>

class AABB : public Rigidbody
{
public:

	AABB(glm::vec2 position, glm::vec2 velocity,
		 float mass, glm::vec2 extents, glm::vec4 colour);

	~AABB();

	virtual void makeGizmo();
	virtual bool checkCollision(PhysicsObject* pOther);

	glm::vec2 getCenter1() const { return (min + max) * 0.5f; }
	glm::vec2 getCentre2() { return m_position; }

	glm::vec2 min, max;
	glm::vec2 m_extents;
	glm::vec4 m_colour;

	glm::vec2 getExtents() const {
		return { abs(max.x - min.y) * 0.5f,
				 abs(max.y - min.y) * 0.5f };
	}


	//float getWidth() { return m_extents.x * 2; }
	//float getHeght() { return m_extents.y * 2; }
	
	//std::vector<glm::vec2> corners() const {
	//	std::vector<glm::vec2> corners(4);
	//	corners[0] = min;
	//	corners[1] = { min.x, max.y };
	//	corners[2] = max;
	//	corners[4] = { max.x, min.y };
	//	return corners;
	//}

};

