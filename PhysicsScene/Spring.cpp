#include "Spring.h"
#include <iostream>
#include <string>
//!summary
//!Connects Two Rigidbodys and adds a force to keep them together
//!
//Draw Line Between To Connected bodys 
void Spring::makeGizmo()
{
		
	aie::Gizmos::add2DLine(m_body2->getPosition(), m_body1->getPosition(), glm::vec4(.005*m_tension,1- m_tension* .005,0, 1));

}

void Spring::debug()
{
}

Spring::Spring(RigidBody* body1, RigidBody* body2, float restLength, float springCoefficient, float damping, glm::vec2 contact1, glm::vec2 contact2) : PhysicsObject(m_shapeID)
{
	m_body1 = body1;
	m_body2 = body2;
	m_restLength = restLength;
	m_springCoefficient = springCoefficient,
	m_damping = damping;
	m_contact1 = contact1;
	m_contact2 = contact2;
}
//Apply Spring Force
void Spring::fixedUpdate(glm::vec2 gravity, float timeStep)
{
		
		glm::vec2 p2 = m_body2->getPosition();
		glm::vec2 p1 = m_body1->getPosition();
	/*	std::cout<<"Body One X:"<<m_body1->getPosition().x <<"Body 1:Y"<< m_body1->getPosition().y;*/
		
		glm::vec2 dist = p2- p1;
		float length = sqrtf(dist.x * dist.x + dist.y * dist.y);
		
		// apply damping
		glm::vec2 relativeVelocity = m_body2->getVelocity() - m_body1->getVelocity();

		// F = -kX - bv
		
		glm::vec2 force = dist * m_springCoefficient * (m_restLength-length) - m_damping * relativeVelocity;
		
		m_tension = glm::length(force);
		
		m_body1->applyForce(-force * timeStep, p1 - m_body1->getPosition());
		m_body2->applyForce(force * timeStep, p2 - m_body2->getPosition());
	/*	std::cout<<"X:"<<force.x << "Y:"<< force.y;*/
}
