package MultiBead;

public class MultithreadThing extends Thread{
	private int threadNumber;
	
	public MultithreadThing (int threadNumber) {
		this.threadNumber = threadNumber;
	}
	
	@Override
	public void run() {
		
			
			long alma = fibonacci(45);
			System.out.print("\n" + alma +"," + threadNumber);
			//try {
				//Thread.sleep(1000);
			//} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				//e.printStackTrace();
			//}
		
	}
	
	public long fibonacci(long n)  {
    if(n == 0)
        return 0;
    else if(n == 1)
      return 1;
   else
      return fibonacci(n - 1) + fibonacci(n - 2);
	}
}