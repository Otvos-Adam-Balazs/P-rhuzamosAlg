package MultiBead;

public class Multithreading{
	
	private MultithreadThing[] sums;
	private int numOfThreads;
	
	public Multithreading(int numOfThreads) {
		this.numOfThreads = numOfThreads;
		this.sums = new MultithreadThing[numOfThreads];
	}
	
	public long sum(long[] nums) {
		float steps = (float) Math.ceil(nums.length * 1.0/ numOfThreads);
		
		for(int i =0; i<numOfThreads;i++) {
			sums[i] = new MultithreadThing(nums, i*steps, (i+1)*steps);
			sums[i].start();
		}
		
		try {
			for(MultithreadThing worker : sums) 
				worker.join();
		}catch(InterruptedException e) {
			e.printStackTrace();
		}
		
		long total = 0;
		
		for(MultithreadThing worker : sums)
			total = total + worker.getPartialSum();
		
		return total;
	}
}