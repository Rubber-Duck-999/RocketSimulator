package org.rocket_simulator.graphics.simulator;

public class Entry
{

    //private static final long serialVersionUID = 1L;

    public double position_axis_x;
    public double position_axis_y;
    public double velocity_axis_x;
    public double velocity_axis_y;
    public double time;

    public Entry(final double position_axis_x, final double position_axis_y, final double velocity_axis_x, final double velocity_axis_y, final double time)
    {
        this.position_axis_x = position_axis_x;
        this.position_axis_y = position_axis_y;
        this.velocity_axis_x = velocity_axis_x;
        this.velocity_axis_y = velocity_axis_y;
        this.time = time;
    }

    public double getPosition_axis_x() {
        return position_axis_x;
    }

    public double getPosition_axis_y() {
        return position_axis_y;
    }

    public double getVelocity_axis_x() {
        return velocity_axis_x;
    }

    public double getVelocity_axis_y() {
        return velocity_axis_y;
    }

    public double getTime() {
        return time;
    }

    @Override
    public String toString() {
        return "Entry{" +
                "Position_Axis_X=" + position_axis_x +
                ", Position_Axis_Y=" + position_axis_y +
                ", Velocity_Axis_X=" + velocity_axis_x +
                ", Velocity_Axis_Y=" + velocity_axis_y +
                ", Time=" + time +
                '}';
    }

    public void setPosition_axis_x(double position_axis_x) {
        this.position_axis_x = position_axis_x;
    }

    public void setPosition_axis_y(double position_axis_y) {
        this.position_axis_y = position_axis_y;
    }

    public void setVelocity_axis_x(double velocity_axis_x) {
        this.velocity_axis_x = velocity_axis_x;
    }

    public void setVelocity_axis_y(double velocity_axis_y) {
        this.velocity_axis_y = velocity_axis_y;
    }

    public void setTime(double time) {
        this.time = time;
    }
}
