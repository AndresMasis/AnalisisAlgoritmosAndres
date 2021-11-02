#include "my_header.h"

int main() {

    vector<Activity> list_activities;
    list_activities.push_back(Activity("Baile", 1, 2));
    list_activities.push_back(Activity("Canto", 0, 3));
    list_activities.push_back(Activity("Juegos", 2, 3));
    list_activities.push_back(Activity("Comida", 3, 4));
    list_activities.push_back(Activity("Partido", 1, 5));
    list_activities.push_back(Activity("Charla", 4, 6));
    list_activities.push_back(Activity("Taller", 5, 7));
    list_activities.push_back(Activity("Pelicula", 5, 7));
    list_activities.push_back(Activity("Exposiciones", 4, 8));
    list_activities.push_back(Activity("Examen", 6, 9));

    vector<vector<Activity>> x = voracious_activities(list_activities, 4);
    return 0;
}
