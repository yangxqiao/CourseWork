package gameRoom;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Properties;
import java.util.Scanner;

public class GameClient extends Thread {
	private static String ServerHostname = "";
	private static String ServerPort = "";
	private static String DBConnection = "";
	private static String DBUsername = "";
	private static String DBPassword = "";
	private static String SecretWordFile = "";

	private BufferedReader br;
	private PrintWriter pw;

	public GameClient(String hostname, int port, Scanner input) {
		try {
			Socket s = new Socket(hostname, port);
			System.out.println("Trying to connect to server...Connected!");
			System.out.println();
			br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			pw = new PrintWriter(s.getOutputStream());
			this.start();
			
			while(true) {
				String line = input.nextLine();
				pw.println(line);
				pw.flush();
			}
		} 
		catch (IOException ioe) {
			System.out.println("Trying to connect to server...Unable to connect to");
			System.out.println("server " + ServerHostname + " on post " + ServerPort);
		}
	}
	
	public void run() {
		try {
			while(true) {
				String line = br.readLine();
				System.out.println(line);
			}
		} 
		catch (IOException ioe) {
			System.out.println("ioe in ChatClient.run(): " + ioe.getMessage());
		}
	}
	
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("What is the name of the configuration file?");
		String filename = input.nextLine();
		System.out.println("Reading configuration file...");
		FileReader fr;
		String param = "";
		
		boolean canReadFile = false;
		while(!canReadFile)
		{
			try {
				fr = new FileReader(filename);
				Properties prop = new Properties();
				prop.load(fr);
				
				ServerHostname = prop.getProperty("ServerHostname");
				ServerPort = prop.getProperty("ServerPort");
				DBConnection = prop.getProperty("DBConnection");
				DBUsername = prop.getProperty("DBUsername");
				DBPassword = prop.getProperty("DBPassword");
				SecretWordFile = prop.getProperty("SecretWordFile");
				
				if(ServerHostname == null)
				{
					throw new IOException("ServerHostname is a required parameter in the configuration file.");
				}
				if(ServerPort == null)
				{
					throw new IOException("ServerPort is a required parameter in the configuration file.");
				}
				if(DBConnection == null)
				{
					throw new IOException("DBConnection is a required parameter in the configuration file.");
				}
				if(DBUsername == null)
				{
					throw new IOException("DBUsername is a required parameter in the configuration file.");
				}
				if(DBPassword == null)
				{
					throw new IOException("DBPassword is a required parameter in the configuration file.");
				}
				if(SecretWordFile == null)
				{
					throw new IOException("SecretWordFile is a required parameter in the configuration file.");
				}
				
				System.out.println("Server Hostname – " + ServerHostname);
				System.out.println("Server Port – " + ServerPort);
				System.out.println("Database Connection String – " + DBConnection);
				System.out.println("Database Username - " + DBUsername);
				System.out.println("Database Password - " + DBPassword);
				System.out.println("Secret Word File - " + SecretWordFile);
				System.out.println();

				canReadFile = true;
			}
			catch(FileNotFoundException fnfe){
				System.out.println("The file " + filename + " could not be found.");
				System.out.println("What is the name of the contacts file?");
				filename = input.nextLine();
			}
			catch(IOException ioe)
			{
				System.out.println(ioe.getMessage());
				System.out.println("What is the name of the configuration file?");
				filename = input.nextLine();
			}
		}
		
		int port = Integer.parseInt(ServerPort);
		
		GameClient gc = new GameClient(ServerHostname, port, input);
	}
}
