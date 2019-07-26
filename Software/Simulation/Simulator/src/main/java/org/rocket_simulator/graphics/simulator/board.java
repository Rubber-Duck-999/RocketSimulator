package org.rocket_simulator.graphics.simulator;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.JPanel;
import javax.swing.Timer;

public class board extends JPanel implements ActionListener {

    private Timer timer;
    private Rocket rocket;
    private final int DELAY = 10;

    public board() {

        initBoard();
    }

    private void initBoard() {

        addKeyListener(new TAdapter());
        setBackground(Color.black);
        setFocusable(true);

        rocket = new Rocket();

        timer = new Timer(DELAY, this);
        timer.start();
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        doDrawing(g);

        Toolkit.getDefaultToolkit().sync();
    }

    private void doDrawing(Graphics g) {

        Graphics2D g2d = (Graphics2D) g;

        g2d.drawImage(rocket.getImage(), rocket.getX(),
                rocket.getY(), this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        step();
    }

    private void step() {

        rocket.move_new();

        repaint(rocket.getX()-1, rocket.getY()-1,
                rocket.getWidth()+2, rocket.getHeight()+2);
    }

    private class TAdapter extends KeyAdapter {

        @Override
        public void keyReleased(KeyEvent e) {
            rocket.keyReleased(e);
        }

        @Override
        public void keyPressed(KeyEvent e) {
            rocket.keyPressed(e);
        }
    }
}