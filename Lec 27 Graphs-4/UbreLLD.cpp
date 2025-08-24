// Overview

// You have a bounded 2D grid with rows × cols blocks. Each block (r,c) can host multiple restaurants, each of which can be open or closed. Initially, every block has zero restaurants (i.e., no open restaurants anywhere). 

// Ultimately, you want to design a data structure with the following operations:
// 1. openRestaurant(r, c)
// Adds a new open restaurant to block (r, c).
// If the block already had open restaurants, simply increments the count.

// 2. countOpenRestaurants(r, c)
// Returns how many restaurants on block (r, c) are currently open.
// Returns 0 if there are no open restaurants at (r, c).

// 3. hasOpenRestaurant(r, c)
// Returns true if there’s at least one open restaurant on (r, c), else false.

// 4. countDeliveryZones()
// Returns the number of distinct delivery zones in the city.
// A “delivery zone” is defined as a maximal group of connected blocks (connected via up/down/left/right) that each have at least one open restaurant.

// Bonus Follow up -> can we also return the list of all restaurants in the delivery zone?