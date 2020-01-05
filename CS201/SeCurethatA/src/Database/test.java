package Database;

public class test {
	
	public static void main(String[] args) {
		
		DatabaseOperator1 do1 = new DatabaseOperator1();
		do1.addUser("root", "123456");
		//authenticate test
		if(!do1.authenticate("root", "1234")) {
			System.out.println("pass authenticate test with not correct password.");
		}
		else {
			System.out.println("fail authenticate test with not correct password.");
		}
		if(do1.authenticate("root", "123456")) {
			System.out.println("pass authenticate test with correct password.");
		}
		else {
			System.out.println("fail authenticate test with correct password.");
		}
		//user exist test
		if(!do1.userExist("trojan")) {
			System.out.println("pass user not exist test.");
		}
		else {
			System.out.println("fail user not exist test.");
		}
		if(!do1.userExist("root")) {
			System.out.println("pass user exist test.");
		}
		else {
			System.out.println("fail user exist test.");
		}
	}

}
