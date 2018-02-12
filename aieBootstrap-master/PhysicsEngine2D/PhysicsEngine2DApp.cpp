#include "PhysicsEngine2DApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"


PhysicsEngine2DApp::PhysicsEngine2DApp() {

}

PhysicsEngine2DApp::~PhysicsEngine2DApp() {

}

bool PhysicsEngine2DApp::startup() {

	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0, 0));
	m_physicsScene->setTimeStep(0.01f);
	


	//WEEK 1 EXERCISE TESTING
	/*
	//SIMULATING ROCKET MOTOR
	//Sphere* rocket = new Sphere(glm::vec2(0, 0), glm::vec2(0, 0), 5.0f, 10, glm::vec4(1, 0, 0, 1));
	//m_physicsScene->addActor(rocket);
	//rocket->applyForce(glm::vec2(0, 0));

	//#1
	//Sphere* ball;
	//ball = new Sphere(glm::vec2(-10, 0), glm::vec2(10, 0), 3.0f, 1, glm::vec4(1, 0, 0, 1));
	//m_physicsScene->addActor(ball);
	
	//#2
	//Sphere* ball1 = new Sphere(glm::vec2(20, 20), glm::vec2(0, 0), 4.0f, 6, glm::vec4(1, 0, 0, 1));
	//Sphere* ball2 = new Sphere(glm::vec2(40, 20), glm::vec2(0, 0), 20.0f, 6, glm::vec4(0, 1, 0, 1));

	//SIMULATE COLLISION
	//m_physicsScene->addActor(ball1);
	//m_physicsScene->addActor(ball2);

	//ball1->applyForce(glm::vec2(-30, 0));
	//ball2->applyForce(glm::vec2(30, 0));
	//ball1->applyForceToActor(ball2, glm::vec2(15, 0));
	*/


	return true;
}

void PhysicsEngine2DApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void PhysicsEngine2DApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsEngine2DApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100,
						-100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}