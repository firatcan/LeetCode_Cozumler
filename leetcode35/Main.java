package com.company;


public class Main {

    static int searchInsert(int[] nums, int target) {
        int size = nums.length;
        int i = 0;
        for (i = 0; i < size; i++) {
            if (nums[i] >= target)
                return i;
        }
        return i;
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 5, 6};
        int target = 2;
        int res = searchInsert(nums, target);

        System.out.println("res= " + res);
    }


}
