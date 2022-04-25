package MultiBead;
import java.util.Random;

public class App {

	public static void main(String[] args) {
		
		Random random = new Random();
		
		long[] nums = new long [32500000];
		
		for(int i=0; i<nums.length;i++) {
			nums[i] = random.nextInt(100);
		}
		
		long start = System.currentTimeMillis();
		
		Multithreading Multithreading = new Multithreading(2);
		System.out.println("\nSum is " + Multithreading.sum(nums));
		System.out.println("\nParallel sum takes: " + (System.currentTimeMillis() - start)+"ms");

	}

}