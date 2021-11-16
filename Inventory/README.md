# Lab 5b
## CS 211
## Date 11/16/2021

Do a program that will used the sorted linked list from chapter 12.

Create a class called Inventory that will have the following UML:

Inventory

-quantity:integer

-pricePer:double

-productName:string

+Inventory(q:integer, pp: double, pn: string)

+value():double

Overloaded operator to print the object, formatted

Overloaded operator of ==

Overloaded operator of >

Overloaded operator of !=

 

You can add more functions to it if you wish.

Have the program create a sorted linked list of Inventory, ask for a file, open and read in an inventory to put into the sorted linked list then print a report. For example, with data file inventory.txt that has:

5 1.95 Widgets, small

11 2.99 Widgets, big

6 9.99 Gidgets

 

The output would be:

Mustang Sally’s electronics store

 

Product

Cost per

Quantity

Value on hand

Gidgets

$9.99

6

$  59.94

Widgets, big

$2.99

11

$  32.89

Widgets, small

$1.95

5

$    9.75

Total value =

 

 

$102.58

 

Note: must use the sorted linked list as is – only overload operators in Inventory objects to allow them to be ordered. And order by the product name.
