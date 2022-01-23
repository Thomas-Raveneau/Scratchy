//
// Project: Scratchy
// File: Shader.h
//

#ifndef SCRATCHY_SHADER_H
#define SCRATCHY_SHADER_H

//#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Scratchy {

	class Shader {
		public:
			unsigned int ID;

			std::string vertexShaderPath;
			std::string fragmentShaderPath;

		public:
			Shader() = default;
			Shader(const std::string &vertexPath, const std::string &fragmentPath);
			~Shader();

		public:
			void setShaders(const std::string &vertexPath, const std::string &fragmentPath);
			void use() const;

		public:
			void setBool(const std::string &name, bool value) const;
			void setInt(const std::string &name, int value) const;
			void setFloat(const std::string &name, float value) const;

			void setVec2(const std::string &name, const glm::vec2 &value) const;
			void setVec2(const std::string &name, float x, float y) const;
			void setVec3(const std::string &name, const glm::vec3 &value) const;
			void setVec3(const std::string &name, float x, float y, float z) const;
			void setVec4(const std::string &name, const glm::vec4 &value) const;
			void setVec4(const std::string &name, float x, float y, float z, float w) const;
			void setMat2(const std::string &name, const glm::mat2 &mat) const;
			void setMat3(const std::string &name, const glm::mat3 &mat) const;
			void setMat4(const std::string &name, const glm::mat4 &mat) const;

		private:
			void checkCompileErrors(GLuint shader, std::string type);
	};
}

#endif //SCRATCHY_SHADER_H
