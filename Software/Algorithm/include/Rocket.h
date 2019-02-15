/* 
 * File:   Rocket.h
 * Author: student
 *
 * Created on May 5, 2016, 11:10 AM
 */

#ifndef ROCKET_H
#define	ROCKET_H

class Rocket
{
	private:
		double _mass;
		double _dragAxisX;
		double _dragAxisY;
		double _horiCrossSectArea;
		double _vertCrossSectArea;
		double _thrust;
		double _burnTime;
		double _flowRate;
		double _distX;
		double _distY;
		double _time;
	public:
		Rocket() {};

		//Constructor for class Rocket
		Rocket(double mass, double dragAxisX, double dragAxisY,
			   double horiCrossSectArea, double vertCrossSectArea,
			   double thrust, double burnTime, double flowRate);

		//Get functions for class member variables
		double getmass() const { return _mass; }
		double getdragAxisX() const { return _dragAxisX; }
		double getdragAxisY() const { return _dragAxisY; }
		double gethoriCrossSectArea() const { return _horiCrossSectArea; }
		double getvertCrossSectArea() const { return _vertCrossSectArea; }
		double getthrust() const { return _thrust; }
		double getburnTime() const { return _burnTime; }
		double getflowRate() const { return _flowRate; }
		double getdistX() const { return _distX; }
		double getdistY() const { return _distY; }
		double gettimeTaken() const { return _time; }

		//Set functions for class member variables
		void setmass(const double &mass)
		{
			_mass = mass;
		}
		void setdragAxisX(const double &dragAxisX)
		{
			_dragAxisX = dragAxisX;
		}
		void setdragAxisY(const double &dragAxisY)
		{
			_dragAxisY = dragAxisY;
		}
		void sethoriCrossSectArea(const double &horiCrossSectArea)
		{
			_horiCrossSectArea = horiCrossSectArea;
		}
		void setvertCrossSectArea(const double &vertCrossSectArea)
		{
			_vertCrossSectArea = vertCrossSectArea;
		}
		void setthrust(const double &thrust)
		{
			_thrust = thrust;
		}
		void setburnTime(const double &burnTime)
		{
			_burnTime = burnTime;
		}
		void setflowRate(const double &flowRate)
		{
			_flowRate = flowRate;
		}
		void setdistX(const double &distX)
		{
			_distX = distX;
		}
		void setdistY(const double &distY)
		{
			_distY = distY;
		}
		void settimeTaken(const double &time)
		{
			_time = time;
		}

};

#endif	/* ROCKET_H */

