#include "MatrixChain.hpp"

#include <iostream>
/// @brief
/// how many operation we need to perfor multiplication of two matrixes @param left and @param right
///
int CostOfTwoMatrixMultiplication(const std::pair<int, int>& left, const std::pair<int, int>& right){
    return left.first * left.second * right.second;
}
int MatrixChainMulCount(std::vector<std::pair<int, int>>& matrixes){
    if(matrixes.size() == 0) return 0;

    // create matrix for storing the resul with [matrixes.size() x matrixes.size()] dimensions, and fill the matrix with 0 values
    std::vector<std::vector<int>> results(matrixes.size(), std::vector<int>(matrixes.size(), 0));


    // fill the results of multiplication coas for two anjecent matrixes
    for(int i = 1; i < results.size(); i++) {
        results[i-1][i] = CostOfTwoMatrixMultiplication(matrixes[i-1], matrixes[i]);
    }
    // for(int i = 2; i < results.size(); i++) {
    //     for(int j = 0; j < results.size() - i; j++ ) {
    //         int value = -1;
    //         for(int k = i; k < j ; k++ ) {
    //             CostOfTwoMatrixMultiplication()
    //         }

    //     }
    // }

    for(auto v: results){
        for(auto i: v){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
    return 1;
 }