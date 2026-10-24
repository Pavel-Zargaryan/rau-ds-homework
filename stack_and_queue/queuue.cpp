#include <cassert>
#include <queue>
#include <utility>
#include <vector>


int time (const std::vector<int>& que,int k){
    std::queue<std::pair<int, int>> counter;
    int time = 0;
    for(int i = 0; i < que.size(); i++){
        counter.push(std::pair<int, int>(i, que[i]));
    }
    while(true){
        counter.front().second--;
        time++;
        if (counter.front().first == k && !counter.front().second) {
         break;
        }
        
       if(counter.front().second) counter.push(counter.front());
        counter.pop();
    }
    return time; 
}


int main(){
    
    std::vector<int> tickets1 = {2, 3, 2};
    std::vector<int> tickets2 = {5, 1, 1, 1};
    assert(time(tickets1,2) == 6);
    assert(time(tickets2,0) == 8);

}