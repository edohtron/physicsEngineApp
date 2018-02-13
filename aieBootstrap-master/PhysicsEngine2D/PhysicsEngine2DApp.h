#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"
#include <Gizmos.h>
#include "PhysicsObject.h"
#include "Sphere.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <vector>

class PhysicsEngine2DApp : public aie::Application {
public:

	PhysicsEngine2DApp();
	virtual ~PhysicsEngine2DApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	PhysicsScene*		m_physicsScene;

	Sphere* ball1;
	Sphere* ball2;

};