//
// Created by andre on 10/10/2021.
//

#include "my_header.h"

// Assumes that the activities are already sorted by their ending times
vector<vector<Activity>> voracious_activities(vector<Activity> list_activities, short amount_rooms) {

    vector<vector<Activity>> rooms; // Will hold the final returnable solution with the info of all the rooms
    vector<Activity> current_room; // A single rooms

    // This for moves between rooms, first fills room1, then room2 and so on
    for (short i = 0; i < amount_rooms; i++) {
        Activity last_activity = list_activities[0]; // The activities are sorted, consequently the first element is the one that finishes earlier
        current_room.push_back(last_activity);
        list_activities.erase(list_activities.begin());  // Activity already took into account can be deleted

        // Moves on the list_activities input, goes activity by activity
        for (short current_position = 0; current_position < list_activities.size(); current_position++) {
            Activity current_activity = list_activities[current_position];

            // Checks if we can fit the current activity, if it start when the rooms is not occupied anymore
            if (current_activity.start > last_activity.finish) {
                // The current activity fit, because the activities are sorted, for sure this is the one that fits that ends earlier
                current_room.push_back(current_activity);
                list_activities.erase(list_activities.begin() + current_position);
                current_position--;
                last_activity = current_activity;
            }
        }

        // The room was already filled with as many activities were possible to fit
        rooms.push_back(current_room);  // Adds this filled room to the final solution

        // Ask if we already scheduled all the activities
        if (list_activities.empty()) {
            // We can stop the algorithm now, everything we needed to schedule is done
            return rooms;
        }
        current_room.clear();  // Cleans for the next iteration
    }

    return rooms;
}
