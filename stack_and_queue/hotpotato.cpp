#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <iostream>

std::string hot_potato(int k,const std::vector<typename std::string>& players){
    std::queue<std::string> game(std::deque<std::string>(players.begin(), players.end()));
    while (game.size() > 1) {
        for(int i =0; i < k; i ++ ){
            game.push(game.front());
            game.pop();
        }
        game.pop();
    }
   
    return game.back();
}

int main(){
    std::vector<std::string> check = {"oo", "ooo","OOOOOOOOOOO"};
    std::cout << hot_potato(4,check) << std::endl;
}