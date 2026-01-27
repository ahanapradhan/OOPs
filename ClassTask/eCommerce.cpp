#include <iostream>
#include <vector>
using namespace std;

int uniq = 0; // global var to create uniq ID

class Product { // products are entities that can be added to vendor catalog, added to cart for check out etc.
    int id;
    double tax;
    double discount;
    double finalPrice;
    double base_price;
    string name;
public:
    Product(const string& name, double base_price, double tax, double discount) {
        id = uniq++;
        this->name = name;
        this->tax = tax;
        this->discount = discount;
        this->finalPrice = base_price - base_price * (discount/100) + (base_price * tax/100);
    }
    void view() const{
        cout << name << " " << id << " " << finalPrice << endl;
    }
    int getId() const {
        return id;
    }
    double getFinalPrice() const {
        return finalPrice;
    }
    string getName() const{ return this->name;}
};

/*
 * Create the constructors properly, by calling the constructor of the base class
 */

class BabyProduct : public Product {
    public:
    // constructor, params: name, base price, 5% discount, 5% tax
};

class Clothing : public Product {
public:
    // constructor, params: name, base price, 0% discount, 18% tax
};

class Electronics : public Product {
public:
    // constructor, params: name, base price, 12% discount, 18% tax
};

class Grocery : public Product {
public:
    // constructor, params: name, base price, 0% discount, 0% tax
};

class CartItem {
    const Product& product;
    /* One product becomes cartitem when it is added to cart.
    So, cart item class holds one reference to a product object --> any change happens to the product, gets reflected to the cartitem
    */
    
    int count; // how many of such products correspond to this cart item, e.g. 1 sunslik, 2 jimjam etc
    double totalPrice; // price of the product * count
    public:
    CartItem(const Product &prod): product(prod), count(1), totalPrice(prod.getFinalPrice()) {
        /* nothing to be done here. Make sure you understand this constructor. */
    }
    void view() const {
        cout << count << " " << product.getName() << " " << product.getId() << " " << totalPrice << endl;
    }
    int getId() const {
        // return the product ID
    }
    CartItem& add() {
        /*
         * increase product count by one.
         * update the totalprice accordingly.
         * return the same cart item object. (hint: use this pointer)
         */
    }
    double getTotalPrice() const {
        // return total price
    }
};
class Cart {
    vector<CartItem> items; // vector to hold all the cart items
    
    bool exists(const Product& p) {
        for (auto& item : items) {
            // go through the items, return true if found
        }
        // return false if reaches here, meaning, could not find it
    }
    CartItem& find(const Product& p) {
        // find and return the Cart Item reference corresponding to the product p. Use loop.
    }
    public:
    /*
     * constructor and destructors are not defined, hence, the defaults are applied.
     */
    Cart& add(const Product& p) {
        /*
         * Make sure you understand the following logic.
         * Should be able to understand and explain what is happening and why.
         */
        if (exists(p)) {
            CartItem& pref = find(p);
            pref.add();
        }
        else {
            CartItem c(p);
            items.push_back(c);
        }
        return *this;
    }
    void view() const {
        for (auto& item : items) {
            item.view();
        }
    }
    double checkout() {
        /*
         * calculate the total of total prices of all the cart items and return the overall total
         */
    }
};

class Catalog {
    vector<const Product*> products; // catalog also maintains a list of products, added by the vendors

public:
    Catalog& add(const Product& p) {
        // add p to the vector (make sure of type conversion from & to *), return this pointer to match the type
    }
    ~Catalog() {
        for (auto& item : products) {
            delete item;
        }
    }
    bool exists(int id) {
        // return true if the vector products has a product with id. Else, return false
    }
    void view() const {
        for (auto& item : products) {
            item->view();
        }
    }
    const Product& find(int id) const {
        // return the product matching with id by ref. 
    }
};

const vector<string> productnames = {"babyproduct", "electronic", "grocery", "clothing"};

bool isValid(string type) {
    // check whether the type is listed within the above "productnames". Return true or false accordingly.
}
int main() {

    Catalog cat;
    Cart cart;

    while (true) {
        string cmd;
        string name;
        string type;
        double price;
        int id, quantity;
        cin >> cmd;
        if (cmd == "catalog") {
            cat.view();
        }
        else if (cmd == "cart") {
            cart.view();
        }
        else if (cmd == "add") {
            cin >> type >> name >> price;
            if ( isValid(type) ) {
                if (type == "babyproduct") {
                     BabyProduct* b = new BabyProduct(name, price);
                     cat.add(*b);
                }
                else if (type == "electronic") {
                    Electronics *e = new Electronics(name, price);
                    cat.add(*e);
                }
                else if (type == "grocery") {
                    Grocery *g = new Grocery(name, price);
                    cat.add(*g);
                }
                else if (type == "clothing") {
                    Clothing *c = new Clothing(name, price);
                    cat.add(*c);
                }
                else {

                }
            }
            else {
                cout << "Invalid Command" << endl;
            }
        }
        else if (cmd == "order") {
            cin >> id >> quantity;
            if (cat.exists(id)) {
                const Product& p = cat.find(id);
                for (int i = 0; i < quantity; i++) {cart.add(p);}
            }
        }
        else if (cmd == "checkout") {
            cout << cart.checkout() << endl;
        }
        else if (cmd == "exit") {
            return 0;
        }
        else {

        }
    }
}
