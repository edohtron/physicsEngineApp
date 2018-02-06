#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "PhysicsObject.h"
#include <list>
#include "Rigidbody.h"
#include <iostream>

//to do 
// -forward declare physics object class
// -addActor(): adds a PhysicsObject pointer to the end of the m_actors vector.
// -removeActor(): removes a PhysicsObject pointer from the m_actors vector.

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* actor); 
	void removeActor(PhysicsObject* actor); 
	void update(float dt); 
	void updateGizmos(); 

	//virtual void debugScene();

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; } 
	glm::vec2 getGravity() const { return m_gravity; } 

	void setTimeStep(const float timeStep) { m_timeStep = timeStep; } 
	float getTimeStep() const { return m_timeStep; }

protected: 
	glm::vec2 m_gravity; 
	float m_timeStep; 
	std::vector<PhysicsObject*> m_actors;
};

