#pragma once
#include "PhysicsObject.h"
#include "glm\ext.hpp"
#include <vector>
///Summary
/// Used To manage Updating all the actors in the Scene as well as drawing all actors
/// Also handles how each physics interaction will be handled
class PhysicsScene
{
public:
	PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0.0f, 0.0f)) {}
	~PhysicsScene();

	void addActor(PhysicsObject* actor);//!<  Adds a Actor to the Scene
	void removeActor(PhysicsObject* actor);//!<  Removes a Actor From the Scene
	void update(float deltaTime);//! Updates the Scene
	void updateGizmos();//!<  Updates all the Gizmos
	void debugScene();//!<  Not Used

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }//!<  Sets the Gravity
	glm::vec2 getGravity() const { return m_gravity; }//!<  Returns the Gravity

	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }//!<  Sets this physics scenes TimeStep
	float getTimeStep() const { return m_timeStep; } //!<  Returns This Scenes Time Step

	void checkForCollision();//! Iterates through all actors in this Scene Checking for collsions

	static bool planeToPlane(PhysicsObject*, PhysicsObject*);//!<  Checks plane to plane collisions
	static bool planeToSphere(PhysicsObject*, PhysicsObject*);//!<  Checks Plane To Sphere collsions
	static bool sphereToPlane(PhysicsObject*, PhysicsObject*);//!<  Sphere to plane collsions
	static bool sphereToSphere(PhysicsObject*, PhysicsObject*);//!<  Checks Sphere to Sphere Collisions

protected:
	glm::vec2	m_gravity;//!<  The Current Gravity of the Scene
	float		m_timeStep;//!<  The Current TimeStep of the Scene

	std::vector<PhysicsObject*>	m_actors;//!<  All of the actors currently in the scene
};
