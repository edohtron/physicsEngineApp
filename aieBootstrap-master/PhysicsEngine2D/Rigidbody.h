#pragma once
#include "PhysicsObject.h"


class Rigidbody : public PhysicsObject {

public:
	Rigidbody(ShapeType shapeID, glm::vec2 position,
		glm::vec2 velocity, float rotation, float mass);

	~Rigidbody();

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void debug()override; //define?
	void applyForce(glm::vec2 force, glm::vec2 pos);
	//void applyForceToActor(Rigidbody* actor2, glm::vec2 force);
	void setVelocity(glm::vec2 vel);

	void resolveCollision(Rigidbody * actor2, glm::vec2 contact, glm::vec2* collisionNormal = nullptr);

	virtual bool checkCollision(PhysicsObject* pOther) = 0; //define?

	glm::vec2 getPosition() { return m_position; }
	float getRotation() { return m_rotation; }
	glm::vec2 getVelocity() { return m_velocity; }
	float getMass() { return m_mass; }
	
	float getElasticity() {	return m_elasticity; }


protected:
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	float m_mass;
	float m_rotation;

	float m_linearDrag = 0.3f;
	float m_angularDrag = 0.3f;
	float m_angularVelocity;

	float m_elasticity;
	float m_moment;

};

