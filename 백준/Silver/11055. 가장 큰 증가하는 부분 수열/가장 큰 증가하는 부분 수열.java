import java.util.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        int n;
        Scanner keyboard = new Scanner(System.in);
        n = keyboard.nextInt();

        int[] arr = new int[n];
        int[] dp = new int[n];

        for(int i =0; i < n; i++){
            arr[i] = keyboard.nextInt();
            dp[i] = arr[i];
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(arr[i] < arr[j]){
                    if(dp[i] < arr[i] + dp[j]){
                        dp[i] = arr[i] + dp[j];
                    }
                }
            }
        }

        int max = Arrays.stream(dp).max().getAsInt();

        System.out.println(max);
    }

}
