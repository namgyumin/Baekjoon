import java.util.*;
import java.lang.*;



public class Main {
    public static class element implements Comparable{
        private int left;
        private int right;

        public element(){
            left = 0;
            right = 0;
        }

        public element(int a, int b){
            left = a;
            right = b;
        }

        public int getLeft(){
            return this.left;
        }
        
        public int getRight(){
            return this.right;
        }

        @Override
        public int compareTo(Object o) {
            element a = (element) o;
            return a.getLeft() - this.getLeft();
        }

    }
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        int n;
        n = keyboard.nextInt();
        ArrayList<element> arr = new ArrayList<>();
        for(int i = 0; i < n; i++){
            int t1, t2;
            t1 = keyboard.nextInt();
            t2 = keyboard.nextInt();
            element temp = new element(t1, t2);
            arr.add(temp);
        }
        arr.sort(null);

        int[] dp = new int[n];
        for(int i = 0; i < n; i++){
            dp[i] = 1;
        }
        int max = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(arr.get(i).getRight() > arr.get(j).getRight()){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(max < dp[i]){
                max = dp[i];
            }
        }
        System.out.println(n - max);
    }

}
