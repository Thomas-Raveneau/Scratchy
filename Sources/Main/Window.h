//
// Project: Scratchy
// File: Window.h
//

#ifndef SCRATCHY_WINDOW_H
#define SCRATCHY_WINDOW_H


#include <Main/Viewport.h>
#include <Main/Camera.h>
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
			float deltaTime = 0.0f;
			float lastFrame = 0.0f;

			std::vector<Mesh *> meshes;
			std::vector<Shader *> shaders;

			std::unique_ptr<Camera> camera;

			bool mouseAlreadyUsed =  false;
			std::unique_ptr<Position2> mousePos;

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

			void addMesh(Mesh &mesh);
			void drawMeshes();

			bool isKeyPressed(int key);

		private:
			void setCallbacks();

			static void processMouse(GLFWwindow* window, double x, double y);
			static void processResize(GLFWwindow* window, int width, int height);

		public:
			const std::string &getTitle() const;
			void setTitle(const std::string &title);

			const Color &getClearColor() const;
			void setClearColor(Color clearColor);
	};
}


#endif //SCRATCHY_WINDOW_H
