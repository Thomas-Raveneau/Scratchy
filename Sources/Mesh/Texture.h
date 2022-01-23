//
// Project: Scratchy
// File: Texture.h
//

#ifndef SCRATCHY_TEXTURE_H
#define SCRATCHY_TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <iostream>

namespace Scratchy {

	class Texture {
		private:
			unsigned int ID;

		public:
			Texture() = default;
			Texture(std::string filepath);
			~Texture();

		public:
			void render() const;
	};
}



#endif //SCRATCHY_TEXTURE_H
