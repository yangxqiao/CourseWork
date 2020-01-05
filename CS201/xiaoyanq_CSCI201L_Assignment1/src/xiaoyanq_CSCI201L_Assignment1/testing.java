package xiaoyanq_CSCI201L_Assignment1;

import java.util.Scanner;


public class testing {
	public static int quotient(int number1, int number2)
	{
		if(number2 == 0)
		{
			throw new ArithmeticException("Divisor cannot be zero.");
//			return 0;
		}
		else {
			return number1/number2;
		}
	}
	
	public static void main(String [] args)
	{
		Scanner input = new Scanner(System.in);
		
//		System.out.print("Enter two integer: ");
//		int num1 = input.nextInt();
//		int num2 = input.nextInt();
//		
		boolean noValidInput = true;
		while(noValidInput)
		{
			try {
				int result = 0;
				while(result == 0)
				{
					System.out.print("Enter two integer: ");
					int num1 = input.nextInt();
					int num2 = input.nextInt();
					result = quotient(num1, num2);
					System.out.println(num1 + '/' + num2 + " is " + result);
					noValidInput = false;
				}
				
			}
			catch (ArithmeticException aex){
				System.out.println(aex.getMessage());
				
			}
		}
		System.out.println("Execution continues");
	}
}
