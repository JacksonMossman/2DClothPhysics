#pragma once
#include "RigidBody.h"
///summary
///Create a Sphere and manages Drawing and Collision Check
class Sphere : public RigidBody
{
public:
	Sphere(glm::vec2 position, glm::vec2 velocity,
		float mass, float radius, glm::vec4 color);
	~Sphere() {}

	virtual void makeGizmo();//!< Draw a Spheare and a Line to represent Rotation
	virtual bool checkCollision(PhysicsObject* other);//!< Checks what object this is colliding with 

	float getRadius() { return m_radius; }//!< Return the Radius 
	glm::vec4 getColor() { return m_color; } //!< Return this Spheres Color
	
protected:
	float m_radius;//!< Radius of this sphere
	glm::vec4 m_color;//!< This Spheres Color
};
