package com.company;

import java.util.ArrayList;
import java.util.List;


public class Main {

    static boolean canJump(int[] nums) {
        if (nums.length == 0) return true;

        int j = 0;
        int counter = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[j] == 0) return false;
            counter++;
            if (nums[j] <= nums[i] || nums[j] <= counter + nums[i]) {
                j = i;
                counter = 0;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        boolean res;
        int[] nums = {2, 5, 0, 0};
        res = canJump(nums);
        System.out.println("res: " + res);
    }
}
