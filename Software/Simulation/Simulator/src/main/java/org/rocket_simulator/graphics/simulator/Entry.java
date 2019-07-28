package org.rocket_simulator.graphics.simulator;

import java.io.Serializable;

public class Entry
{

    //private static final long serialVersionUID = 1L;

    public double position_axis_x;
    public double position_axis_y;
    public double velocity_axis_x;
    public double velocity_axis_y;
    public double time;

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
}
