package xiaoyanq_CSCI201L_Assignment1;

import java.util.Comparator; 
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


class The_Comparator_LN implements Comparator<Contacts_Book> {
	public int compare(Contacts_Book myCont_left, Contacts_Book myCont_right)
	{
		if(myCont_left.getLastname().equalsIgnoreCase(myCont_right.getLastname()))
		{
			return myCont_left.getFirstname().compareTo(myCont_right.getFirstname());
		}
		return myCont_left.getLastname().compareTo(myCont_right.getLastname());
	}
}

public class Contacts_Book {
	private String _firstname;
	private String _lastname;
	private String _emailAdress;
	private int _age;
	private boolean _nearCampus;
	private String _notes;
	
	public Contacts_Book(String firstname, String lastname, String emailAdress, 
			int age, boolean nearCampus, String notes)
	{
		this._firstname = firstname;
		this._lastname = lastname;
		this._emailAdress = emailAdress;
		this._age = age;
		this._nearCampus = nearCampus;
		this._notes = notes;		
	}
	
	public String getFirstname(){
		return this._firstname;
	}
	
	public String getLastname(){
		return this._lastname;
	}
	
	public String getEmailAddress(){
		return this._emailAdress;
	}
	
	public void print()
	{
		System.out.println("Name: " + this._firstname + " " + this._lastname);
		System.out.println("Email: " + this._emailAdress);
		System.out.println("Age: " + this._age);
		if(this._nearCampus)
		{
			System.out.println("Near Campus: Yes");
		}
		if(!this._nearCampus)
		{
			System.out.println("Near Campus: No");
		}
		System.out.println("Notes: " + this._notes);	
		System.out.println();
	}
	
	public void print_file(PrintWriter pw)
	{
		pw.println("Name: " + this._firstname + " " + this._lastname);
		pw.println("Email: " + this._emailAdress);
		pw.println("Age: " + this._age);
		if(this._nearCampus)
		{
			pw.println("Near Campus: Yes");
		}
		if(!this._nearCampus)
		{
			pw.println("Near Campus: No");
		}
		pw.println("Notes: " + this._notes);	
		pw.println();
	}
	
    // this function get the valid response from users
	public static String getValidOption(Scanner input)
	{
		System.out.println("1) Contact Lookup");
		System.out.println("2) Add contact");
		System.out.println("3) Delete contact");
		System.out.println("4) Print to a file");
		System.out.println("5) Exit");
		System.out.println();
		System.out.print("What option would you like to select?");
		String option = input.nextLine();
		System.out.println();
		while(!option.equalsIgnoreCase("1") && !option.equalsIgnoreCase("2") 
				&& !option.equalsIgnoreCase("3") && !option.equalsIgnoreCase("4") 
				&& !option.equalsIgnoreCase("5") && !option.contentEquals("EXIT"))
		{
			System.out.println("That is not a valid option.");
			System.out.println();
			System.out.print("What option would you like to select?");
			option = input.nextLine();
			System.out.println();
		}
		return option;
	}
	
	// a function check whether every char in a string is an alphabetic letter
	public static void checkAllAlphabet(String name) throws IOException
	{
		for(int i = 0; i < name.length(); i++)
		{
			if(!(name.charAt(i) >= 'A' && name.charAt(i) <= 'Z') && !(name.charAt(i) >= 'a' && name.charAt(i) <= 'z') && (name.charAt(i) != ' '))
			{
				throw new IOException("The parameter \"" + name + "\" cannot be parsed as a name.");
			}
		}
	}
	
	public static String checkAllAlphabetNoException(String name, String pos, Scanner input)
	{
		boolean is_valid = false;
		int invalid_count = 0;
		while(!is_valid)
		{
			for(int i = 0; i < name.length(); ++i)
			{
				if(!(name.charAt(i) >= 'A' && name.charAt(i) <= 'Z') && !(name.charAt(i) >= 'a' && name.charAt(i) <= 'z') && (name.charAt(i) != ' '))
				{
					invalid_count++;
				}
			}
			if(invalid_count > 0)
			{
				System.out.println("This is not a valid name. A name should only contain alphabetic letters.");
				System.out.println();
				System.out.print("What is the " + pos +  " of your new contact?");
				name = input.nextLine();
				System.out.println();
				invalid_count = 0;
			}
			else
			{
				is_valid = true;
			}
		}
		return name;
	}
	
	// a function check whether the format of email address is correct
	public static void checkEmailAddress(String email) throws IOException
	{
		int emailLength = email.length();
		String lastFourDigit = email.substring(emailLength-4);
		if(!lastFourDigit.equalsIgnoreCase(".edu") && !lastFourDigit.equalsIgnoreCase(".com") && !lastFourDigit.equalsIgnoreCase(".net"))
		{
			throw new IOException("The parameter \"" + email + "\" cannot be parsed as an email.");
		}
		
		int index = email.indexOf("@");
		if((index == -1) || (emailLength - 4 - index) <= 1)
		{
			throw new IOException("The parameter \"" + email + "\" cannot be parsed as an email.");
		}
	}
	
	// a function check whether the format of email address is correct without throwing an exception
	public static String checkEmailAddressNoException(String email, Scanner input)
	{
		boolean is_valid = false;
		while(!is_valid)
		{
			is_valid = true;
			int emailLength = email.length();
			if(emailLength < 6)
			{
				is_valid = false;
			}
			else
			{
				String lastFourDigit = email.substring(emailLength-4);
				if(!lastFourDigit.equalsIgnoreCase(".edu") && !lastFourDigit.equalsIgnoreCase(".com") && !lastFourDigit.equalsIgnoreCase(".net"))
				{
					is_valid = false;
				}
				
				int index = email.indexOf("@");
				if((index == -1) || (emailLength - 4 - index) <= 1)
				{
					is_valid = false;
				}
			}
			if(!is_valid)
			{
				System.out.println("That is not a valid email. An email must have this formatting:xxx@yyy.com");
				System.out.println();
				System.out.print("What is the email of your new contact?");
				email = input.nextLine();
				System.out.println();
			}
		}
		return email;
	}
	
	public static boolean checkBoolean(String on_campus) throws IOException
	{
		if(on_campus.equalsIgnoreCase("true"))
		{
			return true;
		}
		if(on_campus.equalsIgnoreCase("false"))
		{
			return false;
		}
		throw new IOException("The parameter \"" + on_campus + "\" cannot be parsed as a valid boolean.");	
	}

	public static void trimHeadTrail(String myArr[])
	{
		for(int i = 0; i < myArr.length; i++)
		{
			myArr[i] = myArr[i].trim();
		}
	}
	
	public static void main(String [] args)
	{
		Scanner input = new Scanner(System.in);
		System.out.print("What is the name of the contacts file?");
		String filename = input.nextLine();
		List<Contacts_Book> my_total_contacts = new ArrayList<Contacts_Book>();
		FileReader fr;
		BufferedReader br;
		boolean canReadFile = false;
		while(!canReadFile)
		{
			try {
				fr = new FileReader(filename);
				br = new BufferedReader(fr);
				String line = br.readLine();
				while(line != null)
				{
					String[] parse_arr = line.split(",");
					trimHeadTrail(parse_arr);
					if(parse_arr.length < 6)
					{
						throw new IOException("There are not enough parameters on line '" + line + "'.");
					}
					
					checkAllAlphabet(parse_arr[0]);
					checkAllAlphabet(parse_arr[1]);
					checkEmailAddress(parse_arr[2]);
					int age = Integer.parseInt(parse_arr[3]);
					boolean on_campus = checkBoolean(parse_arr[4]);
					String notes = parse_arr[5];
					for(int i = 6; i < parse_arr.length; ++i)
					{
						notes = notes + ", " + parse_arr[i];
					}
					notes.trim();
					
					Contacts_Book my_cont = new Contacts_Book(parse_arr[0], parse_arr[1], parse_arr[2], age, on_campus, notes);
					my_total_contacts.add(my_cont);
					Collections.sort(my_total_contacts ,new The_Comparator_LN());
					
					line = br.readLine();
				}
				canReadFile = true;
			}
			catch(FileNotFoundException fnfe){
				System.out.println("The file " + filename + " could not be found.");
				System.out.println();
				System.out.print("What is the name of the contacts file?");
				filename = input.nextLine();
			}
			catch(IOException ioe)
			{
				System.out.println("This file " + filename + " is not formatted properly.");
				System.out.println(ioe.getMessage());
				System.out.println();
				System.out.print("What is the name of the contacts file?");
				filename = input.nextLine();
			}
			catch(NumberFormatException nfe)
			{
				System.out.println("This file " + filename + " is not formatted properly.");
				System.out.println("Found an invalid age.");
				System.out.println();
				System.out.print("What is the name of the contacts file?");
				filename = input.nextLine();
			}
		}
		
		String option = getValidOption(input);
		boolean EXIT = false;
		while(!EXIT)
		{
			switch(option)
			{
				case "1":
					System.out.print("Enter the contact’s last name.");
					String lastname = input.nextLine();
					System.out.println();
					lastname.trim();
					boolean canFoundLastname = false;

			        for(Contacts_Book cont:my_total_contacts){
			        	if(cont.getLastname().equalsIgnoreCase(lastname))
			        	{
			        		cont.print();
			        		canFoundLastname = true;
			        	}
			        }
					if(!canFoundLastname)
					{
						System.out.println("There is no one with the last name " + lastname + " in your contact\n" + 
								"book.");
						System.out.println();
					}
					option = getValidOption(input);
					break;
				
				case "2":
					System.out.print("What is the firstname of your new contact?");
					String new_contact_firstname = input.nextLine();
					System.out.println();
					new_contact_firstname = checkAllAlphabetNoException(new_contact_firstname, "firstname", input);
					
					System.out.print("What is the lastname of your new contact?");
					String new_contact_lastname = input.nextLine();
					System.out.println();
					new_contact_lastname = checkAllAlphabetNoException(new_contact_lastname, "lastname", input);
					
					System.out.print("What is the email of your new contact?");
					String new_email = input.nextLine();
					System.out.println();
					new_email = checkEmailAddressNoException(new_email, input);
					// check whether the age is valid
					boolean valid_ans = false;
					int my_new_age = 0;
					while(!valid_ans)
					{
						try {
							System.out.print("What is the age of your new contact?");
							String new_age = input.nextLine();
							System.out.println();
							my_new_age = Integer.parseInt(new_age);
							valid_ans = true;
						}
						catch(NumberFormatException nfe)
						{
							System.out.println("This is not a valid age");
							System.out.println();
						}
					}
					// check whether the boolean is valid
					boolean valid_respond = false;
					boolean new_near_campus = false;
					do {
						System.out.print("Does your new contact live near campus?");
						String near_campus = input.nextLine();
						System.out.println();
						
						if(near_campus.equalsIgnoreCase("yes"))
						{
							new_near_campus = true;
							valid_respond = true;
						}
						if(near_campus.equalsIgnoreCase("no"))
						{
							new_near_campus = false;
							valid_respond = true;
						}
						
						if(!valid_respond)
						{
							System.out.println("This is not a valid boolean.");
							System.out.println();
						}
					}
					while(!valid_respond);
					// check whether the user wants to add note
					String my_notes = "";
					String add_notes = "";
					boolean valid_bool = false;
					System.out.print("Add a note about your new contact.");
					my_notes = my_notes + input.nextLine();
					do {

						System.out.println();
						System.out.print("Do you want to add another note?");
						add_notes = input.nextLine();
						System.out.println();
						if(add_notes.equalsIgnoreCase("yes"))
						{
							System.out.print("Add a note about your new contact.");
							my_notes = my_notes + ", " + input.nextLine();
						}
						else if(add_notes.equalsIgnoreCase("no"))
						{
							valid_bool = true;
						}
						else
						{
							System.out.println("This is not a valid answer");
						}
					}
					while(! valid_bool);
					my_notes.trim();
					
					Contacts_Book my_cont = new Contacts_Book(new_contact_firstname, new_contact_lastname, new_email, my_new_age, new_near_campus, my_notes);
					my_total_contacts.add(my_cont);
					Collections.sort(my_total_contacts ,new The_Comparator_LN());
					option = getValidOption(input);
					break;
				
				case "3":
					System.out.print("Enter the email of the contact you would like to delete.");
					String email = input.nextLine();
					System.out.println();
					boolean canFoundEmail = false;
					while(!canFoundEmail)
					{						
				        for(Contacts_Book contact:my_total_contacts){
				        	if(contact.getEmailAddress().equalsIgnoreCase(email))
				        	{
				        		my_total_contacts.remove(contact);
				        		String this_name = contact.getFirstname();
				        		this_name = this_name + " " + contact.getLastname();
								System.out.println(this_name + " was successfully deleted from your contact list.");
								System.out.println();
								canFoundEmail = true;
								break;
				        	}
				        }
						if(canFoundEmail == false)
						{
							System.out.println(email + " does not exist in your contact list.");
							System.out.println();
							System.out.print("Enter the email of the contact you would like to delete.");
							email = input.nextLine();
							System.out.println();
						}
					}					
					option = getValidOption(input);
					break;
				
				case "4":
					System.out.print("Enter the name of the file that you would like to print your contact\n" + 
							"list to.");
					String output_filename = input.nextLine();
					System.out.println();
					
					FileWriter fw;
					PrintWriter pw;
					try {
						fw = new FileWriter(output_filename);
						pw = new PrintWriter(fw);				

				        for(Contacts_Book contact:my_total_contacts){
				        	contact.print_file(pw);
				        }
						pw.flush();
					} 
					catch (IOException ioe) {
						System.out.println(ioe.getMessage());
					}
					System.out.println("Successfully printed all your contacts to " + output_filename);
					System.out.println();
					option = getValidOption(input);
					break;
				case "EXIT":
					System.out.println("Thank you for using my contacts program. Goodbye!");
					EXIT = true;
					break;
				case "5":
					System.out.println("Thank you for using my contacts program. Goodbye!");
					EXIT = true;
					break;	
			}
		}
	}	
}