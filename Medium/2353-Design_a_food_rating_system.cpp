class FoodRatings {
public:
    map<string,int> rating;
    map<string,string> cuisine;
    map<string,set<pair<int,string>>> best;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0;i<foods.size();i++){
            rating[foods[i]]=ratings[i];
            cuisine[foods[i]]=cuisines[i];
            best[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food,int newRating) {
        string c=cuisine[food];
        best[c].erase({-rating[food],food});
        rating[food]=newRating;
        best[c].insert({-newRating,food});
    }
    
    string highestRated(string c) {
        return best[c].begin()->second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
