#pragma once

#include "glm/glm.hpp"
namespace Hazel {	
	class OrthographicCamera
	{
	public:
		//OrthographicCamera() {};
		OrthographicCamera(float left, float right, float bottom, float top) ;
		void SetProjection(float left, float right, float bottom, float top);

		const glm::vec3& GetPosition()const { return m_Positioin; }
		void SetPosition(const glm::vec3& position) { m_Positioin = position;RecalculatieViewMatrix();	}

		float GetRotation()const { return m_Rotation; }
		void SetRotation(const float rotation) {m_Rotation = glm::radians(rotation);RecalculatieViewMatrix();}

		const glm::mat4 GetProjectMatrix()const { return m_ProjectionMatrix; }
		const glm::mat4 GetViewMatrix()const { return m_ViewMatrix; }
		const glm::mat4 GetViewProjectionMatrix()const {return m_ViewProjectionMatrix; }
	private:
		void RecalculatieViewMatrix();
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Positioin = { 0,0,0 };
		float m_Rotation = 0.0f;
	};
}