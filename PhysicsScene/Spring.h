#pragma once
#include "RigidBody.h"
#include <Gizmos.h>
///Summary
///Connects Two Rigidbodys and adds a force to keep them together
class Spring : public PhysicsObject
{
private:
	RigidBody* m_body1;//!< One of the Bodys Connected with this spring
	RigidBody* m_body2;//!< The other Body Connected with a spring 

	glm::vec2 m_contact1;//!< Not Used
	glm::vec2 m_contact2;//!< Not Used
	void makeGizmo();//!< Draw a line between the center of the two bodys
	void debug();//!< Not Used
	float m_damping;//!< A force acting against the spring to prevent infinite loops
	float m_restLength;//!< The Resting length of the spring
	float m_springCoefficient;//!< How Strong the spring force is
	float m_tension=0;//!< Only used to Change the springs color based on how much force it is outputting
public :
	Spring(RigidBody* body1, RigidBody* body2,
		float restLength, float springCoefficient, float damping = 0.1f,
		glm::vec2 contact1 = glm::vec2(0, 0), glm::vec2 contact2 = glm::vec2(0, 0));

	void fixedUpdate(glm::vec2 gravity, float timeStep);//!< Calculates the Spring Force on the two objects
};

