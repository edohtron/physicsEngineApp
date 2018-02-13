#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "PhysicsObject.h"
#include <list>
#include "Rigidbody.h"
#include <iostream>
#include <algorithm>
#include "Sphere.h"
#include "Plane.h"

class PhysicsScene
{
public: //or private
	struct CollisionData
	{
		bool		wasCollision;
		glm::vec2	normal;
		float		overlap;
		glm::vec2	contactPoint;
	};

public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* actor); 
	void removeActor(PhysicsObject* actor); 
	void update(float dt); 
	void updateGizmos(); 
	void debugScene();

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; } 
	glm::vec2 getGravity() const { return m_gravity; } 

	void setTimeStep(const float timeStep) { m_timeStep = timeStep; } 
	float getTimeStep() const { return m_timeStep; }

	void checkForCollision();

	static bool plane2Plane(PhysicsObject*, PhysicsObject*);
	static bool plane2Sphere(PhysicsObject*, PhysicsObject*);
	static bool sphere2Plane(PhysicsObject*, PhysicsObject*);
	static bool sphere2Sphere(PhysicsObject*, PhysicsObject*);

	//static CollisionData plane2Plane(PhysicsObject*, PhysicsObject*);
	//static CollisionData plane2Sphere(PhysicsObject*, PhysicsObject*);
	//static CollisionData sphere2Plane(PhysicsObject*, PhysicsObject*); 
	//static CollisionData sphere2Sphere(PhysicsObject*, PhysicsObject*); 

protected: 
	glm::vec2 m_gravity; 
	float m_timeStep; 
	std::vector<PhysicsObject*> m_actors;


};

