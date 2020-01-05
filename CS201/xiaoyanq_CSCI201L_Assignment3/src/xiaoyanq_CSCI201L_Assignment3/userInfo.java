package xiaoyanq_CSCI201L_Assignment3;

public class userInfo {
	private String userName;
	private String password;
	
	// Constructor
	public userInfo(String userName, String password)
	{
		this.userName = userName;
		this.password = password;
	}
	
	// Getters
	public String getUsername() {
		return userName;
	}
	
	public String getPassword() {
		return password;
	}
}
