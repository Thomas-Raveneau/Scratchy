//
// Project: Scratchy
// File: Viewport.h
//

#ifndef SCRATCHY_VIEWPORT_H
#define SCRATCHY_VIEWPORT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <utility>

namespace Scratchy {

	class Viewport {
		public:
			enum MODE {
				WINDOWED,
				FULLSCREEN
			};

		private:
			std::pair<int, int> size;
			MODE mode = WINDOWED;

		protected:
			Viewport(int width, int height);
			virtual ~Viewport();

		public :
			int getWidth() const;
			void setWidth(int width);

			int getHeight() const;
			void setHeight(int height);

			void setSize(int width, int height);

			MODE getMode() const;
			void setMode(MODE mode);
	};
}

#endif //SCRATCHY_VIEWPORT_H
