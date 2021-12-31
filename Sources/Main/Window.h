//
// Project: Scratchy
// File: Window.h
//

#ifndef SCRATCHY_WINDOW_H
#define SCRATCHY_WINDOW_H


#include <Main/Viewport.h>
#include <Utils/Color.h>
#include <Mesh/Mesh.h>
#include <Mesh/Primitives/Rect.h>

#include <iostream>
#include <vector>

namespace Scratchy {

	class Window: public Viewport {
		private:
			enum STATE {
				OPEN,
				CLOSE
			};

		private:
			GLFWwindow* window;
			std::string title;
			STATE state;
			Color clearColor;

			std::vector<Mesh *> meshes;

		public:
			Window(int width, int height, const std::string &title);
			virtual ~Window();

		public :
			int init(Color clearColor);

			void close();
			bool isOpen() const;

			void clear();
			void swapBuffer();

			void pollEvents();

		private:
			static void resize(GLFWwindow* window, int width, int height);

		public:
			const std::string &getTitle() const;
			void setTitle(const std::string &title);

			const Color &getClearColor() const;
			void setClearColor(Color clearColor);

			void addMesh(Mesh &mesh);

			void drawMeshes();
	};
}


#endif //SCRATCHY_WINDOW_H
