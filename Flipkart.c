#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    float price;
    int quantity;
};

struct cart {
    struct product products[100];
    int count;
    float total;
};

void addToCart(struct cart *c, struct product p) {
    c->products[c->count] = p;
    c->count++;
    c->total += p.price;
}

void removeFromCart(struct cart *c, int index) {
    if (index < c->count) {
        c->total -= c->products[index].price;
        
        for (int i = index; i < c->count-1; i++) {
            c->products[i] = c->products[i+1];
        }
        
        c->count--;
    }
}

void displayCart(struct cart *c) {
    printf("\nCart Items:\n");
    for (int i = 0; i < c->count; i++) {
        printf("Product Name: %s\n", c->products[i].name);
        printf("Price: %.2f\n", c->products[i].price);
        printf("Quantity: %d\n", c->products[i].quantity);
        printf("----------------------\n");
    }
    printf("Total: %.2f\n", c->total);
}

int main() {
    struct product products[5];
    struct cart myCart;
    myCart.count = 0;
    myCart.total = 0;
    
    strcpy(products[0].name, "Product 1");
    products[0].price = 10.99;
    products[0].quantity = 2;
    
    strcpy(products[1].name, "Product 2");
    products[1].price = 5.99;
    products[1].quantity = 1;
    
    strcpy(products[2].name, "Product 3");
    products[2].price = 15.99;
    products[2].quantity = 3;
    
    strcpy(products[3].name, "Product 4");
    products[3].price = 7.99;
    products[3].quantity = 2;
    
    strcpy(products[4].name, "Product 5");
    products[4].price = 12.99;
    products[4].quantity = 1;
    
    addToCart(&myCart, products[0]);
    addToCart(&myCart, products[2]);
    addToCart(&myCart, products[4]);
    
    displayCart(&myCart);
    
    removeFromCart(&myCart, 1);
    
    displayCart(&myCart);
    
    return 0;
}