/*
 *    Copyright (C) 2023 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
	\brief
	@author authorname
*/



#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
#include <abstract_graphic_viewer/abstract_graphic_viewer.h>
#include <ranges>
#include <cmath>

class SpecificWorker : public GenericWorker
{
Q_OBJECT
public:
	SpecificWorker(TuplePrx tprx, bool startup_check);
	~SpecificWorker();
	bool setParams(RoboCompCommonBehavior::ParameterList params);



public slots:
	void compute();
	int startup_check();
	void initialize(int period);



private:
    double t = 2;
    double rot = 2;
	bool startup_check_flag;
    int giros = 0;
    int giros_follow_wall = 0;
    RoboCompLidar3D::TPoint punto;
    int repeticion = 0;
    bool acabar = false;
    int giro = 0;
    int aumento = 0.008;
    bool ini = false;
    int count = 0;
    bool spiralSL = false;
    int pasarEstado = 0;
    float MIN_DISTANCE_Y = 470;
    float MIN_DISTANCE_X = 570;
    AbstractGraphicViewer* viewer;
    QGraphicsLineItem* linea = nullptr;
    void draw_lidar(const RoboCompLidar3D::TPoints &points, AbstractGraphicViewer *viewer);
    enum class Estado {FOLLOW_WALL, STRAIGHT_LINE, SPIRAL};
    Estado estado = Estado::SPIRAL;
    Estado straight_line(RoboCompLidar3D::TPoints &points);
    Estado follow_wall(RoboCompLidar3D::TPoints &points);
    Estado spiral(RoboCompLidar3D::TPoints &points);
    void comprobarBloqueo(RoboCompLidar3D::TPoint &min_elem);
};

#endif
