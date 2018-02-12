#pragma once
#include <glm/glm.hpp>

enum ShapeType {
	PLANE = 0,
	SPHERE,
	SHAPE_COUNT
};

class PhysicsObject
{
protected:
	PhysicsObject(ShapeType a_shapeID) : m_shapeID(a_shapeID) {};

public:
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
	virtual void debug() = 0;
	virtual void makeGizmo() = 0;
	virtual void resetPosition() {};

	int getShapeID() { return m_shapeID; }
	~PhysicsObject();

protected:
	ShapeType m_shapeID;

};

