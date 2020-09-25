#pragma once
#include "PhysicsObject.h"
///Summary
/// A Class used to Calculate physics interactions and Resolve collisions
class RigidBody : public PhysicsObject
{
public:
	RigidBody(ShapeType shapeID, glm::vec2 position,
		glm::vec2 velocity, float rotation, float mass);
	~RigidBody() {}

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);//!< Updates this object on a fixed timestep
	virtual void debug(){}//!<  Not Used*/

	void applyForce(glm::vec2 force, glm::vec2 position);//!<  Applys a force to this object

	virtual bool checkCollision(PhysicsObject* other) = 0;//!<  Used to Check what kind of collisions happened
	void resolveCollision(RigidBody* other, glm::vec2 contact, glm::vec2* collisionNormal = nullptr);//!<  What Happens on this bodys collision

	glm::vec2 getPosition() { return m_position; }//!<  Return Current Position
	glm::vec2 getVelocity(){ return m_velocity; }//!< Return Current Velocity
	float getMass(){ return m_mass; }//!< Return Mass */ 

	float getRotation() { return m_rotation; }//!<  Return Rotation
	float getAngularVelocity() { return m_angularVelocity; }//!< Return angular Velocty
	float getMoment() { return m_moment; }//!<  return moment 

	float getLinearDrag(){ return m_linearDrag; }//!< Return Linear Drag 
	void setLinearDrag(float value){ m_linearDrag = value; }//!< Set Linear Drag

	float getAngularDrag() { return m_angularDrag; }//!<Return Angular Drag
	void setAngularDrag(float value) { m_angularDrag = value; }//!<!Sets Angular Drag 

	float getElasticity(){ return m_elasticity;} //!< Returns Elasticit
	void setElasticity(float value){ m_elasticity = value;}//!< Sets Elasticity

	bool isKinematic = false;//!<  Sets Body to Kinematic
	
	
protected:
	glm::vec2 m_position;//!< This Objects position in space
	glm::vec2 m_velocity;//!< This Object Velocity
	float m_mass;//!< This Objects Mass

	float m_rotation;//!< This Objects current roation
	float m_angularVelocity;//!< This Objects Roatational Veloctiy 
	float m_moment;//!<  Current force pm pnkct tp rotate

	float m_linearDrag = 0.3f;//!< Drag to Change Position
	float m_angularDrag = 0.3f;//!< Drag to Change Rotation
	float m_elasticity = 0.5f;//!< used for this objects resiestance to movement
};

