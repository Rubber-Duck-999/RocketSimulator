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

    public void Entry()
    {

    };

    @Override
    public String toString() {
        return "Entry{" +
                "position_axis_x=" + position_axis_x +
                ", position_axis_y=" + position_axis_y +
                ", velocity_axis_x=" + velocity_axis_x +
                ", velocity_axis_y=" + velocity_axis_y +
                ", time=" + time +
                '}';
    }
}
