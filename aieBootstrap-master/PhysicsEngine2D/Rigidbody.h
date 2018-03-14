#pragma once
#include "PhysicsObject.h"

class Rigidbody : public PhysicsObject {

public:
	Rigidbody(ShapeType shapeID, glm::vec2 position,
		glm::vec2 velocity, float rotation, float mass);

	~Rigidbody();

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void debug()override; 
	void applyForce(glm::vec2 force);
	void applyForceToActor(Rigidbody* actor2, glm::vec2 force);
	void setVelocity(glm::vec2 vel);

	void resolveCollision(Rigidbody * actor2);

	virtual bool checkCollision(PhysicsObject* pOther) = 0; 

	glm::vec2 getPosition() { return m_position; }
	float getRotation() { return m_rotation; }
	glm::vec2 getVelocity() { return m_velocity; }
	float getMass() { return m_mass; }


protected:
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	float m_mass;
	float m_rotation;
	//float m_elasticity;


};

