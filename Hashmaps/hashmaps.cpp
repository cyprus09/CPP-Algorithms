#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string, int> ourmap;

    //insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);

    //insert method-2
    ourmap["def"] = 2;

    //find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;

    //will give error
    cout << ourmap.at("ghi") << endl;

    //size function
    cout << "size: " << ourmap.size() << endl;

    //check presence
    if(ourmap.count("ghi") > 0) {
        cout << "ghi is present" << endl;
    }

    //erase a key
    ourmap.erase("ghi");
    
}
