package org.rocket_simulator.graphics.simulator;

import java.io.FileReader;
import java.io.File;
import java.io.*;
import java.util.List;

public class CsvReader
{
    /**
     * An example of reading using CsvBeanReader.
     */

    private static final String CSV_FILENAME = "//mnt//c//Users//simon//Documents//data.csv";

    public static void readWithCsvBeanReader() throws Exception 
    {
            
        try 
        {
                File tempFile = new File(CSV_FILENAME);
                BufferedReader br = new BufferedReader(new FileReader(tempFile)); 
  
                String st; 
                while ((st = br.readLine()) != null) 
                {
                    System.out.println(st); 
                } 
        }
        finally 
        {
        }
    }
}