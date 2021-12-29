//
// Project: Scratchy
// File: Shader.h
//

#ifndef SCRATCHY_SHADER_H
#define SCRATCHY_SHADER_H

//#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Scratchy {

	class Shader {
		public:
			// the program ID
			unsigned int ID;

			// constructor reads and builds the shader
			Shader(std::string vertexPath, std::string fragmentPath);
			~Shader();

			// use/activate the shader
			void use() const;

			// utility uniform functions
			void setBool(const std::string &name, bool value) const;
			void setInt(const std::string &name, int value) const;
			void setFloat(const std::string &name, float value) const;
	};
}

#endif //SCRATCHY_SHADER_H
