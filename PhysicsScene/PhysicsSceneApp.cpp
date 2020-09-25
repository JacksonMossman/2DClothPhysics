#include "PhysicsSceneApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Sphere.h"
#include "Plane.h"
#include"Spring.h"
#include <list>
#include <Gizmos.h>

PhysicsSceneApp::PhysicsSceneApp() {

}

PhysicsSceneApp::~PhysicsSceneApp() {

}

bool PhysicsSceneApp::startup() {
	// increase the 2D line count to maximize the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);



	// initialize gravity
	glm::vec2 gravity = glm::vec2(0.0f, -10.0f);

	// initialize the PhysicsScene
	m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(gravity);
	m_physicsScene->setTimeStep(0.01f);

	//Create Cloth For Simulation
	CreateCloth();

	return true;
}

void PhysicsSceneApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void PhysicsSceneApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// clear the buffer
	aie::Gizmos::clear();

	// update the PhysicsScene
	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsSceneApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw 
	static float aspectRatio = 16 / 9.0f;
	aie::Gizmos::draw2D(glm::ortho<float>(
		-100.0f, 100.0f,
		-100.0f / aspectRatio, 100.0f / aspectRatio,
		-1.0f, 1.0f));
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

void PhysicsSceneApp::CreateCloth()
{




	Plane* floor = new Plane(glm::vec2(0.0f, 90.0f), 00.0f);
	//Create ball to launch through cloth
	Sphere* LaunchMe = new Sphere(glm::vec2(-80, 20), glm::vec2(100, 0), 100, 2,
		glm::vec4(1, 1, 1, 1));
	m_physicsScene->addActor(LaunchMe);
	int startX = -50;
	//create iterator balls
	Sphere* ball1;
	Sphere* ball2;
	//set base values
	float ballRadius = .5;
	float mass = 1;

	ball1 = new Sphere(glm::vec2(startX, 40), glm::vec2(50, 50), mass, ballRadius,
		glm::vec4(1, 1, 1, 1));
	ball1->setElasticity(0.9f);

	int numberBallsX = 5;
	int numberBallsY = 5;

	Sphere* PreviuosSphere = nullptr;
	std::vector<Sphere*> PreviousColumn;

	//generate top Row
	for (int i = 0; i < numberBallsX; i++)
	{
		//place top ball
		ball1 = new Sphere(glm::vec2(startX + i * 10.0f, 40), glm::vec2(0, 0), mass, ballRadius,
			glm::vec4(1, 1, 1, 1));
		ball1->isKinematic = true;
		//check if this is the first ball
		if (PreviuosSphere != nullptr)
		{
			//add a spring to the previous row
			Spring* spring1 = new Spring(ball1, PreviuosSphere, 10, 3, 0.1f);
			m_physicsScene->addActor(spring1);

		}
		//add the new ball
		m_physicsScene->addActor(ball1);
		//set to previous sphere
		PreviuosSphere = ball1;
		//generate columns
		for (int j = 0; j < numberBallsY; j++)
		{
			//generate next ball in colunm
			ball2 = new Sphere(glm::vec2(startX + i * 10.0f, 40 - j * 10.0f), glm::vec2(0, 0), mass, ballRadius,
				glm::vec4(1, i, 1, 1));

			m_physicsScene->addActor(ball2);
			//create spring between this and previous sphere
			Spring* spring2 = new Spring(ball2, PreviuosSphere, 10, 3, 0.1f);
			m_physicsScene->addActor(spring2);
			//check if this is the first row 
			if (i == 0)
			{
				//populate previous 
				PreviousColumn.push_back(ball2);
			}
			else
			{
				//attach this the the previous node in row
				Spring* spring3 = new Spring(ball2, PreviousColumn.at(j), 10, 3, 0.1f);
				m_physicsScene->addActor(spring3);
				//set this to the previous column
				PreviousColumn.at(j) = ball2;
			}
			//set previous sphere the the current ball 2
			PreviuosSphere = ball2;

		}
		//set previous sphere to ball 1 
		PreviuosSphere = ball1;

	}
}



