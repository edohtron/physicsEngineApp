#pragma once
#include "Rigidbody.h"
#include <Gizmos.h>

class AABB : public Rigidbody
{
public:
	AABB(glm::vec2 position, glm::vec2 velocity,
		 float mass, glm::vec4 colour);

	~AABB();

	virtual void makeGizmo();
	virtual bool checkCollision(PhysicsObject* pOther);

	float min(float a, float b) { return a < b ? a : b; }
	float max(float a, float b) { return a > b ? a : b; }
	float clamp(float t, float a, float b)
	{
		return max(a, min(b, t));
	}
	
	glm::vec2 min(const glm::vec2& a, const glm::vec2& b)
	{
		return { min(a.x, b.x), min(a.y, b.y) };
	}

	glm::vec2 max(const glm::vec2& a, const glm::vec2& b)
	{
		return { max(a.x, b.x), max(a.y, b.y) };
	}

	glm::vec2 clamp(const glm::vec2& t, const glm::vec2& a, const glm::vec2& b)
	{
		return max(a, min(b, t));
	}

	glm::vec2 m_extents;
	 



};

