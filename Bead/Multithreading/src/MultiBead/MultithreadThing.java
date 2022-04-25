package MultiBead;

public class MultithreadThing extends Thread{
	private long[] nums;
	private float low;
	private float high;
	private long partialSum;
	
	public MultithreadThing(long[] nums, float low, float high) {	
		this.nums = nums;
		this.low = low;
		this.high = high;
	}

	public long getPartialSum() {
		return this.partialSum;
	}
	
	@Override	
	public void run() {
		partialSum = 0;
		
		for(long i=(long)low; i<high; i++) {
			partialSum = partialSum + nums[(int)i];
		}
	}
}