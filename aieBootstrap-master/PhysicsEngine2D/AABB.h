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

	glm::vec2 m_extents;
	glm::vec4 m_colour;

	glm::vec2 getExtents() const { return m_extents; }
	void setExtents(glm::vec2& extents) { m_extents = extents; }

	glm::vec2 min() { return m_position - m_extents; }
	glm::vec2 max() { return m_position + m_extents; }

	float getWidth() { return m_extents.x * 2; }
	float getHeight() { return m_extents.y * 2; }
	


};

