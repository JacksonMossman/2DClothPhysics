#pragma once
#include "PhysicsObject.h"
#include "RigidBody.h"

//Summary
//Create a plane and Resolves its collisions
class Plane : public PhysicsObject
{
public:
	Plane();
	Plane(glm::vec2 normal, float distanceToOrigin);
	~Plane() {}

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep)//!< Updates this Objects Physics
	{}
	
	virtual void debug()//!<  Not Used
	{}
	
	virtual void makeGizmo();//!<  Draws this plane

	void resolveCollision(RigidBody* other, glm::vec2 contact);//!<  Applys a Force the the other object collided with 

	glm::vec2 getNormal(){return m_normal;}//!<  Return this objects normal
	float getDistance(){return m_distanceToOrigin;}//!< Return this objects Distance From Orgin

protected:
	glm::vec2 m_normal;//! Used To determain the angle of the plane
	float m_distanceToOrigin;//! How Fare the Center point of the plane is from orgin
};

