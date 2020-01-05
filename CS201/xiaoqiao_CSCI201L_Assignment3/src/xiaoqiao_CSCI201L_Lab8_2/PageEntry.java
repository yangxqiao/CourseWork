package xiaoqiao_CSCI201L_Lab8_2;

public class PageEntry {
	// Private variables
	private String pageName;
	private int portNumber;
	private int count;
	private String ipAddress;
	
	// Constructor
	public PageEntry(String pageName, int portNumber, int count, String ipAddress)
	{
		this.pageName = pageName;
		this.portNumber = portNumber;
		this.count = count;
		this.ipAddress = ipAddress;
	}
	
	// Getters
	public String getPageName() {
		return pageName;
	}
	
	public int getPortNumber() {
		return portNumber;
	}
	
	public int getCount() {
		return count;
	}
	
	public String getIpAddress() {
		return ipAddress;
	}
}
