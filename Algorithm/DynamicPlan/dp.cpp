//
//  dp.cpp
//  Algorithm
//
//  Created by marco on 2019/3/26.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "dp.hpp"

int Solution::coinChange(std::vector<int> &coins,int amount)
{
    std::vector<int> dp(amount+1,-1);
    dp[0] = 0;
    for (int i = 1; i<=amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            //金额大于等于面值，且差值可达
            if (i-coins[j]>=0 && dp[i-coins[j]] != -1) {
                //第一个面额或者后续面额更优，则更新
                if (dp[i]==-1 && dp[i]>dp[i-coins[j]]+1) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }
    return dp[amount];
}
