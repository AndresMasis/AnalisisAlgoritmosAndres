//
// Created by andre on 10/10/2021.
//

#include "my_header.h"

vector<vector<Activity>> voracious_activities(vector<Activity> list_activities, short amount_rooms) {

    vector<vector<Activity>> rooms;

    vector<Activity> current_room;

    for (short i = 0; i < amount_rooms; i++) {
        Activity last_activity = list_activities[0];
        current_room.push_back(last_activity);
        list_activities.erase(list_activities.begin());

        for (short current_position = 0; current_position < list_activities.size(); current_position++) {
            Activity current_activity = list_activities[current_position];
            if (current_activity.start > last_activity.finish) {
                current_room.push_back(current_activity);
                list_activities.erase(list_activities.begin() + current_position);
                current_position--;
                last_activity = current_activity;
            }
        }
        rooms.push_back(current_room);
        if (list_activities.empty()) {
            return rooms;
        }
        current_room.clear();
    }

    return rooms;
}
