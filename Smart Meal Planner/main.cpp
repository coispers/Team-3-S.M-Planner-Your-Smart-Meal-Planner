    #include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>
#include <limits>
#include <algorithm>
#include <vector>
#include <thread>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

double result;
string bmiResult, recommendation;
float menBMR;
float womenBMR;
int y = 1,buffed;
int days;
int n = 0;

void print_loading_bar(int n) {
    for (int i = 0; i < n; i++) {
        cout << "=";
    }
    for (int i = n; i < 50; i++) {
        cout << " ";
    }
    cout << " " << n * 2 << "%\r";
    cout.flush();
}

void print_header(string text) {
  system("CLS");
  cout << string(60, '=') << endl;
  cout << setw(37) << text << endl;
  cout << string(60, '=') << endl;
}

struct Node {
    string name;
    string data;
    Node* next;

    Node(const string& name, const string& data)
        : name(name), data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(const string& name, const string& data) {
        Node* newNode = new Node(name, data);
        newNode->next = head;
        head = newNode;
    }

    Node* search(const string& searchMeal) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == searchMeal) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Meal not found
    }
};

void mealList(LinkedList& myList) {
    myList.insert( "Apple Cinnamon Oatmeal" , "Meals/Breakfast/Apple cinnamon oatmeal.txt");
    myList.insert( "Avocado Toast" , "Meals/Breakfast/Avocado Toast.txt");
    myList.insert( "Banana Pancakes" , "Meals/Breakfast/Banana Pancakes.txt");
    myList.insert( "Breakfast Burrito" , "Meals/Breakfast/Breakfast Burrito.txt");
    myList.insert( "Breakfast Quiche" , "Meals/Breakfast/Breakfast quiche.txt");
    myList.insert( "Cottage Cheese with Fruits" , "Meals/Breakfast/Cottage Cheese with fruits.txt");
    myList.insert( "Egg and Veggie Wrap" , "Meals/Breakfast/Egg and Veggie Wrap.txt");
    myList.insert( "Greek Yogurt Parfait" , "Meals/Breakfast/Greek Yogurt Parfait.txt");
    myList.insert( "Green Breakfast Bowl" , "Meals/Breakfast/Green Breakfast bowl.txt");
    myList.insert( "Overnight Chia Pudding" , "Meals/Breakfast/Overnight Chia Pudding.txt");
    myList.insert( "Peanut Butter Banana Toast" , "Meals/Breakfast/Peanut butter banana toast.txt");
    myList.insert( "Protein Smoothie" , "Meals/Breakfast/Protein smoothie.txt");
    myList.insert( "Quinoa Breakfast Bowl" , "Meals/Breakfast/Quinoa breakfast bowl.txt");
    myList.insert( "Smoked Salmon Toast" , "Meals/Breakfast/Smoked salmon toast.txt");
    myList.insert( "Smoothie Bowl" , "Meals/Breakfast/Smoothie Bowl.txt");
    myList.insert( "Sweet Potato Hash" , "Meals/Breakfast/Sweet potato hash.txt");
    myList.insert( "Tofu Scramble" , "Meals/Breakfast/Tofu scramble.txt");
    myList.insert( "Veggie Breakfast Wrap" , "Meals/Breakfast/Veggie breakfast wrap.txt");
    myList.insert( "Veggie Omelette" , "Meals/Breakfast/veggie Omellete.txt");
    myList.insert( "Whole Grain Cereal" , "Meals/Breakfast/Whole Grain Cereal.txt");
    myList.insert( "Asian Chicken Quinoa Bowl with Almond Butter Sauce" , "Meals/Lunch/Asian Chicken Quinoa bowl with almond butter sauce.txt");
    myList.insert( "BLT Pasta Salad" , "Meals/Lunch/BLT Pasta salad.txt");
    myList.insert( "Cheesy Seafood Bake" , "Meals/Lunch/Cheesy seafood bake.txt");
    myList.insert( "Chicken Satay Salad" , "Meals/Lunch/Chicken Satay Salad.txt");
    myList.insert( "Chicken Shawarma Salad" , "Meals/Lunch/Chicken Shawarma Salad.txt");
    myList.insert( "Grilled Pork Tenderloin" , "Meals/Lunch/Grilled pork tenderloin with avocado green sauce.txt");
    myList.insert( "Halloumi, Carrot, and Orange Salad" , "Meals/Lunch/Halloumi, carrot, and orange salad.txt");
    myList.insert( "Mexican Spiced Grilled Chicken with Nectarine Salsa" , "Meals/Lunch/Mexican Spiced Grilled Chicken with Nectarine Salsa.txt");
    myList.insert( "Paleo &Whole30 Sesame Chicken" , "Meals/Lunch/Paleo &whole30 sesame chicken.txt");
    myList.insert( "Peanut Chicken Wrap" , "Meals/Lunch/Peanut Chicken Wrap.txt");
    myList.insert( "Pesto Grilled Cheese" , "Meals/Lunch/Pesto Grilled Cheese.txt");
    myList.insert( "Salmon Meal Prep with Veggies" , "Meals/Lunch/Salmon Meal Prep with veggies.txt");
    myList.insert( "Scrambled Egg and Feta Fash" , "Meals/Lunch/Scrambled Egg and feta hash.txt");
    myList.insert( "Sheet Pan Honey Lemon Salmon" , "Meals/Lunch/Sheet pan honey lemon salmon.txt");
    myList.insert( "Skillet Egg Frittata" , "Meals/Lunch/Skillet Egg Frittata.txt");
    myList.insert( "Skirt Steak Meal Prep" , "Meals/Lunch/Skirt Steak Meal Prep.txt");
    myList.insert( "Spicy Cajun Chicken Quinoa" , "Meals/Lunch/Spicy Cajun Chicken Quinoa.txt");
    myList.insert( "Spicy Fish Stew" , "Meals/Lunch/Spicy Fish Stew.txt");
    myList.insert( "Taco Soup" , "Meals/Lunch/Taco soup.txt");
    myList.insert( "Teriyaki Grilled Eggplant" , "Meals/Lunch/Teriyaki Grilled Eggplant.txt");
    myList.insert( "Thai Tofu Collard Wraps" , "Meals/Lunch/Thai Tofu Collard wraps.txt");
    myList.insert( "Vegan Chickpea Curry Jacket Potatoes" , "Meals/Lunch/Vegan Chickpea curry jacket potatoes.txt");
    myList.insert( "Vegan Grain Bowl with Pesto" , "Meals/Lunch/Vegan Grain Bowl with pesto.txt");
    myList.insert( "White Chicken Chili" , "Meals/Lunch/White Chicken Chili.txt");
    myList.insert( "Beef and Brocolli" , "Meals/Dinner/beef and brocolli.txt");
    myList.insert( "Cauliflower Pizza" , "Meals/Dinner/Cauliflower Pizza.txt");
    myList.insert( "Chicken and Vegetable Stir Fry" , "Meals/Dinner/Chicken and stir fry.txt");
    myList.insert( "Chicken and Vegetable Skewers" , "Meals/Dinner/chicken and vegetable skewers.txt");
    myList.insert( "Egg and Vegetable Scramble" , "Meals/Dinner/Egg and vegetable scramble.txt");
    myList.insert( "Grilled Cheese Sandwich and Tomato Soup" , "Meals/Dinner/Grilled cheese sandwich and tomato soup.txt");
    myList.insert( "Ham and Cheese Quiche" , "Meals/Dinner/ham and cheese quiche.txt");
    myList.insert( "Lentil and Vegetable Stew" , "Meals/Dinner/Lentil and vegetable stew.txt");
    myList.insert( "Mushroom Risotto" , "Meals/Dinner/Mushroom Risotto.txt");
    myList.insert( "Pizza" , "Meals/Dinner/Pizza.txt");
    myList.insert( "Roasted Chicken and Vegetables" , "Meals/Dinner/roasted chicken and vegetables.txt");
    myList.insert( "Salmon and Roasted Vegetables" , "Meals/Dinner/Salmon and Roasted Vegetables.txt");
    myList.insert( "Spaghetti Bolognese" , "Meals/Dinner/Spaghetti bolognese.txt");
    myList.insert( "Taco Salad" , "Meals/Dinner/Taco Salad.txt");
    myList.insert( "Thai Chicken Noodle Soup" , "Meals/Dinner/Thai Chicken Noodle soup.txt");
    myList.insert( "Turkey Burger with Sweet Potato Fries" , "Meals/Dinner/Turkey Burger with sweet potato fries.txt");
    myList.insert( "Vegetable Curry with Rice" , "Meals/Dinner/Vegetable curry with rice.txt");
    myList.insert( "Vegetable Lasagna" , "Meals/Dinner/vegetable lasagna.txt");
    myList.insert( "Vegetable Sushi" , "Meals/Dinner/Vegetable sushi.txt");

}

struct Meal {
    string umagahan;
    string tanghalian;
    string hapunan;
};

struct meals {
    string name;
    int calr;
    float protn;
} set[75];

void predefmeals() {
    // breakfast[0-24]
    set[0] = {"Veggie Omelette", 275, 18};
    set[1] = {"Greek Yogurt Parfait", 275, 18};
    set[2] = {"Avocado Toast", 175, 8};
    set[3] = {"Overnight Chia Pudding", 175, 8};
    set[4] = {"Smoothie Bowl", 275, 13};
    set[5] = {"Whole Grain Cereal", 175, 7};
    set[6] = {"Egg and Veggie Wrap", 275, 18};
    set[7] = {"Banana Pancakes", 250, 13};
    set[8] = {"Cottage Cheese with Fruit", 175, 13};
    set[9] = {"Breakfast Burrito", 325, 23};
    set[10] = {"Quinoa Breakfast Bowl", 250, 13};
    set[11] = {"Apple Cinnamon Oatmeal", 225, 7};
    set[12] = {"Veggie Breakfast Wrap", 275, 13};
    set[13] = {"Protein Smoothie", 225, 17};
    set[14] = {"Breakfast Quiche", 150, 18};
    set[15] = {"Peanut Butter Banana Toast", 275, 8};
    set[16] = {"Green Breakfast Bowl", 225, 13};
    set[17] = {"Tofu Scramble", 250, 18};
    set[18] = {"Sweet Potato Hash", 275, 8};
    set[19] = {"Smoked Salmon Toast", 350, 18};

    // lunch[25-49]
    set[25] = {"Teriyaki Grilled Eggplant", 163, 4};
    set[26] = {"Grilled Pork Tenderloin", 210, 24};
    set[27] = {"Taco Soup", 163, 15};
    set[28] = {"Skillet Egg Frittata", 304, 25};
    set[29] = {"Mexican-Spiced Grilled Chicken with Nectarine Salsa", 351, 37.2};
    set[30] = {"Vegan Grain Bowl Pesto", 480, 20};
    set[31] = {"Paleo & Whole30 Sesame Chicken", 432, 29};
    set[32] = {"Sheet Pan Honey Lemon Salmon", 758, 43};
    set[33] = {"White Chicken Chili", 383, 33};
    set[34] = {"Asian Chicken Quinoa Bowl with Almond Butter Sauce", 55, 34};
    set[35] = {"Thai Tofu Collard Wraps", 284, 13};
    set[36] = {"Chicken Cobb Salad", 407, 32};
    set[37] = {"Cheesy Seafood Bake", 511, 49};
    set[38] = {"Scrambled Egg & Feta Hash", 485, 32};
    set[39] = {"Spicy Fish Stew", 664, 42};
    set[40] = {"Chicken Satay Salad", 353, 38};
    set[41] = {"Spicy Cajun Chicken Quinoa", 386, 47};
    set[42] = {"BLT Pasta Salad", 386, 18};
    set[43] = {"Halloumi, Carrot, and Orange Salad", 338, 16};
    set[44] = {"Taco Salad", 450, 25};
    set[45] = {"Vegan Chickpea Curry Jacket Potatoes", 276, 12};
    set[46] = {"Salmon Meal Prep with Veggies", 806, 54};
    set[47] = {"Pesto Grilled Cheese", 781, 34};
    set[48] = {"Peanut Chicken Wrap", 648, 33.6};
    set[49] = {"Chicken Shawarma Salad", 844, 50};

    // dinner[50-74]
    set[50] = {"Chicken and Vegetable Stir Fry", 350, 30};
    set[51] = {"Salmon and Roasted Vegetables", 400, 35};
    set[52] = {"Spaghetti Bolognese", 450, 25};
    set[53] = {"Vegetable Curry with Rice", 300, 15};
    set[54] = {"Grilled Cheese Sandwich and Tomato Soup", 500, 20};
    set[55] = {"Beef and Broccoli", 350, 30};
    set[56] = {"Greek Salad with Chicken", 400, 30};
    set[57] = {"Taco Salad", 450, 25};
    set[58] = {"Roasted Chicken and Vegetables", 500, 35};
    set[59] = {"Vegetable Lasagna", 400, 20};
    set[60] = {"Ham and Cheese Quiche", 450, 25};
    set[61] = {"Thai Chicken Noodle Soup", 350, 25};
    set[62] = {"Turkey Burger with Sweet Potato Fries", 500, 30};
    set[63] = {"Mushroom Risotto", 400, 15};
    set[64] = {"Pizza", 450, 20};
    set[65] = {"Chicken and Vegetable Soup", 250, 25};
    set[66] = {"Shrimp and Zucchini Noodles", 300, 25};
    set[67] = {"Tofu and Vegetable Stir Fry", 300, 20};
    set[68] = {"Turkey and Vegetable Wrap", 350, 25};
    set[69] = {"Chicken and Avocado Salad", 350, 30};
    set[70] = {"Egg and Vegetable Scramble", 250, 20};
    set[71] = {"Lentil and Vegetable Stew", 300, 15};
    set[72] = {"Chicken and Vegetable Skewers", 250, 25};
    set[73] = {"Vegetable Sushi", 300, 10};
    set[74] = {"Cauliflower Pizza", 250, 15};
}

class Info {
public:
    string name;
    int age;
    char sex;
    float weight;
    float height;
    string units;
    string mass;

    Info(string n, int a, char s, float w, float h, string u, string m)
        : name(n), age(a), sex(s), weight(w), height(h), units(u), mass(m) {}
};

void loadingAnimation() {
    int counter = 0;
    string animation = "|/-\\";

    while (counter < 10) {
        cout << "Generating meals.. " << animation[counter % animation.length()] << " ";
        cout.flush();

        this_thread::sleep_for(chrono::milliseconds(200));

        cout << "\r";  // Move the cursor back to the beginning of the line
        counter++;
    }

    cout << "Loading complete!" << endl;
}

void sevenDayMealLoss(Meal* foods, int gainweight, int i, int n, int days){
    predefmeals();
    srand(time(0)); // Seed the random number generator with the current time

    queue<string> recommendedMeals; // Queue to store the recommended meals

    switch (n) {
        case 1: {
            int i = 0;
        while (recommendedMeals.size() < 7) {
            int totalCalorie = 0;
            string meal; // Declare the meal variable

            // Generate random indices for breakfast, lunch, and dinner
            int breakfastIndex = rand() % 20;
            int lunchIndex = rand() % 20 + 25;
            int dinnerIndex = rand() % 20 + 50;

            // Retrieve the randomly selected meals
            meals breakfast = set[breakfastIndex];
            meals lunch = set[lunchIndex];
            meals dinner = set[dinnerIndex];

            // Calculate the total calorie count
            totalCalorie = breakfast.calr + lunch.calr + dinner.calr;

            meal += "Day " + to_string(recommendedMeals.size() + 1) + "\n";
            meal += "Breakfast: " + breakfast.name + "\n";
            meal += "Lunch: " + lunch.name + "\n";
            meal += "Dinner: " + dinner.name + "\n";
            meal += "Total Calorie = " + to_string(totalCalorie) + "\n";
            foods[i].umagahan = breakfast.name;
            foods[i].tanghalian = lunch.name;
            foods[i].hapunan = dinner.name;
            recommendedMeals.push(meal);
            i++;
        }

        // Print the recommended meals from the queue
        int day = 1;
        while (!recommendedMeals.empty()) {
            cout << recommendedMeals.front() << endl;
            recommendedMeals.pop();
            day++;
        }
        }
            break;
        case 2: {
            while (recommendedMeals.size() < days) {
                int totalCalorie = 0;

                // Generate random indices for breakfast, lunch, and dinner
                int breakfastIndex = rand() % 20;
                int lunchIndex = rand() % 20 + 25;
                int dinnerIndex = rand() % 20 + 50;

                // Retrieve the randomly selected meals
                meals breakfast = set[breakfastIndex];
                meals lunch = set[lunchIndex];
                meals dinner = set[dinnerIndex];

                // Calculate the total calorie count
                totalCalorie = breakfast.calr + lunch.calr + dinner.calr;

                if (totalCalorie <= gainweight) {
                    string meal = "Day " + to_string(recommendedMeals.size() + 1) + "\n";
                    meal += "Breakfast: " + breakfast.name + "\n";
                    meal += "Lunch: " + lunch.name + "\n";
                    meal += "Dinner: " + dinner.name + "\n";
                    meal += "Total Calorie = " + to_string(totalCalorie) + "\n";
                    foods[i].umagahan = breakfast.name;
                    foods[i].tanghalian = lunch.name;
                    foods[i].hapunan = dinner.name;
                    recommendedMeals.push(meal);
                }
                i++;
            }

            // Print the recommended meals from the queue
            int day = 1;
            while (!recommendedMeals.empty()) {
                cout << recommendedMeals.front() << endl;
                recommendedMeals.pop();
                day++;
            }
            break;
        }
}
    }

void option(){
    cout << "\t[1] 7-Day Meal Plan" << endl;
    cout << "\t[2] Customize Meal Plan" << endl;
    cout << "\nYour choice: ";
}

void sevenDayMealBuff(Meal* foods, int gainweight, int i, int n, int days){
    predefmeals();
    srand(time(0)); // Seed the random number generator with current time

    queue<string> recommendedMeals; // Queue to store the recommended meals
    switch (n) {
        case 1: {
            while (recommendedMeals.size() < 7) {
                int totalProtein = 0;
                string meal; // Declare the meal variable

                // Generate random indices for breakfast, lunch, and dinner
                int breakfastIndex = rand() % 20;
                int lunchIndex = rand() % 20 + 25;
                int dinnerIndex = rand() % 20 + 50;

                // Retrieve the randomly selected meals
                meals breakfast = set[breakfastIndex];
                meals lunch = set[lunchIndex];
                meals dinner = set[dinnerIndex];

                // Calculate the total calorie count
                meal += "Breakfast: " + breakfast.name + "\n";
                totalProtein += breakfast.protn;
                if (lunch.protn <= 30) {
                    meal += "Lunch: 2 servings of " + lunch.name + "\n";
                    totalProtein += 2 * lunch.protn;
                } else {
                    meal += "Lunch: " + lunch.name + "\n";
                    totalProtein += lunch.protn;
                }

                if (dinner.protn <= 30) {
                    meal += "Dinner: 2 servings of " + dinner.name + "\n";
                    totalProtein += 2 * dinner.protn;
                } else {
                    meal += "Dinner: " + dinner.name + "\n";
                    totalProtein += dinner.protn;
                }

                meal += "Total Protein = " + to_string(totalProtein) + "\n";
                foods[i].umagahan = breakfast.name;
                foods[i].tanghalian = lunch.name;
                foods[i].hapunan = dinner.name;
                recommendedMeals.push(meal);
                i++;
            }

            // Print the recommended meals from the queue
            int day = 1;
            while (!recommendedMeals.empty()) {
                cout << recommendedMeals.front() << endl;
                recommendedMeals.pop();
                day++;
        }
            break;
        }
        case 2: {

            while (recommendedMeals.size() < days) {
                int totalProtein = 0;
                string meal; // Declare the meal variable

                // Generate random indices for breakfast, lunch, and dinner
                int breakfastIndex = rand() % 20;
                int lunchIndex = rand() % 20 + 25;
                int dinnerIndex = rand() % 20 + 50;

                // Retrieve the randomly selected meals
                meals breakfast = set[breakfastIndex];
                meals lunch = set[lunchIndex];
                meals dinner = set[dinnerIndex];

                // Calculate the total calorie count
                meal += "Breakfast: " + breakfast.name + "\n";
                totalProtein += breakfast.protn;
                if (lunch.protn <= 30) {
                    meal += "Lunch: 2 servings of " + lunch.name + "\n";
                    totalProtein += 2 * lunch.protn;
                } else {
                    meal += "Lunch: " + lunch.name + "\n";
                    totalProtein += lunch.protn;
                }

                if (dinner.protn <= 30) {
                    meal += "Dinner: 2 servings of " + dinner.name + "\n";
                    totalProtein += 2 * dinner.protn;
                } else {
                    meal += "Dinner: " + dinner.name + "\n";
                    totalProtein += dinner.protn;
                }

                meal += "Total Protein = " + to_string(totalProtein) + "\n";
                foods[i].umagahan = breakfast.name;
                foods[i].tanghalian = lunch.name;
                foods[i].hapunan = dinner.name;
                recommendedMeals.push(meal);
                i++;
            }

            // Print the recommended meals from the queue
            int day = 1;
            while (!recommendedMeals.empty()) {
                cout << recommendedMeals.front() << endl;
                recommendedMeals.pop();
                day++;
        }
            break;
        }
}}

void sevenDayMealGain(Meal* foods, int gainweight, int i, int n, int days){
    predefmeals();
srand(time(0)); // Seed the random number generator with current time

queue<string> recommendedMeals; // Queue to store the recommended meals

switch (n) {
    case 1: {
        int i = 0; // Declare and initialize the 'i' variable
        while (recommendedMeals.size() < 7) {
            int totalCalorie = 0;
            string meal; // Declare the meal variable

            // Generate random indices for breakfast, lunch, and dinner
            int breakfastIndex = rand() % 20;
            int lunchIndex = rand() % 20 + 25;
            int dinnerIndex = rand() % 20 + 50;

            // Retrieve the randomly selected meals
            meals breakfast = set[breakfastIndex];
            meals lunch = set[lunchIndex];
            meals dinner = set[dinnerIndex];

            // Calculate the total calorie count
            meal += "Breakfast: " + breakfast.name + "\n";
            totalCalorie += breakfast.calr;
            if (lunch.calr <= 700 && lunch.calr >= 400) {
                meal += "Lunch: 2 servings of " + lunch.name + "\n";
                totalCalorie += 2 * lunch.calr;
            } else if (lunch.calr <= 399) {
                meal += "Lunch: 3 servings of " + lunch.name + "\n";
                totalCalorie += 3 * lunch.calr;
            } else {
                meal += "Lunch: " + lunch.name + "\n";
                totalCalorie += lunch.calr;
            }

            if (dinner.calr <= 700 && dinner.calr >= 400) {
                meal += "Dinner: 2 servings of " + dinner.name + "\n";
                totalCalorie += 2 * dinner.calr;
            } else if (dinner.calr <= 399) {
                meal += "Dinner: 3 servings of " + dinner.name + "\n";
                totalCalorie += 3 * dinner.calr;
            } else {
                meal += "Dinner: " + dinner.name + "\n";
                totalCalorie += dinner.calr;
            }

            meal += "Total Calorie = " + to_string(totalCalorie) + "\n";
            foods[i].umagahan = breakfast.name;
            foods[i].tanghalian = lunch.name;
            foods[i].hapunan = dinner.name;
            recommendedMeals.push(meal);
            i++;
        }

        // Print the recommended meals from the queue
        int day = 1;
        while (!recommendedMeals.empty()) {
            cout << recommendedMeals.front() << endl;
            recommendedMeals.pop();
            day++;
        }
        break;
    }
    case 2: {
        int day = 1;
        int i = 0; // Declare and initialize the 'i' variable
        while (recommendedMeals.size() < days) {
            int totalCalorie = 0;
            string meal; // Declare the meal variable

            // Generate random indices for breakfast, lunch, and dinner
            int breakfastIndex = rand() % 20;
            int lunchIndex = rand() % 20 + 25;
            int dinnerIndex = rand() % 20 + 50;

            // Retrieve the randomly selected meals
            meals breakfast = set[breakfastIndex];
            meals lunch = set[lunchIndex];
            meals dinner = set[dinnerIndex];

            // Calculate the total calorie count
            meal += "Day " + to_string(day) + "\n"; // Use the 'day' variable here
            meal += "Breakfast: " + breakfast.name + "\n";
            totalCalorie += breakfast.calr;
            if (lunch.calr <= 700 && lunch.calr >= 400) {
                meal += "Lunch: 2 servings of " + lunch.name + "\n";
                totalCalorie += 2 * lunch.calr;
            } else if (lunch.calr <= 399) {
                meal += "Lunch: 3 servings of " + lunch.name + "\n";
                totalCalorie += 3 * lunch.calr;
            } else {
                meal += "Lunch: " + lunch.name + "\n";
                totalCalorie += lunch.calr;
            }

            if (dinner.calr <= 700 && dinner.calr >= 400) {
                meal += "Dinner: 2 servings of " + dinner.name + "\n";
                totalCalorie += 2 * dinner.calr;
            } else if (dinner.calr <= 399) {
                meal += "Dinner: 3 servings of " + dinner.name + "\n";
                totalCalorie += 3 * dinner.calr;
            } else {
                meal += "Dinner: " + dinner.name + "\n";
                totalCalorie += dinner.calr;
            }

            meal += "Total Calorie = " + to_string(totalCalorie) + "\n";
            foods[i].umagahan = breakfast.name;
            foods[i].tanghalian = lunch.name;
            foods[i].hapunan = dinner.name;
            recommendedMeals.push(meal);
            i++;
            day++; // Increment the 'day' variable
        }

        // Print the recommended meals from the queue
        while (!recommendedMeals.empty()) {
            cout << recommendedMeals.front() << endl;
            recommendedMeals.pop();
        }
        break;
    }
}
}

void weightloss(Meal* foods, float weight, float height, int age, char sex) {
	do{
        cout << "\n\nLoading...\n";
        for (int i = 0; i <= 50; i++) {
            print_loading_bar(i);
            this_thread::sleep_for(chrono::milliseconds(60));
        }
        y++;
    }while(y == 1);
    cout << "\n\nLoading Complete.\n";
    Sleep (1000);
    print_header("Weight Loss");

    int i = 0;
    if (sex == 'M' || sex == 'm') {
        menBMR = 88 + (13 * weight) + (5 * height) - (6 * age);
        int gainweight = menBMR - 400;

        cout << "\nYour recommended calorie maintenance is " << menBMR << endl;
        cout << "If you want to gain weight slowly and steadily, you need to decrease your calorie maintenance to 300 and above." << endl;
        cout << "Therefore, your new calorie maintenance is " << gainweight << endl << endl;

        option();
        while (true)
        {
        	cin >> n;
        	if (cin.fail()||n>2||n<1)
        	{
        		cin.clear();
        		cin.ignore(100,'\n');
        		cout<<"Please enter a correct choice: ";
			}
			else
			{
				break;
			}
		}

        if (n == 2){
            cout << "How many days? : ";
                        while (true)
            {
            cin >> days;

            if (days<0||days>7)
            {
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"Please enter the exact amount of day/s [1-7]: ";
            }
            else
            {
                break;
            }
            }
        }
        cout << endl;

        loadingAnimation();

        cout << "Here is the recommended meal..." << endl;
		Sleep (3000);
		print_header("Weight Loss");
        sevenDayMealLoss(foods, gainweight, i, n, days);

    } else if (sex == 'F' || sex == 'f') {
        menBMR = 448 + (9 * weight) + (3 * height) - (4 * age);
        int gainweight = menBMR - 400;

        cout << "\nYour recommended calorie maintenance is " << menBMR << endl;
        cout << "If you want to gain weight slowly and steadily, you need to decrease your calorie maintenance to 300 and above." << endl;
        cout << "Therefore, your new calorie maintenance is " << gainweight << endl << endl;

        option();
                while (true)
        {
        	cin >> n;
        	if (cin.fail()||n>2||n<1)
        	{
        		cin.clear();
        		cin.ignore(100,'\n');
        		cout<<"Please enter a correct choice: ";
			}
			else
			{
				break;
			}
		}
        cout << endl;
        if (n == 2){
            cout << "How many days? : ";
                        while (true)
            {
            cin >> days;

            if (days<0||days>7)
            {
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"Please enter the exact amount of day/s [1-7]: ";
            }
            else
            {
                break;
            }
            }
        }

        loadingAnimation();

        cout << "Here is the recommended meal..." << endl;
        Sleep (2500);
		print_header("Weight Loss");
        sevenDayMealLoss(foods, gainweight, i, n, days);
}
}

void buffMeUp(Meal* foods, float weight, float height, int age, char sex){
	do{
        cout << "\n\nLoading...\n";
        for (int i = 0; i <= 50; i++) {
            print_loading_bar(i);
            this_thread::sleep_for(chrono::milliseconds(60));
        }
        y++;
    }while(y == 1);
    cout << "\n\nLoading Complete.\n";
    Sleep (1000);
    print_header("Gain Muscle");

    int i = 0;
     if (sex == 'M' || sex == 'm') {
        menBMR = 88 + (13 * weight) + (5 * height) - (6 * age);
        buffed = 1.5 * weight;

        cout << "\nYour recommended calorie maintenance is " << menBMR << endl;
        cout << "In order to gain muscle, you need to take around " << buffed << " protein daily."<< endl << endl;

        option();
                while (true)
        {
        	cin >> n;
        	if (cin.fail()||n>2||n<1)
        	{
        		cin.clear();
        		cin.ignore(100,'\n');
        		cout<<"Please enter a correct choice: ";
			}
			else
			{
				break;
			}
		}
        cout << endl;
        if (n == 2){
            cout << "How many days? : ";
                        while (true)
            {
            cin >> days;

            if (days<0||days>7)
            {
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"Please enter the exact amount of day/s [1-7]: ";
            }
            else
            {
                break;
            }
            }
        }

        loadingAnimation();

        cout << "Here is the recommended meal." << endl;
        Sleep (3000);
		print_header("Gain Muscle");
        sevenDayMealBuff(foods, buffed, i, n, days);

    }else if (sex == 'F' || sex == 'f') {
        menBMR = 448 + (9 * weight) + (3 * height) - (4 * age);
        int buffed = 1.5 * weight;

        cout << "\nYour recommended calorie maintenance is " << menBMR << endl;
        cout << "In order to gain muscle, you need to take around " << buffed << " daily."<< endl << endl;

        option();
                while (true)
        {
        	cin >> n;
        	if (cin.fail()||n>2||n<1)
        	{
        		cin.clear();
        		cin.ignore(100,'\n');
        		cout<<"Please enter a correct choice: ";
			}
			else
			{
				break;
			}
		}
        cout << endl;
        if (n == 2){
            cout << "How many days? : ";
                        while (true)
            {
            cin >> days;

            if (days<0||days>7)
            {
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"Please enter the exact amount of day/s [1-7]: ";
            }
            else
            {
                break;
            }
            }
        }

        loadingAnimation();
        Sleep (2500);
		print_header("Gain Muscle");
        cout << "Here is the recommended meal..." << endl;
        sevenDayMealBuff(foods, buffed, i, n, days);
}}

void weightgain(Meal* foods, float weight, float height, int age, char sex) {
	do{
        cout << "\n\nLoading...\n";
        for (int i = 0; i <= 50; i++) {
            print_loading_bar(i);
            this_thread::sleep_for(chrono::milliseconds(60));
        }
        y++;
    }while(y == 1);
    cout << "\n\nLoading Complete.\n";
    Sleep (1000);
    print_header("Weight Gain");

    int i = 0;
     if (sex == 'M' || sex == 'm') {
        int menBMR = 88 + (13 * weight) + (5 * height) - (6 * age);
        int gainweight = menBMR + 400;

       cout << "\nYour recommended calorie maintenance is " << menBMR << endl;
        cout << "If you want to gain weight slowly and steadily, you need to increase your calorie maintenance to 300 and above." << endl;
        cout << "Therefore, your new calorie maintenance is " << gainweight << endl << endl;

        option();
                while (true)
        {
        	cin >> n;
        	if (cin.fail()||n>2||n<1)
        	{
        		cin.clear();
        		cin.ignore(100,'\n');
        		cout<<"Please enter a correct choice: ";
			}
			else
			{
				break;
			}
		}
        cout << endl;
        if (n == 2){
            cout << "How many days? : ";
                        while (true)
            {
            cin >> days;

            if (days<0||days>7)
            {
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"Please enter the exact amount of day/s [1-7]: ";
            }
            else
            {
                break;
            }
            }
        }

        loadingAnimation();
        Sleep (2500);
		print_header("Weight Gain");
        cout << "Here is the recommended meal..." << endl;
        sevenDayMealGain(foods, gainweight, i, n, days);

    } else if (sex == 'F' || sex == 'f') {
        menBMR = 448 + (9 * weight) + (3 * height) - (4 * age);
        int gainweight = menBMR + 400;

        cout << "\nYour recommended calorie maintenance is " << menBMR << endl;
        cout << "If you want to gain weight slowly and steadily, you need to increase your calorie maintenance to 300 and above." << endl;
        cout << "Therefore, your new calorie maintenance is " << gainweight << endl << endl;

        option();
                while (true)
        {
        	cin >> n;
        	if (cin.fail()||n>2||n<1)
        	{
        		cin.clear();
        		cin.ignore(100,'\n');
        		cout<<"Please enter a correct choice: ";
			}
			else
			{

				break;
			}
		}
        cout << endl;
        if (n == 2){
            cout << "How many days? : ";
                        while (true)
            {
            cin >> days;

            if (days<0||days>7)
            {
                cin.clear();
                cin.ignore(100,'\n');
                cout<<"Please enter the exact amount of day/s [1-7]: ";
            }
            else
            {
                break;
            }
            }
        }

        loadingAnimation();
        Sleep (2500);
		print_header("Weight Gain");
        cout << "Here is the recommended meal..." << endl;
        sevenDayMealGain(foods, gainweight, i, n, days);
    }
}

void underweight() {
    cout << "You are underweight." << endl;
    int x;
    srand(time(NULL));
    x = rand() % 5;
    cout << "Random Fact: ";
    if (x == 0)
        cout << "Being underweight may be a symptom of other conditions like cancer, tuberculosis, and hyperthyroidism." << endl;
    else if (x == 1)
        cout << "Being underweight weakens the immune system, and for females, it causes issues with their menstruation and pregnancies, as well as increases the risk of infertility." << endl;
    else if (x == 2)
        cout << "8.8% of men and 9.7% women in the world are underweight." << endl;
    else if (x == 3)
        cout << "Being underweight can be influenced by stress, anxiety, depression, and/or eating disorders." << endl;
    else if (x == 4)
        cout << "A main cause of being underweight is malnutrition." << endl;
}

void normalweight() {
    int x;
    srand(time(NULL));
    x = rand() % 4;
    cout << "You are normal weight." << endl;
    cout << "\nRandom Fact: ";
    if (x == 0) {
        cout << "Maintaining a healthy weight can lower the risk of heart disease, stroke, diabetes, high blood pressure, and many different types of cancers." << endl;
    } else if (x == 1) {
        cout << "Having a normal/healthy body weight more efficiently circulates your blood." << endl;
    } else if (x == 2) {
        cout << "Your fluid levels are more easily managed." << endl;
    } else if (x == 3) {
        cout << "You are less likely to develop diabetes, heart disease, certain cancers, gallstones, osteoarthritis, breathing problems, and sleep apnea." << endl;
    }
}

void overweight() {
    int x;
    srand(time(NULL));
    x = rand() % 3;
    cout << "You are overweight." << endl;
    cout << "Random Fact: ";
    if (x == 0)
        cout << "More than 1 in 3 adults are considered to be overweight." << endl;
    else if (x == 1)
        cout << "Men are more likely than women to be overweight." << endl;
    else if (x == 2)
        cout << "More than 2 in 3 adults are considered to be overweight or have obesity." << endl;
}

void obese() {
    int x;
    srand(time(NULL));
    x = rand() % 4;
    cout << "You are obese." << endl;
    cout << "\nRandom Fact: ";
    if (x == 0) {
        cout << "Obesity-related conditions include heart disease, stroke, type 2 diabetes, and certain types of cancer. These are among the leading causes of preventable, premature death." << endl;
    } else if (x == 1) {
        cout << "Worldwide obesity has nearly tripled since 1975." << endl;
    } else if (x == 2) {
        cout << "Obesity is preventable." << endl;
    } else if (x == 3) {
        cout << "39 million children under the age of 5 were overweight or obese in 2020." << endl;
    }
}

void bmi(float h, float w, string units) {
    float newHeight = h;

    if (units == "cm") {
        newHeight = h / 100;
    }

    result = w / (newHeight * newHeight);
    cout << "\nYour BMI is: " << result << endl;

    if (result < 18.5) {
        bmiResult = "underweight";
        recommendation = "gaining weight or bulking";
        underweight();
    } else if (result >= 18.5 && result <= 24.9) {
        bmiResult = "normal";
        recommendation = "bulking";
        normalweight();
    } else if (result >= 25 && result <= 30) {
        bmiResult = "overweight";
        recommendation = "losing weight";
        overweight();
    } else {
        cout << "Facts about obese" << endl;
        bmiResult = "obese";
        recommendation = "losing weight";
        obese();
    }
}

void print_logo(){
    SetConsoleTextAttribute(h, 11);
    char const *text =
    "\t\tGETFITEATRIGHTLETSGETFITANDEATRIGHTGETFITEATRIGHTLETSGETFITANDEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGETFITANDEATRIGHTGETFITEATRIGHTLETSGETFITANDEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGET          IGHTGET         HTLETSGETF         IGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGE  ITANDEATRIGHTGETFITEA  IG  LETSGET  T  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGE  ITANDEATRIGHTGETFITEA  IGH  ETSGE  IT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGE  ITANDEATRIGHTGETFITEA  IGHT  TSG  FIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGE  ITANDEATRIGHTGETFITEA  IGHTL  S  TFIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGE  ITANDEATRIGHTGETFITEA  IGHTLE  GETFIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGET          IGHTGETFITEA  IGHTLETSGETFIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGETFITANDEATR  HTGETFITEA  IGHTLETSGETFIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGETFITANDEATR  HTGETFITEA  IGHTLETSGETFIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGETFITANDEATR  HTGETFITEA  IGHTLETSGETFIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGETFITANDEATR  HTGETFITEA  IGHTLETSGETFIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGETFITANDEATR  HT      EA  IGHTLETSGETFIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGET          IGHT      EA  IGHTLETSGETFIT  DEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGETFITANDEATRIGHTGETFITEATRIGHTLETSGETFITANDEATRIGHTGETFITEATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLE      IT  DEATRIGHT  TFIT   RIGH  ET   TFIT  DE      TG      ATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLE  GET IT  DEATRIG  GE  IT  T  GH  ET  E  IT  DE  RIGHTG  FIT  TRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLE      IT  DEATRIG      IT  TR  H  ET  ET  T  DE      TG      ATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLE  GETFIT  DEATRIG  GE  IT  TRI    ET  ETF    DE  RIGHTG  FI  ATRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLE  GETFIT       IG  GE  IT  TRIG   ET  ETFI   DE      TG  FIT  TRIGHTLETS\n"
    "\t\tGETFITEATRIGHTLETSGETFITANDEATRIGHTGETFITEATRIGHTLETSGETFITANDEATRIGHTGETFITEATRIGHTLETS\n\n";                             ;
    cout<<text;

}

void userInfo(Meal* foods, string name, int age, float weight, float height,string units, char sex){
    system("cls");
    const char *welcome =
    "\t\t\t\t\t|SM PLANNER: Your Smart Meal Planner|\n"
    "--------------------------------------------------|USER INFORMATION|----------------------------------------------------\n";
    cout<<welcome;
    cout<<"\nName: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Sex: "<<sex<<endl;
    cout<<"Height: "<<height << " " << units<<endl;
    cout<<"Weight: "<<weight<<"kg"<<endl;
    cout<<"BMI: "<<bmiResult<<endl;
    cout << "\nYour recommended calorie maintenance is " << menBMR << endl;
    cout << "In order to gain muscle, you need to take around " << buffed << " protein daily to gain muscles."<< endl << endl;
    cout<<"\nWeek Meal Plan: " << endl;
if (n == 1) {

    for (int i = 0; i < 7; i++) {
        cout << "Day "<<i + 1 <<":"<<endl;
        cout << "Breakfast: " << foods[i].umagahan << endl;
        cout << "Lunch: " << foods[i].tanghalian << endl;
        cout << "Dinner: " << foods[i].hapunan << endl;
        cout << endl;
    }
}  else if (n == 2) {
    if (days > 0) {
        for (int i = 0; i < days; i++) {
            cout << "Day " << i + 1 << ":" << endl;
            cout << "Breakfast: " << foods[i].umagahan << endl;
            cout << "Lunch: " << foods[i].tanghalian << endl;
            cout << "Dinner: " << foods[i].hapunan << endl;
            cout << endl;
        }
    } else {
        cout << "Please generate a meal first." << endl;
    }
} else {
    cout << "Please generate a meal first." << endl;
}
    cout<<"------------------------------------------------------------------------------------------------------------------------\n";
}

int main() {

    int choice, userChoice;
    string searchMeal;
    string name, units;
    int age;
    char sex, choice2, goBack[50];
    float weight, height;
    bool isTrue = true;
    Meal foods[7];

    print_logo();
    cout << "\nLoading...\n";
    for (int i = 0; i <= 50; i++) {
        print_loading_bar(i);
        this_thread::sleep_for(chrono::milliseconds(70));

    }
    cout<<"\nLoading Complete"<<endl;
    system("pause");

    SetConsoleTextAttribute(h, 15);
    print_header("Smart Meal Planner");
    cout<<"\nWelcome to S.M Planner: Your Smart Meal Planner!"<<endl;
    Sleep (1000);
    cout<<"Enter your credentials to create a profile..."<<endl<<endl;
    Sleep (1500);
    cout << "Enter your Name: ";
    getline(cin,name);
    cout << "Enter your age: ";
    while(true){
        cin>>age;
        if(cin.fail()){
            cout<<"Please enter your real age: ";
            cin.clear();
            cin.ignore(100,'\n');
        }else{
            break;
        }
    }

    do{
        cout << "Enter your sex [M/F]: ";
        cin>>sex;
        cin.ignore(100,'\n');
    }while (sex!='M'&&sex!='m'&&sex!='f'&&sex!='F');

    cout << "Enter your Height in terms of cm or m: ";
    while (true){
        cin >> height;
        if(cin.fail()){
            cout<<"Please enter your Height in terms of cm or m: ";
            cin.clear();
            cin.ignore(100,'\n');
        }else{
            break;
        }
    }
do {
    cout << "Enter the unit of height [cm/m]: ";
    cin >> units;
}while (units!="cm"&&units!="m");
    cout << "Enter your Weight in KG: ";
    while(true){
        cin >> weight;
        if (cin.fail()){
            cout<<"Please enter your weight in KG: ";
            cin.clear();
            cin.ignore(100,'\n');
        }else{
            break;
        }
    }

    do{
        cout << "\n\nLoading...\n";
        for (int i = 0; i <= 50; i++) {
            print_loading_bar(i);
            this_thread::sleep_for(chrono::milliseconds(60));
        }
        y++;
    }while(y == 1);
    cout << "\n\nLoading Complete.\n";
    Sleep (1000);

    Info user(name, age, sex, weight, height, units, "");
    menBMR = 88 + (13 * weight) + (5 * height) - (6 * age);
    buffed = 1.5 * weight;
    while(isTrue){
        system("cls");
        print_header("Smart Meal Planner");
        bmi(user.height, user.weight, user.units);
        cout << "\nYour recommended calorie maintenance is " << menBMR << endl;
        cout << "In order to gain muscle, you need to take around " << buffed << " protein daily to gain muscles."<< endl << endl;
        cout << "\n==============================================================="<< endl;
        cout << "\n\t[1] Generate Meal Plan" << endl;
        cout << "\t[2] Search Meal" << endl;
        cout << "\t[3] View Profile" << endl;
        cout << "\t[4] Exit" << endl;
        cout << "\nYour Choice: ";
        while(true){
            cin>>userChoice;
            if(cin.fail()){
                cout<<"Please enter a correct choice: ";
                cin.clear();
                cin.ignore(100,'\n');
            }else{
                break;
            }
        }

         predefmeals();

        switch(userChoice){
            case 1:
                do {
                    system("cls");
                    print_header("Smart Meal Planner");
                    cout << "You are " << bmiResult << ". We recommend " << recommendation << endl;
                    cout << "\t[1] Weight Loss" << endl;
                    cout << "\t[2] Gain Muscles" << endl;
                    cout << "\t[3] Gain Weight" << endl;
                    cout << "\nYour Choice: ";
                    while(true){
                        cin>>choice;
                        if(cin.fail()){
                            cout<<"Please enter a correct choice: ";
                            cin.clear();
                            cin.ignore(100,'\n');
                        }else{
                            break;
                        }
                    }
                    switch (choice) {
                        case 1:
                            weightloss(foods, user.weight, user.height, user.age, user.sex);
                            break;
                        case 2:
                            buffMeUp(foods, user.weight, user.height, user.age, user.sex);
                            break;
                        case 3:
                            weightgain(foods, user.weight, user.height, user.age, user.sex);
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            continue;  // Go back to the beginning of the loop
                    }

                    cout << "\n\tDo you want to generate meals again? [Y/N]: ";
                    cin >> choice2;
                    if (choice2 == 'N' || choice2 == 'n') {
                        break;  // Exit the loop
                    }
                } while (choice2 == 'Y' || choice2 == 'y');
                break;
            case 2:
                do {
                    LinkedList myList;
                    // Call mealList(myList) function to populate the linked list with meals
                    mealList(myList);

                    system("cls");
                    Sleep (2000);
                    int maxBreakfastWidth = 0;
                    int maxLunchWidth = 0;
                    int maxDinnerWidth = 0;

                    for (int i = 0; i < 25; i++) {
                        maxBreakfastWidth = max(maxBreakfastWidth, static_cast<int>(set[i].name.length()));
                        maxLunchWidth = max(maxLunchWidth, static_cast<int>(set[i + 25].name.length()));
                        maxDinnerWidth = max(maxDinnerWidth, static_cast<int>(set[i + 50].name.length()));
                    }

                    // Display breakfast, lunch, and dinner in aligned columns
                    cout << "Breakfast" << string(maxBreakfastWidth - 8, ' ') << "\tLunch" << string(maxLunchWidth - 5, ' ') << "\t\tDinner\n";
                    cout << "----------------------------------------------------------------------------------------------------------------------------\n";

                    for (int i = 0; i < 25; i++) {
                        cout << set[i].name << string(maxBreakfastWidth - set[i].name.length(), ' ');
                        cout << "\t" << set[i + 25].name << string(maxLunchWidth - set[i + 25].name.length(), ' ');
                        cout << "\t" << set[i + 50].name << '\n';
                    }

                    cout << "========================================================================" << endl;
                    cout << "Enter a meal to search: ";

                    // Clear the input stream
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    getline(cin, searchMeal);

                    Node* p = myList.search(searchMeal);
                    if (p != nullptr) {
                        cout << "Found meal: " << p->name << endl << endl;
                        ifstream file(p->data);
                        if (file.is_open()) {
                            string line;
                            while (getline(file, line)) {
                                cout << line << endl;
                            }
                            file.close();
                        } else {
                            cout << "Unable to open file: " << p->name << endl;
                        }
                    } else {
                        cout << "Meal not found." << endl;
                    }

                    cout << "\n\tDo you want to search recipe again? [Y/N]: ";
                    cin >> choice2;
                    if(choice2 == 'N' || choice2 == 'n'){
                        continue;
                    }
                } while (choice2 == 'Y' || choice2 == 'y');
                break;
            case 3:
                userInfo(foods, name, age, weight, height, units, sex);
                cout << "\n\tReturn [Y]: ";
                cin >> goBack;
                system("cls");
                break;
            case 4:
                exit(0);
                break;
        }
    }

    return 0;
}
