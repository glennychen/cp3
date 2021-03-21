//Design Underground System
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> map_ckin; //id, station, check-in time
    unordered_map<string, pair<int,int>> map_sum;  //station-in, station-out, pair total, people count

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {

        map_ckin[id]={stationName,t};
    }

    void checkOut(int id, string stationName, int t) {
        string& station_out=stationName;
        int& out_time=t;

        auto [station_in, in_time]=map_ckin[id];
        map_ckin.erase(id);

        string key=station_in+station_out;
        auto iter=map_sum.find(key);
        if(iter==map_sum.end()){
            map_sum.insert({key,pair{out_time-in_time,1}});
        } else {
            auto [total, people_count]=iter->second;
            iter->second={total+out_time-in_time, ++people_count};
        }
    }

    double getAverageTime(string startStation, string endStation) {
        auto [total,people_count]=map_sum[startStation+endStation];
        return (double)total/people_count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
