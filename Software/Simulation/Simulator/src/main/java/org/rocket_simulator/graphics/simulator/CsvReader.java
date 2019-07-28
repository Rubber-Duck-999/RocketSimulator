package org.rocket_simulator.graphics.simulator;

import java.io.FileReader;
import java.io.File;
import java.io.*;
import java.util.List;

import org.supercsv.cellprocessor.ParseDouble;
import org.supercsv.cellprocessor.ift.CellProcessor;
import org.supercsv.io.CsvBeanReader;
import org.supercsv.io.CsvListReader;
import org.supercsv.io.ICsvBeanReader;
import org.supercsv.io.ICsvListReader;
import org.supercsv.prefs.CsvPreference;

public class CsvReader
{
    /**
     * An example of reading using CsvBeanReader.
     */

    private static final String CSV_FILENAME = "//mnt//c//Users//simon//Documents//data.csv";

    private static CellProcessor[] getProcessors() 
    {
        
        final CellProcessor[] processors = new CellProcessor[] 
        { 
            new ParseDouble(),
            new ParseDouble(),
            new ParseDouble(), // lastName
            new ParseDouble(), // birthDate
            new ParseDouble() // mailingAddress
        };
        
        return processors;
}

    public static void readWithCsvBeanReader() throws Exception 
    {
            
        ICsvListReader beanReader = null;
        try 
        {
                beanReader = new CsvListReader(new FileReader(CSV_FILENAME), CsvPreference.STANDARD_PREFERENCE);
                File tempFile = new File(CSV_FILENAME);
                BufferedReader br = new BufferedReader(new FileReader(tempFile)); 
  
                String st; 
                while ((st = br.readLine()) != null) 
                {
                    //System.out.println(st); 
                } 
                // the header elements are used to map the values to the bean (names must match)
                //final String[] header = beanReader.getHeader(true);
                //System.out.println(header[0]);
                final CellProcessor[] processors = getProcessors();
                
                //System.out.println(beanReader.read(Entry.class, header, processors));

                //Entry value;
                List<Object> value;
                while( (value = beanReader.read(processors)) != null ) 
                {
                        System.out.println(String.format("lineNo=%d, rowNo=%d, entry=%d", beanReader.getLineNumber(),
                                beanReader.getRowNumber(), value));
                }
                
        }
        finally 
        {
                if( beanReader != null ) 
                {
                        beanReader.close();
                }
        }
    }
}