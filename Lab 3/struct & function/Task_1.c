#include <stdio.h>

struct Parantha
{
    int quantity, unit_price;
};
struct Mineral_Water
{
    int quantity, unit_price;
};
struct vegetable
{
    int quantity, unit_price;
};

int main()
{
    struct Parantha p;
    struct Mineral_Water w;
    struct vegetable v;
    int num;

    printf(" Please Enter Parantha's Quantity: ");
    scanf("%d", &p.quantity);

    printf("Unit Price of Each Paratha: ");
    scanf("%d", &p.unit_price);

    printf("Please Enter Vegetable's Quantity: ");
    scanf("%d", &v.quantity);

    printf("Unit Price of Vegetables: ");
    scanf("%d", &v.unit_price);

    printf("Enter the Quantity of Water: ");
    scanf("%d", &w.quantity);

    printf("Unit Price of Water: ");
    scanf("%d", &w.unit_price);

    printf("How many people are there?: ");
    scanf("%d", &num);

    float ans = (p.quantity * p.unit_price + v.quantity * v.unit_price + w.quantity * w.unit_price) / (float)num;
    printf("Individual people will pay: %0.2f", ans);

    return 0;
}