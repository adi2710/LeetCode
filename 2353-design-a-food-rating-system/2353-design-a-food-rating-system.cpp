struct compare {
    bool operator() (const pair<int, string> &a, const pair<int, string> &b) const {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class FoodRatings {
public:
    
    unordered_map<string, set<pair<int, string>, compare>> cuisineFoodMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, int> foodRatingMap;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            foodCuisineMap[foods[i]] = cuisines[i];
            foodRatingMap[foods[i]] = ratings[i];
            cuisineFoodMap[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisineMap[food];
        int rating = foodRatingMap[food];
        cuisineFoodMap[cuisine].erase({rating, food});
        foodRatingMap[food] = newRating;
        cuisineFoodMap[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*cuisineFoodMap[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */