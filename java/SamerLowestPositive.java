import java.util.Arrays;

public class SamerLowestPositive
{
	private static int[] nums = { 1, 2, 3, 3, 3, 3 }; //{ 3, 8, 5, 23, 654, 7, 3, 67, 9, 4, 2, 1, 6 };
	
	public static void main(String[] args)
	{
		Arrays.sort(nums);
		System.out.println(getLowestPositiveNumNotInList(nums));
		
	}
	
	private static int getLowestPositiveNumNotInList(int[] nums) {
		if (nums[0] - 1 > 0) {
			return nums[0] - 1;
		} else {
			int num = nums[0] + 1;
			
			for (int i = 1; i < nums.length; i++) {
				if (num < nums[i]) {
					return num;
				} else if (num == nums[i]) {
					num++;
				}
			}
			
			return nums[nums.length-1] + 1;
		}
	}
}
