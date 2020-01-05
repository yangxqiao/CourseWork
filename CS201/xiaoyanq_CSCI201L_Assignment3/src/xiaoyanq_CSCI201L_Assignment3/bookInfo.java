package xiaoyanq_CSCI201L_Assignment3;

public class bookInfo {
	private String bookname;
	private String authorname;
	private String publisher;
	private String publishdate;
	private String ISBN;
	private String description;
	private String username;
	private String image;
	private String rating;
	
	// Constructor
	public bookInfo(String bookname, String authorname, String publisher, String publishdate, String ISBN, String description, String userName, String image, String rating)
	{
		this.bookname = bookname;
		this.authorname = authorname;
		this.publishdate = publishdate;
		this.publisher = publisher;
		this.ISBN = ISBN;
		this.description = description;
		this.username = userName;
		this.image = image;
		this.rating = rating;
	}
	
	// Getters
	public String getUsername() {
		return username;
	}
	
	public String getBookname() {
		return bookname;
	}
	
	public String getAuthorname() {
		return authorname;
	}
	
	public String getPublisher() {
		return publisher;
	}
	
	public String getPublishdate() {
		return publishdate;
	}
	
	public String getISBN() {
		return ISBN;
	}
	
	public String getDescription() {
		return description;
	}
	
	public String getImage() {
		return image;
	}
	
	public String getRating() {
		return rating;
	}
}
