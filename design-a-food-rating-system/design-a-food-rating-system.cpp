class FoodRatings {
    unordered_map<string, set<pair<int, string>>> rating;
    unordered_map<string, int> mpFood_to_rating;
    unordered_map<string, string> mpFood_to_cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); ++i){
            rating[cuisines[i]].insert({-ratings[i],foods[i]});
            mpFood_to_rating[foods[i]] = ratings[i];
            mpFood_to_cuisine[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuis = getCuisine(food);
        int oldRating = getRating(food);
        rating[cuis].erase({-oldRating, food});
        rating[cuis].insert({-newRating, food});
        mpFood_to_rating[food] = newRating;
    }
    
    int getRating(string& food){
        return mpFood_to_rating[food];
    }
    string getCuisine(string& food){
        return mpFood_to_cuisine[food];
    }

    string highestRated(string cuisine) {
        return (rating[cuisine].begin())->second;
        // vector<string> foods_in_cuisine = mpCuisine_to_food[cuisine];
        // string ans = foods_in_cuisine[0];
        // int rating_ans = getRating(ans);
        // for(int i=0; i<foods_in_cuisine.size(); ++i){
        //     if(getRating(foods_in_cuisine[i]) > rating_ans){
        //         ans = foods_in_cuisine[i];
        //         rating_ans = getRating(ans);
        //     }
        //     else if(getRating(foods_in_cuisine[i]) == rating_ans){
        //         ans = min(ans, foods_in_cuisine[i]);    
        //     }
        // }
        // return ans;

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */