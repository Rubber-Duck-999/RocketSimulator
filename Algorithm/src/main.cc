#include <iostream>
#include <math.h>
 
using namespace::std;
 
float velocity_squared(float velocity);
float r_squared (float r);
float root_q (float thrust, float Mass, float g, float coef_k );
float get_l_value(float Mass, float g, float coef_k, float v_s, float thrust);
float get_l_2(float Mass, float g, float coef_k, float v_s);
 
const float pi = 3.14;
const float Cd = 0.75;
const float e = 2.71828182845904523536;
const float rho = 1.2;
const float g = 9.8;
 
float l_value; /* this is the value that is used for the equation yc = [+M / (2*coef_k)]*ln([M*g + k*v^2] / [M*g]); 
l_value =(M*g + k*v^2) / M*g)*/
float l_val_2;
 
float velocity; //v, in the equation
float v_s; //v^2;
float area;
float diam_inch;
float r; //radius
float r_s; //radius squared, used for pi*r^2;
float Mass; //in kilograms;
float boost_alt; //altitude at motor burnout
float coast_alt;//altitude gained while coasting;
float total_alt; //boost_alt + coast_alt;
float coef_k; //wind resistance temporary holder;
float impulse;
float thrust;
float burn_time;
float q;
float x;
float x_neg;
float m_neg;
 
int main()
{
    cout<<"Enter the mass of the rocket in ounces: \n";
    cin>>Mass;
    Mass = Mass /16 / 2.2; //conversion to Kg from ounces
    system("CLS");
    cout<<"Enter the diameter of the rocket, in inches: \n";
    cin>> diam_inch;
    system("CLS");
    r = diam_inch / 2; //useless now
    r_squared(r); //ignore this whole  function, it is no longer used
    area = pi* (0.5*(diam_inch / 12) * 0.3048) * (0.5*(diam_inch / 12) * 0.3048); 
     //area in square meters;
    coef_k = 0.5 * rho *Cd * area; /*temporary holding variable to implement wind resistance in other equations*/
    cout<<"Enter the Impulse for the motor: \n";
    cin>>impulse;
    system("CLS");
    cout<<"Enter the Thrust for the motor: \n";
    cin>>thrust;
    system("CLS");
    burn_time = impulse / thrust;
    q = root_q(thrust,  Mass, g, coef_k);
    x = 2*coef_k*q/Mass;
    x_neg = x * -1;
    velocity = q*(1-pow(e,x_neg*burn_time) / (1+pow(e,x_neg*burn_time)));
    m_neg = Mass * -1;
    v_s = velocity_squared(velocity);
    l_value = get_l_value(Mass, g, coef_k, v_s, thrust);
    boost_alt = (m_neg / (2*coef_k)) * log(l_value);
    l_val_2 = get_l_2(Mass, g, coef_k, v_s);
    coast_alt = (Mass / (2*coef_k)* log(l_val_2));
    total_alt = boost_alt + coast_alt;
    cout<<"Frontal Area of Rocket is " << area <<"square meters. \n";
    cout<<"Total altitude: " << total_alt << "feet. \n";
    system("PAUSE");
    if (total_alt < 0)
    {
                  cout<<"Try putting the motor in the other way. \n"; /*prompted by the consistent negative altitudes.*/
                  system("PAUSE");
    }
    return 0;
}
 
float velocity_squared(float velocity)
{
    v_s = velocity*velocity;
    return v_s;
}    
 
float r_squared(float r)
{
      r_s = r * r;
      return r_s;
}
 
float root_q (float thrust, float Mass, float g, float coef_k)
{
      q = ((thrust - Mass * g )/coef_k);
      q = sqrt(q);
      return q;
}
 
float get_l_value(float Mass, float g, float coef_k, float v_s, float thrust)
{
      l_value =(thrust - Mass*g + coef_k*v_s) / (Mass*g);
      return l_value;
}
 
float get_l_2(float Mass, float g, float coef_k, float v_s)
{
      l_val_2 = (Mass * g + coef_k * v_s) / (Mass * g);
      return l_val_2;
}