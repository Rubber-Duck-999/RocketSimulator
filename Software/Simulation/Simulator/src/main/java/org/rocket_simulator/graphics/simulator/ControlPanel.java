package org.rocket_simulator.graphics.simulator;

import javax.swing.*;
import java.awt.EventQueue;

public class ControlPanel extends JFrame
{
    public ControlPanel()
    {
        initUI();
    }

    private void initUI()
    {
        add(new board());

        setTitle("Moving Rocket");

        setSize(640,480);
        setLocationRelativeTo(null);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    public static void main(String[] args)
    {
        System.out.println("Starting Control Panel");
        /*CsvReader csv = new CsvReader();
        csv.run();
        */
        EventQueue.invokeLater(() -> {
            ControlPanel con = new ControlPanel();
            con.setVisible(true);
        });
    }

}
