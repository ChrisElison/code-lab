/*
 * Java HashMap Test
 * 
 * An example of using HashMaps in Java, they're basically asssociate arrays
 * or dictionaries in Python terms
 * 
 * Author: Christopher Elison <chriselison.uk>
 * Date created: 2026-05-14 19:28
 * Date modified: 2026-05-14 19:28
 * 
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

import java.util.HashMap;

public class HashMapTest {
    public static void main(String[] args) {
        // Declare HashMap to hold player inventory, string item ID and integer for item count
        HashMap<String, Integer> playerInventory = new HashMap<String, Integer>();
        
        // Add items to player inventory
        playerInventory.put("ammo_arrow", 12);
        playerInventory.put("currency_gold", 525);
        playerInventory.put("food_apple", 6);
        playerInventory.put("food_bread", 3);
        playerInventory.put("potion_health", 2);
        playerInventory.put("potion_mana", 4);
        
        // Output playerInventory HashMap
        System.out.println(playerInventory);
        
        // Get player gold count
        System.out.println("Gold: " + playerInventory.get("currency_gold"));
        
        // Get number of keys
        System.out.println("Keys: " + playerInventory.size() + "\n");
        
        // Show list of keys/items in inventory
        System.out.println("Items:");
        for (String i : playerInventory.keySet()) {
            System.out.println(i);
        }
        
        System.out.println();
        
        // Show list of items and counts
        for (String i : playerInventory.keySet()) {
            System.out.println("Item: " + i + " Count: " + playerInventory.get(i));
        }
    }
}