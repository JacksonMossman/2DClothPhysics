#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"
///Summary
///Used To Create Window and initalize program

class PhysicsSceneApp : public aie::Application {
public:
	PhysicsSceneApp();
	virtual ~PhysicsSceneApp();

	virtual bool startup();//!<  Runs any Initalizaton of the scneen
	virtual void shutdown();//!<  Closes Scene

	virtual void update(float deltaTime);//!<  Updates this scene
	virtual void draw();//!<  Draws this scene
	void CreateCloth();//!< Used to initalize cloth without crowding startup


protected:
	aie::Renderer2D*	m_2dRenderer;//!<  Not Used
	aie::Font*			m_font;//!<  Not Used
	PhysicsScene*		m_physicsScene;//!<  Refrence to this scenes Physics Scene
};