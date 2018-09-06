/*******************************************************************************
 *
 *     Copyright : 2010 Arnaud Emilien
 *
 *******************************************************************************/

#ifndef _SPACE_FLOOR_H
#define _SPACE_FLOOR_H

#include "../../Engine/Mesh.h"
#include "WallE.h"
#include "WindowFacade.h"

class SpaceFloor {
public:
	Quad _ground;
	Quad _floor1;
	float _height;
	Mesh _mesh;

	SpaceFloor(Quad base,
			float height)
			: _ground(base), _height(height) {
		_floor1 = Quad(base._points[0] + Vector3F(0, height, 0),
				base._points[1] + Vector3F(0, height, 0),
				base._points[2] + Vector3F(0, height, 0),
				base._points[3] + Vector3F(0, height, 0));
	}

	Mesh generate() {
		_mesh.empty();

		WindowFacade wall1, wall2, wall3, wall4;
		wall1 = WindowFacade(Quad(_ground._points[0],
				_ground._points[1],
				_floor1._points[1],
				_floor1._points[0]));

		wall2 = WindowFacade(Quad(_ground._points[1],
				_ground._points[2],
				_floor1._points[2],
				_floor1._points[1]));

		wall3 = WindowFacade(Quad(_ground._points[2],
				_ground._points[3],
				_floor1._points[3],
				_floor1._points[2]));

		wall4 = WindowFacade(Quad(_ground._points[3],
				_ground._points[0],
				_floor1._points[0],
				_floor1._points[3]));

		_mesh += wall1.generate();
		_mesh += wall2.generate();
		_mesh += wall3.generate();
		_mesh += wall4.generate();

		return _mesh;
	}

}; // class SpaceFloor

#endif // _SPACE_FLOOR_H
