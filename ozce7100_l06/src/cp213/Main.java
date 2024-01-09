package cp213;


import java.util.Scanner;
import java.util.InputMismatchException;

public class Main {

    /**
     * @param args unused
     */
    public static void main(String[] args) {
	System.out.println("Test scannerTest");
	System.out.println();
	Scanner keyboard = new Scanner(System.in);
	int total = scannerTest(keyboard);
	keyboard.close();
	System.out.println("Total: " + total);
	System.out.println();

	System.out.print("Test stringPrinter");
	System.out.println();

	try {
	    String output = stringPrinter(5, "*");
	    System.out.println(output);
	    output = stringPrinter(-5, "*");
	    System.out.println(output);
	} catch (Exception e) {
	    System.out.println();
	    System.out.println("getMessage:");
	    System.out.println(e.getMessage());
	    System.out.println();
	    System.out.println("toString:");
	    System.out.println(e.toString());
	    System.out.println();
	    System.out.println("printStackTrace:");
	    e.printStackTrace();
	}
    }

    /**
     * Uses exceptions to capture bad input from a keyboard Scanner.
     *
     * @return The total of all the integers entered.
     */
    public static int scannerTest(final Scanner keyboard) {
    	int tot = 0;
    	do {
   			System.out.println("Enter an integer ('Quit' to stop): ");
   			try {
       			int scan = keyboard.nextInt();
       			tot += scan;
    		}
   			catch(InputMismatchException error) {
   				if(keyboard.nextLine().equals("Quit")) {
   					break;
    			}else {
    				System.out.println("This is not an integer!");
    			}
   			}	
   		}while(true);
    	keyboard.close();
    	return tot;
    }

    /**
     * Repeats a string.
     *
     * @param n   Number of times to repeat a string.
     * @param str The string to print.
     * @return The repeated string.
     * @throws Exception If n is negative.
     */
    public static String stringPrinter(int n, String str) throws Exception {

    	String newStr = "";
    	if(n < 0) { 
    		throw new IllegalArgumentException("Please Enter a Positive Number! ");
    		}
    	for(int i = 0; i < n; i++) {
    		newStr = newStr + str;
    	}
	return newStr;
    }

}
