import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Customer extends Thread {

	private int customerName;
	private SleepingBarber firstsb;
	private SleepingBarber secondsb;
	private Lock customerLock;
	private Condition gettingHaircutCondition;
	public Customer(int customerName, SleepingBarber firstsb, SleepingBarber secondsb) {
		this.customerName = customerName;
		this.firstsb = firstsb;
		this.secondsb = secondsb;
		customerLock = new ReentrantLock();
		gettingHaircutCondition = customerLock.newCondition();
	}
	
	public int getCustomerName() {
		return customerName;
	}
	public void startingHaircut() {
		Util.printMessage("Customer " + customerName + " is getting hair cut.");
	}
	public void finishingHaircut() {
		Util.printMessage("Customer " + customerName + " is done getting hair cut.");
		try {
			customerLock.lock();
			gettingHaircutCondition.signal();
		} finally {
			customerLock.unlock();
		}
	}
	
	public void run() {
		boolean seatsAvailable = SleepingBarber.addCustomerToWaiting(this);
		if (!seatsAvailable) {
			Util.printMessage("Customer " + customerName + " leaving...no seats available.");
			return;
		}
		
		if(firstsb.is_sleeping && secondsb.is_sleeping)
		{
			firstsb.wakeUpBarber();
//			firstsb.is_sleeping = false;
		}
		else if(firstsb.is_sleeping)
		{
			firstsb.wakeUpBarber();
//			firstsb.is_sleeping = false;
		}
		else if(secondsb.is_sleeping)
		{
			secondsb.wakeUpBarber();
//			secondsb.is_sleeping = false;
		}
		
		try {
			customerLock.lock();
			gettingHaircutCondition.await();
		} catch (InterruptedException ie) {
			System.out.println("ie getting haircut: " + ie.getMessage());
		} finally {
			customerLock.unlock();
//			firstsb.is_sleeping = false;
//			secondsb.is_sleeping = false;
		}
		Util.printMessage("Customer " + customerName + " is leaving.");
	}
}
