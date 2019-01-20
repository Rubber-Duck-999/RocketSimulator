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
		double getmass();
		double getdragAxisX();
		double getdragAxisY();
		double gethoriCrossSectArea();
		double getvertCrossSectArea();
		double getthrust();
		double getburnTime();
		double getflowRate();
		double getdistX();
		double getdistY();

		//Set functions for class member variables
		void setmass(double mass);
		void setdragAxisX(double dragAxisX);
		void setdragAxisY(double dragAxisY);
		void sethoriCrossSectArea(double horiCrossSectArea);
		void setvertCrossSectArea(double vertCrossSectArea);
		void setthrust(double thrust);
		void setburnTime(double burnTime);
		void setflowRate(double flowRate);
		void setdistX(double distX);
		void setdistY(double distY);

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
};

#endif	/* ROCKET_H */

