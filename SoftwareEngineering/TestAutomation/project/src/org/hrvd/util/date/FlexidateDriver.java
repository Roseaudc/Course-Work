package org.hrvd.util.date;


import org.hrvd.util.date.Flexidate;
import java.util.GregorianCalendar;
import java.util.Calendar;
import java.util.ArrayList;
import java.util.List;

import java.io.*;


public class FlexidateDriver {

	static int testCaseNumber;
	static String result;
	
	public static void main(String[] args)
	{
		String method = args[0];
		String input = args[1];
		testCaseNumber = Integer.parseInt(args[2]);
		// parse the input argument
		String[] dateParameters = input.split(";");
	
		String[] firstDateParameters = dateParameters[0].split(",");
		String[] secondDateParameters = dateParameters[1].split(",");		
		
		int firstDateYear = Integer.parseInt(firstDateParameters[0]);
		int firstDateMonth = Integer.parseInt(firstDateParameters[1]);
		int firstDateDay = Integer.parseInt(firstDateParameters[2]);

		int secondDateYear = Integer.parseInt(secondDateParameters[0]);
		int secondDateMonth = Integer.parseInt(secondDateParameters[1]);
		int secondDateDay = Integer.parseInt(secondDateParameters[2]);

		// create two calendars that will be used as input for flexidate object
		Calendar date1 = new GregorianCalendar(firstDateYear, firstDateMonth, firstDateDay);
		Calendar date2 = new GregorianCalendar(secondDateYear, secondDateMonth, secondDateDay);
		
		// create the flexidate object
		Flexidate flexidate = new Flexidate(date1, date2); 

		switch(method)
		{
			case "getRange":
				 result = testGetRange(flexidate);
				 break;
			case "getMonth":
				result = testGetMonth(flexidate);
				break;
			case "getYear":
				result = testGetYear(flexidate);
				break;
			case "getDay":
				result = testGetDay(flexidate);
				break;
			default:
				result = "method is not valid";
				break;
							
		} 

		
		writeResultToFile(result);
	}


	private static String testGetRange(Flexidate flexidate)
	{
		
		String range = Integer.toString(flexidate.getRange());				
		return range;
	}	
	
	private static String testGetYear(Flexidate flexidate)
	{
		String year = Integer.toString(flexidate.getYear());
		return year;
	}
	
	private static String testGetMonth(Flexidate flexidate)
	{
		String month = Integer.toString(flexidate.getMonth());
		return month;
	}
	
	private static String testGetDay(Flexidate flexidate)
	{
		String day = Integer.toString(flexidate.getDay());
		return day;
	}
		
	private static void writeResultToFile(String result)
	{
		String filename;
        if(testCaseNumber < 10)
        	filename = "../../temp/testCase0" + testCaseNumber + "Results.txt";
        else
        	filename = "../../temp/testCase" + testCaseNumber + "Results.txt";
        try (Writer writer = new BufferedWriter(new OutputStreamWriter(
            new FileOutputStream(filename), "utf-8"))) 
        {
  			writer.write(result);
  			writer.write("\n");
  		}
  				
  		catch ( Throwable t ) 
        {
            t.printStackTrace( System.err );
       	}
  	}
				

}
