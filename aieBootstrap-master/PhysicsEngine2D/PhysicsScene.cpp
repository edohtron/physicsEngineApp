#include "PhysicsScene.h"

typedef bool(*fn)(const PhysicsObject*, const PhysicsObject*);

static fn collisionfnc collisionFunctionArray[] = {
	PhysicsScene::plane2Plane,	PhysicsScene::plane2Sphere,	 PhysicsScene::plane2Box,
	PhysicsScene::sphere2Plane, PhysicsScene::sphere2Sphere, PhysicsScene::sphere2Box,
	PhysicsScene::box2Plane,	PhysicsScene::box2Sphere,	 PhysicsScene::box2Box,
};

void PhysicsScene::checkForCollision()
{
	int actorCount = m_actors.size();

	//check for collisions against all object excpet this
	for (int outer = 0; outer < actorCount; outer++)
	{
		for (int inner = outer + 1; inner < actorCount; inner++)
		{
			PhysicsObject* object1 = m_actors[outer];
			PhysicsObject* object2 = m_actors[inner];
			int shapeId1 = object1->getShapeID();
			int shapeId2 = object2->getShapeID();

			//using function pointers
			int functionIdx = (shapeId1 * SHAPE_COUNT) + shapeId2;
			fn collisionFunctionPtr = collisionFunctionArray[functionIdx];
			if (collisionFunctionPtr != nullptr)
			{
				//did collision occur?
				collisionFunctionPtr(object1, object2);
			}
		}
	}
}

PhysicsScene::PhysicsScene()
{
	m_timeStep = 0.01f;
	m_gravity = glm::vec2(0, 0);
}

void PhysicsScene::update(float dt)
{
	static std::list<PhysicsObject*> dirty;

	// update physics at a fixed time step 
	static float accumulatedTime = 0.0f;
	accumulatedTime += dt;

	while (accumulatedTime >= m_timeStep)
	{
		for (auto pActor : m_actors)
		{
			pActor->fixedUpdate(m_gravity, m_timeStep);
		}

		accumulatedTime -= m_timeStep;
	}

	for (auto pActor : m_actors) {
		for (auto pOther : m_actors) {
			if (pActor == pOther)
				continue;

			if (std::find(dirty.begin(), dirty.end(), pActor) != dirty.end() &&
				std::find(dirty.begin(), dirty.end(), pOther) != dirty.end())
				continue;

			Rigidbody* pRigid = dynamic_cast<Rigidbody*>(pActor);
			if (pRigid->checkCollision(pOther) == true) {
				pRigid->applyForceToActor(
					dynamic_cast<Rigidbody*>(pOther),
					pRigid->getVelocity() * pRigid->getMass());
				dirty.push_back(pRigid);
				dirty.push_back(pOther);
			}
		}
	}
	dirty.clear();
}

void PhysicsScene::updateGizmos()
{
	for (auto pActor : m_actors) {
		pActor->makeGizmo();
	}
}

void PhysicsScene::debugScene()
{
	int count = 0;
	for (auto pActor : m_actors) {
		std::cout << count << " : ";
		pActor->debug();
		count++;
	}
}

/*
Note that in future tutorials you will need to keep track of the previous and current position of each
physics object so that you can interpolate between the two states when drawing.While this is not
essential, failing to do this will mean that your simulation will stutter slightly – a problem known as 
temporal aliasing.
*/

void PhysicsScene::addActor(PhysicsObject * actor)
{
	m_actors.push_back(actor);
}

void PhysicsScene::removeActor(PhysicsObject * actor)
{
	//m_actors.erase(std::remove(m_actors.begin(), m_actors.end(), 8), m_actors.end());
}

bool PhysicsScene::sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	//try to cast objects to sphere and sphere
	Sphere *sphere1 = dynamic_cast<Sphere*>(obj1);
	Sphere *sphere2 = dynamic_cast<Sphere*>(obj2);
	
	//if successful then test for collision
	if (sphere1 != nullptr && sphere2 != nullptr)
	{
		sphere1->applyForce(glm::vec2(0, 0));

		//get dist of 2 spheres (centre)
		if ((sphere2->getPosition - sphere1->getPosition) < (sphere2->getRadius + sphere1->getRadius))
		{

		}
	}
	return false;
}


PhysicsScene::~PhysicsScene()
{
	for (auto pActor : m_actors)
	{
		delete pActor;
	}
}

