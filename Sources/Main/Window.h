//
// Project: Scratchy
// File: Window.h
//

#ifndef SCRATCHY_WINDOW_H
#define SCRATCHY_WINDOW_H

#include <iostream>

#include <Main/Viewport.h>
#include <Utils/Color.h>

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
	};
}


#endif //SCRATCHY_WINDOW_H
