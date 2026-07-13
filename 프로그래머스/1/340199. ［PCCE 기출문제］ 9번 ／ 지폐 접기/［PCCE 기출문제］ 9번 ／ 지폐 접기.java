class Solution {
    static boolean check_Wallet(int[] wallet, int[] bill)
    {
        int max_Wallet = Math.max(wallet[0], wallet[1]);
        int min_Wallet = Math.min(wallet[0], wallet[1]);
        int max_Bill = Math.max(bill[0], bill[1]);
        int min_Bill = Math.min(bill[0], bill[1]);
            
        if (max_Wallet >= max_Bill && min_Wallet >= min_Bill) return true;
        return false;
    }
    
    
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        
        if (!check_Wallet(wallet, bill)) {
            while (true) {
                answer++;
                int target_Idx = -1;
                if (bill[0] >= bill[1]) target_Idx = 0;
                else target_Idx = 1;
                bill[target_Idx] /= 2;
                if (check_Wallet(wallet, bill)) {
                    break;
                }
            }
        }
        

        return answer;
    }
}

