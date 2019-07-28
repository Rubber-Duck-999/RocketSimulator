package org.rocket_simulator.graphics.simulator;

import java.awt.Image;
import java.io.File;
import javax.swing.ImageIcon;

public class Rocket
{

    private int dx;
    private int dy;
    private int x = 40;
    private int y = 60;
    private int w;
    private int h;
    private Image image;

    public Rocket() {

        loadImage();
    }

    private void loadImage() 
    {
        String file = "//mnt//c//Users//simon//Documents//Projects//C++//RocketSimulator//Software//Simulation//Simulator//src//resources//rocket.png";
        ImageIcon ii = new ImageIcon(file);
        File tempFile = new File(file);
        boolean exists = tempFile.exists();
        System.out.println("The file is this state: ");
        System.out.println(exists);
        image = ii.getImage();

        w = image.getWidth(null);
        h = image.getHeight(null);
    }

    public void move() {

        x += dx;
        y += dy;
    }

    public void move_new() {
        x += 2;
        y += 0;
    }

    public int getX() {

        return x;
    }

    public int getY() {

        return y;
    }

    public int getWidth() {

        return w;
    }

    public int getHeight() {

        return h;
    }

    public Image getImage() {

        return image;
    }
}