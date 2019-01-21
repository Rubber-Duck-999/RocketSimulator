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
	public:
		Rocket();

		//Constructor for class Rocket
		Rocket(double mass, double dragAxisX, double dragAxisY,
			   double horiCrossSectArea, double vertCrossSectArea,
			   double thrust, double burnTime, double flowRate);

		//Get functions for class member variables
		double getmass() const;
		double getdragAxisX() const;
		double getdragAxisY() const;
		double gethoriCrossSectArea() const;
		double getvertCrossSectArea() const;
		double getthrust() const;
		double getburnTime() const;
		double getflowRate() const;
		double getdistX() const;
		double getdistY() const;
		float  gettimeTaken() const;

		//Set functions for class member variables
		void setmass(const double &mass);
		void setdragAxisX(const double &dragAxisX);
		void setdragAxisY(const double &dragAxisY);
		void sethoriCrossSectArea(const double &horiCrossSectArea);
		void setvertCrossSectArea(const double &vertCrossSectArea);
		void setthrust(const double &thrust);
		void setburnTime(const double &burnTime);
		void setflowRate(const double &flowRate);
		void setdistX(const double &distX);
		void setdistY(const double &distY);
		void settimeTaken(const float &time);

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
		float  _time;
};

#endif	/* ROCKET_H */

