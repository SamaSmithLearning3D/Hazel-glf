#include "Hzpch.h"
#include "OrthographicCamera.h"//�þ����#include "Hzpch.h"����ͻ᲻��OrthgraphicCamera�����
#include "gtc/matrix_transform.hpp"
namespace Hazel {
	
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		:m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)),m_ViewMatrix(1.0f)
	{	
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
	{
		m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::RecalculatieViewMatrix()
	{
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Positioin) *
			glm::rotate(glm::mat4(1.0f), m_Rotation, glm::vec3(0, 0, 1.0f));

		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

}