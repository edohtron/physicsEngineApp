#include "PhysicsScene.h"

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

PhysicsScene::~PhysicsScene()
{
	for (auto pActor : m_actors)
	{
		delete pActor;
	}
}

void PhysicsScene::addActor(PhysicsObject * actor)
{
}

void PhysicsScene::removeActor(PhysicsObject * actor)
{
}
