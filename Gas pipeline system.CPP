#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Structure to represent the AreaDetails with distance and cost
struct AreaDetails {
    string area_name;
    int distance; // distance from selected area (in meters)
    int cost;     // cost in Rs
};

// Structure to represent the Sub-division gas pipeline Office
struct Sub_division_gas_pipeline_office {
    vector<AreaDetails> areas;  // List of areas in the sub-division
};

// Function to implement the functionality of displaying areas based on the selected zone
void displayAreas(const string& selected_zone, const unordered_map<string, vector<string>>& zone_areas) {
    cout << selected_zone << " contains the following areas:\n";
    const vector<string>& areas = zone_areas.at(selected_zone);  // Get areas for selected zone
    for (size_t i = 0; i < areas.size(); ++i) {
        cout << i + 1 << ". " << areas[i] << endl;  // Display area number and name
    }
}

// Function to display the sub-division office and area details based on the selected area
void displaySubDivisionDetails(const string& selected_area, const unordered_map<string, Sub_division_gas_pipeline_office>& area_details) {
    auto it = area_details.find(selected_area);  // Find the selected area in the area details map
    if (it != area_details.end()) {
        // Correctly displaying the area name dynamically
        cout << "gas pipeline office " << selected_area << ":\n";
        for (size_t i = 0; i < it->second.areas.size(); ++i) {
            const AreaDetails& area = it->second.areas[i];
            cout << i + 1 << ". " << area.area_name << " - " << area.distance << " meters, cost - " << area.cost << " rs\n";
        }
    } else {
        cout << "Area not found in this sub-division.\n";
    }
}

// Function to find the area with the shortest distance
string findShortestDistanceArea(const vector<AreaDetails>& areas) {
    // Find the area with the minimum distance
    auto min_it = min_element(areas.begin(), areas.end(), [](const AreaDetails& a, const AreaDetails& b) {
        return a.distance < b.distance;
    });
    return min_it->area_name;
}

// Function to calculate the volume of a cylindrical pipe
double calculatePipeVolume(double length, double outerDiameter, double thickness)
{
    const double PI = 3.14159265359;
    double innerDiameter = outerDiameter - 2 * thickness;
    double outerRadius = outerDiameter / 2.0;
    double innerRadius = innerDiameter / 2.0;

    double outerVolume = PI * outerRadius * outerRadius * length;
    double innerVolume = PI * innerRadius * innerRadius * length;

    return outerVolume - innerVolume; // Material volume
}
// Function to calculate the surface area of a cylindrical pipe
double calculateSurfaceArea(double length, double outerDiameter)
{
    const double PI = 3.14159265359;
    double radius = outerDiameter / 2.0;
    return 2 * PI * radius * length; // Surface area of the cylindrical surface
}

// Function to categorize pressure
string categorizePressure(double pressure)
 {
    if (pressure > 100)
    {
        return "High Pressure";
    } else if (pressure >= 40 && pressure <= 100)
    {
        return "Medium Pressure";
    } else
    {
        return "Low Pressure";
    }
}




int main()
{
    // User interface for input
    cout << "The Belagavi city gas pipeline " << endl;
    cout << "Enter the Zones (1. East zone, 2. West zone, 3. North zone, 4. South zone): ";
    int zone_choice;
    cin >> zone_choice;

    string selected_zone;
    unordered_map<int, string> zone_map =
     {
        {1, "East Zone"},
        {2, "West Zone"},
        {3, "North Zone"},
        {4, "South Zone"}
    };

    if (zone_map.find(zone_choice) == zone_map.end())
    {
        cout << "Invalid Zone" << endl;
        return 1;
    }

    selected_zone = zone_map[zone_choice];
    cout << "The selected zone is: " << selected_zone << endl;

    // Define the list of areas for each zone
    unordered_map<string, vector<string>> zone_areas =
    {
        {"East Zone", {"Shaniwar Khoot",
                       "Khanjar Galli",
                       "Green Taj",
                       "Khanjar Galli Cross",
                       "Khanjar Galli Urdu School",
                       "Darbar Galli Cross",
                       "Bagwan Galli Cross",
                       "Kotwal Galli Double Road",
                       "Kakar Galli",
                       "Khade Bazar",
                       "Tenginkeri Galli Junction",
                       "Govt. Hospital",
                       "Mesni Galli",
                       "Kaktives",
                       "Chandu Galli",
                       "Ghee Galli - Jalgar Galli",
                       "Mali Galli",
                       "MBS No. 4 Azad Galli",
                       "Joshi Bazar",
                       "Joshi Bazar Road",
                       "Karnatak Chowk",
                       "Kalmath Road",
                       "Bhavye Chowk",
                       "Ananshyana Galli",
                       "Konwal Galli",
                       "Tilak Chowk",
                       "Raghvendra Math",
                       "SamsunG Showroom",
                       "Corporation Bank",
                       "Sardar High School",
                       "Court Compound",
                       "Topi Galli",
                       "Darbar Galli Cross",
                       "Chavat Galli to PB Road",
                       "Shetti Galli PB Road Cross",
                       "Kotwal Galli Double Road",
                       "Kaktives Road",
                       "Sardar High School Ground",
                       "Konwal Galli Guest House",
                       "Azad Galli", "Hospital Road",
                       "Tenginkeri Sheetal Hotel Cross",
                       "Pai Hotel",
                       "Old PB Road South Peripheral"}},
        {"West Zone", {"Raviwar Peth Main Road",
                       "Motilal Circle",
                       "Hira Talkies",
                       "Ganpat Galli upto Hira Talkies",
                       "Kirloskar Road",
                       "Bata Showroom",
                       "Ramdev Galli",
                       "Adarsh Dress Circle",
                       "SamsunG Showroom",
                       "Samadevi Galli",
                       "Gondhalli Galli",
                       "Gavli Galli",
                       "Narvekar Gali",
                       "Risaldar Galli",
                       "Khade Bazar Police Station",
                       "Shaniwar Khoot - Ganpat Galli",
                       "Hira Talkies Backside",
                       "Kalkundrikar Road",
                       "Kalkundrikar",
                       "Ganga Prabaha Hotel",
                       "Kirloskar Road",
                       "Bata Showroom"}},
        {"North Zone", {"Moksahi Galli",
                        "Bauxite Road",
                        "Bank of Maharashtra",
                        "Nayaya Marg",
                        "Vidyagiri",
                        "Basav Colony",
                        "Shivbasav Nagar",
                        "Bauxite Road",
                        "Kanakdas Circle",
                        "Shankam Hotel Cross",
                        "Gandhi Nagar",
                        "Shivterth Colony",
                        "KLE Compound",
                        "Jadhav Nagar",
                        "Shivaji Garden",
                        "Vandan Colony",
                        "Vidyagiri"}},
        {"South Zone", {"Chennamma Circle",
                        "Rayanna Circle",
                        "Keerti Hotel",
                        "Shetti Galli",
                        "Old PB Road",
                        "SamsunG Showroom",
                        "Raviwar Peth Main Road",
                        "Shani Mandir",
                        "Shivaji Nagar",
                        "Sambhaji Circle",
                        "Shivbasav Nagar",
                        "Ram Nagar",
                        "NCC Arts",
                        "Bharat Motor School",
                        "Jadhav Nagar",
                        "Sadashiv Nagar",
                        "Vengurla Road",
                        "DC Bungalow Cross",
                        "Ambedkar Road",
                        "Chennamma Circle - College Road",
                        "Vengurla Road - DC Bungalow",
                        "Rail Nagar South Cross",
                        "TB Ward - Ambedkar Road",
                        "APMC Road",
                        "Ambedkar Road",
                        "Veerbhadra Nagar"}}



};

    // Define the sub-division office and area details
    unordered_map<string, Sub_division_gas_pipeline_office> area_details = {
        {"Green Taj", {
            {{"Green Taj", 800, 3000},
            {"Khanjar Galli", 500, 2500},
            {"Shaniwar Khoot", 300, 2000},
             {"Khanjar Galli Cross", 1000, 3300},
             {"Khanjar Galli Urdu School", 900, 3200}}}
        },
        {"Shaniwar Khoot",{
         {{"Shaniwar Khoot", 300, 2000},
         {"Khanjar Galli", 500, 2500},
        {"Green Taj", 800, 3000},
        {"Khanjar Galli Cross", 1000, 3300},
        {"Khanjar Galli Urdu School", 900, 3200},
        {"Darbar Galli Cross", 1200, 3500},
        {"Bagwan Galli Cross", 300, 2000}}}
        },
        {"Khanjar Galli",{
         {{"Shaniwar Khoot", 300, 2000},
         {"Khanjar Galli", 500, 2500},
        {"Green Taj", 800, 3000},
        {"Khanjar Galli Cross", 1000, 3300},
        {"Khanjar Galli Urdu School", 900, 3200},
        {"Darbar Galli Cross", 1200, 3500},
        {"Bagwan Galli Cross", 300, 2000}}}
        },
        {"Darbar Galli Cross",{
         {{"Shaniwar Khoot", 300, 2000},
         {"Khanjar Galli", 500, 2500},
        {"Green Taj", 800, 3000},
        {"Khanjar Galli Cross", 1000, 3300},
        {"Khanjar Galli Urdu School", 900, 3200},
        {"Darbar Galli Cross", 1200, 3500},
        {"Bagwan Galli Cross", 300, 2000}}}
        },
        {"Bagwan Galli Cross",{
         {{"Shaniwar Khoot", 300, 2000},
         {"Khanjar Galli", 500, 2500},
        {"Green Taj", 800, 3000},
        {"Khanjar Galli Cross", 1000, 3300},
        {"Khanjar Galli Urdu School", 900, 3200},
        {"Darbar Galli Cross", 1200, 3500},
        {"Bagwan Galli Cross", 300, 2000}}}
        },
        {"Khanjar Galli Cross", {
            {{"Green Taj", 800, 3000},
            {"Khanjar Galli", 500, 2500},
            {"Shaniwar Khoot", 300, 2000},
             {"Khanjar Galli Cross", 1000, 3300},
             {"Khanjar Galli Urdu School", 900, 3200}}}
        },
        {"Khanjar Galli Urdu School", {
            {{"Green Taj", 800, 3000},
            {"Khanjar Galli", 500, 2500},
            {"Shaniwar Khoot", 300, 2000},
             {"Khanjar Galli Cross", 1000, 3300},
             {"Khanjar Galli Urdu School", 900, 3200}}}
        },
        {"Khade Bazar",{
        {{"Kotwal Galli Double Road", 2000, 5500},
        {"Kakar Galli", 1600, 4800},
        {"Khade Bazar", 300, 2000},
        {"Tenginkeri Galli Junction", 900, 3200},
        {"Govt. Hospital", 1000, 3300},
        {"Green Taj", 500, 2500}}}
        },
        {"Kotwal Galli Double Road",{
        {{"Kotwal Galli Double Road", 2000, 5500},
        {"Kakar Galli", 1600, 4800},
        {"Khade Bazar", 300, 2000},
        {"Tenginkeri Galli Junction", 900, 3200},
        {"Govt. Hospital", 1000, 3300},
        {"Green Taj", 500, 2500}}}
        },
        {"Kakar Galli",{
        {{"Kotwal Galli Double Road", 2000, 5500},
        {"Kakar Galli", 1600, 4800},
        {"Khade Bazar", 300, 2000},
        {"Tenginkeri Galli Junction", 900, 3200},
        {"Govt. Hospital", 1000, 3300},
        {"Green Taj", 500, 2500}}}
        },
        {"Tenginkeri Galli Junction",{
        {{"Kotwal Galli Double Road", 2000, 5500},
        {"Kakar Galli", 1600, 4800},
        {"Khade Bazar", 300, 2000},
        {"Tenginkeri Galli Junction", 900, 3200},
        {"Govt. Hospital", 1000, 3300},
        {"Green Taj", 500, 2500}}}
        },
        {"Govt. Hospital",{
        {{"Kotwal Galli Double Road", 2000, 5500},
        {"Kakar Galli", 1600, 4800},
        {"Khade Bazar", 300, 2000},
        {"Tenginkeri Galli Junction", 900, 3200},
        {"Govt. Hospital", 1000, 3300},
        {"Green Taj", 500, 2500}}}
        },
        {"Kaktives",{
        {{"Govt. Hospital", 1000, 3300},
        {"Green Taj", 500, 2500},
        {"Mesni Galli", 500, 2500},
        {"Kaktives", 1600, 4800},
        {"Chandu Galli", 2000, 5500},
        {"Khanjar Galli Cross", 800, 3000},
        {"Ghee Galli - Jalgar Galli", 2500, 6500}}
        }
        },
        {"Mesni Galli",{
        {{"Govt. Hospital", 1000, 3300},
        {"Green Taj", 500, 2500},
        {"Mesni Galli", 500, 2500},
        {"Kaktives", 1600, 4800},
        {"Chandu Galli", 2000, 5500},
        {"Khanjar Galli Cross", 800, 3000},
        {"Ghee Galli - Jalgar Galli", 2500, 6500}}
        }
        },
        {"Chandu Galli",{
        {{"Govt. Hospital", 1000, 3300},
        {"Green Taj", 500, 2500},
        {"Mesni Galli", 500, 2500},
        {"Kaktives", 1600, 4800},
        {"Chandu Galli", 2000, 5500},
        {"Khanjar Galli Cross", 800, 3000},
        {"Ghee Galli - Jalgar Galli", 2500, 6500}}
        }
        },
        {"Ghee Galli - Jalgar Galli",{
        {{"Govt. Hospital", 1000, 3300},
        {"Green Taj", 500, 2500},
        {"Mesni Galli", 500, 2500},
        {"Kaktives", 1600, 4800},
        {"Chandu Galli", 2000, 5500},
        {"Khanjar Galli Cross", 800, 3000},
        {"Ghee Galli - Jalgar Galli", 2500, 6500}}
        }
        },
        {"Topi Galli",{
        {{"Mali Galli", 500, 2500},
        {"MBS No. 4 Azad Galli", 1200, 3500},
        {"Joshi Bazar", 800, 3000},
        {"Joshi Bazar Road", 900, 3200},
        {"Karnatak Chowk", 1600, 4800},
        {"Kalmath Road", 3500, 8000},
        {"Khade Bazar", 1000, 3000},
        {"Topi Galli", 200, 1800},
        {"Ananshyana Galli", 800, 3000}}}
        },
        {"Joshi Bazar",{
        {{"Mali Galli", 500, 2500},
        {"MBS No. 4 Azad Galli", 1200, 3500},
        {"Joshi Bazar", 800, 3000},
        {"Joshi Bazar Road", 900, 3200},
        {"Karnatak Chowk", 1600, 4800},
        {"Kalmath Road", 3500, 8000},
        {"Khade Bazar", 1000, 3000},
        {"Topi Galli", 200, 1800},
        {"Ananshyana Galli", 800, 3000}}}
        },
        {"Karnatak Chowk",{
        {{"Mali Galli", 500, 2500},
        {"MBS No. 4 Azad Galli", 1200, 3500},
        {"Joshi Bazar", 800, 3000},
        {"Joshi Bazar Road", 900, 3200},
        {"Karnatak Chowk", 1600, 4800},
        {"Kalmath Road", 3500, 8000},
        {"Khade Bazar", 1000, 3000},
        {"Topi Galli", 200, 1800},
        {"Ananshyana Galli", 800, 3000}}}
        },
        {"Ananshyana Galli",{
        {{"Mali Galli", 500, 2500},
        {"MBS No. 4 Azad Galli", 1200, 3500},
        {"Joshi Bazar", 800, 3000},
        {"Joshi Bazar Road", 900, 3200},
        {"Karnatak Chowk", 1600, 4800},
        {"Kalmath Road", 3500, 8000},
        {"Khade Bazar", 1000, 3000},
        {"Topi Galli", 200, 1800},
        {"Ananshyana Galli", 800, 3000}}}
        },
        {"Kalmath Road",{
        {{"Mali Galli", 500, 2500},
        {"MBS No. 4 Azad Galli", 1200, 3500},
        {"Joshi Bazar", 800, 3000},
        {"Joshi Bazar Road", 900, 3200},
        {"Karnatak Chowk", 1600, 4800},
        {"Kalmath Road", 3500, 8000},
        {"Khade Bazar", 1000, 3000},
        {"Topi Galli", 200, 1800},
        {"Ananshyana Galli", 800, 3000}}}
        },
        {"Tilak Chowk",{
        {{"Konwal Galli", 500, 2500},
        {"Tilak Chowk", 1200, 3500},
        {"Raghvendra Math", 1600, 4800},
        {"SamsunG Showroom", 300, 2000},
        {"Corporation Bank", 3500, 8000},
        {"Sardar High School", 2000, 5500},
        {"Court Compound", 1000, 3300}}}
        },
        {"Konwal Galli",{
        {{"Konwal Galli", 500, 2500},
        {"Tilak Chowk", 1200, 3500},
        {"Raghvendra Math", 1600, 4800},
        {"SamsunG Showroom", 300, 2000},
        {"Corporation Bank", 3500, 8000},
        {"Sardar High School", 2000, 5500},
        {"Court Compound", 1000, 3300}}}
        },
        {"Raghvendra Math",{
        {{"Konwal Galli", 500, 2500},
        {"Tilak Chowk", 1200, 3500},
        {"Raghvendra Math", 1600, 4800},
        {"SamsunG Showroom", 300, 2000},
        {"Corporation Bank", 3500, 8000},
        {"Sardar High School", 2000, 5500},
        {"Court Compound", 1000, 3300}}}
        },
        {"Court Compound",{
        {{"Konwal Galli", 500, 2500},
        {"Tilak Chowk", 1200, 3500},
        {"Raghvendra Math", 1600, 4800},
        {"SamsunG Showroom", 300, 2000},
        {"Corporation Bank", 3500, 8000},
        {"Sardar High School", 2000, 5500},
        {"Court Compound", 1000, 3300}}}
        },
        {"Bhavye Chowk",{
        {{"Bhavye Chowk",200, 1800},
        {"Darbar Galli Cross",2500, 6500},
        {"SamsunG Showroom", 500, 2500},
        {"Chavat Galli to PB Road",4000, 9000},
        {"Shetti Galli PB Road Cross",3000, 8500},
        {"Kotwal Galli Double Road",2000, 5500}}}
        },
        {"Bhavye Chowk",{
        {{"Bhavye Chowk",200, 1800},
        {"Darbar Galli Cross",2500, 6500},
        {"SamsunG Showroom", 500, 2500},
        {"Chavat Galli to PB Road",4000, 9000},
        {"Shetti Galli PB Road Cross",3000, 8500},
        {"Kotwal Galli Double Road",2000, 5500}}}
        },
        {"Darbar Galli Cross",{
        {{"Bhavye Chowk",200, 1800},
        {"Darbar Galli Cross",2500, 6500},
        {"SamsunG Showroom", 500, 2500},
        {"Chavat Galli to PB Road",4000, 9000},
        {"Shetti Galli PB Road Cross",3000, 8500},
        {"Kotwal Galli Double Road",2000, 5500}}}
        },
        {"Chavat Galli to PB Road",{
        {{"Bhavye Chowk",200, 1800},
        {"Darbar Galli Cross",2500, 6500},
        {"SamsunG Showroom", 500, 2500},
        {"Chavat Galli to PB Road",4000, 9000},
        {"Shetti Galli PB Road Cross",3000, 8500},
        {"Kotwal Galli Double Road",2000, 5500}}}
        },
        {"Shetti Galli PB Road Cross",{
        {{"Bhavye Chowk",200, 1800},
        {"Darbar Galli Cross",2500, 6500},
        {"SamsunG Showroom", 500, 2500},
        {"Chavat Galli to PB Road",4000, 9000},
        {"Shetti Galli PB Road Cross",3000, 8500},
        {"Kotwal Galli Double Road",2000, 5500}}}
        },

        {"Kaktives Road", {
        {{"Kaktives Road",300, 2000},
        {"Sardar High School Ground",1200, 3500},
        {"Konwal Galli Guest House",3500, 8000},
        {"Azad Galli",2000, 5500},
        {"Hospital Road",800, 3000},
        {"Tenginkeri Sheetal Hotel Cross",1600, 3300},
        {"Pai Hotel",1000, 3300},
        {"Old PB Road South Peripheral",3000, 8500}}}
        },
        {"Old PB Road South Peripheral", {
        {{"Kaktives Road",300, 2000},
        {"Sardar High School Ground",1200, 3500},
        {"Konwal Galli Guest House",3500, 8000},
        {"Azad Galli",2000, 5500},
        {"Hospital Road",800, 3000},
        {"Tenginkeri Sheetal Hotel Cross",1600, 3300},
        {"Pai Hotel",1000, 3300},
        {"Old PB Road South Peripheral",3000, 8500}}}
        },
        {"Azad Galli", {
        {{"Kaktives Road",300, 2000},
        {"Sardar High School Ground",1200, 3500},
        {"Konwal Galli Guest House",3500, 8000},
        {"Azad Galli",2000, 5500},
        {"Hospital Road",800, 3000},
        {"Tenginkeri Sheetal Hotel Cross",1600, 3300},
        {"Pai Hotel",1000, 3300},
        {"Old PB Road South Peripheral",3000, 8500}}}
        },
        {"Pai Hotel", {
        {{"Kaktives Road",300, 2000},
        {"Sardar High School Ground",1200, 3500},
        {"Konwal Galli Guest House",3500, 8000},
        {"Azad Galli",2000, 5500},
        {"Hospital Road",800, 3000},
        {"Tenginkeri Sheetal Hotel Cross",1600, 3300},
        {"Pai Hotel",1000, 3300},
        {"Old PB Road South Peripheral",3000, 8500}}}
        },
        {"Konwal Galli Guest House", {
        {{"Kaktives Road",300, 2000},
        {"Sardar High School Ground",1200, 3500},
        {"Konwal Galli Guest House",3500, 8000},
        {"Azad Galli",2000, 5500},
        {"Hospital Road",800, 3000},
        {"Tenginkeri Sheetal Hotel Cross",1600, 3300},
        {"Pai Hotel",1000, 3300},
        {"Old PB Road South Peripheral",3000, 8500}}}
        },
        {"Hospital Road", {
        {{"Kaktives Road",300, 2000},
        {"Sardar High School Ground",1200, 3500},
        {"Konwal Galli Guest House",3500, 8000},
        {"Azad Galli",2000, 5500},
        {"Hospital Road",800, 3000},
        {"Tenginkeri Sheetal Hotel Cross",1600, 3300},
        {"Pai Hotel",1000, 3300},
        {"Old PB Road South Peripheral",3000, 8500}}}
        },
        {"Motilal Circle",{
        {{"Motilal Circle", 300, 2000},
        {"Raviwar Peth Main Road", 1200, 3500},
        {"Hira Talkies", 3500, 8000},
        {"Ganpat Galli upto Hira Talkies", 1000, 3300},
        {"Kirloskar Road", 2000, 5500},
        {"Bata Showroom", 1200, 3500}}}
        },
        {"Raviwar Peth Main Road",{
        {{"Motilal Circle", 300, 2000},
        {"Raviwar Peth Main Road", 1200, 3500},
        {"Hira Talkies", 3500, 8000},
        {"Ganpat Galli upto Hira Talkies", 1000, 3300},
        {"Kirloskar Road", 2000, 5500},
        {"Bata Showroom", 1200, 3500}}}
        },
        {"Hira Talkies",{
        {{"Motilal Circle", 300, 2000},
        {"Raviwar Peth Main Road", 1200, 3500},
        {"Hira Talkies", 3500, 8000},
        {"Ganpat Galli upto Hira Talkies", 1000, 3300},
        {"Kirloskar Road", 2000, 5500},
        {"Bata Showroom", 1200, 3500}}}
        },
        {"Kirloskar Road",{
        {{"Motilal Circle", 300, 2000},
        {"Raviwar Peth Main Road", 1200, 3500},
        {"Hira Talkies", 3500, 8000},
        {"Ganpat Galli upto Hira Talkies", 1000, 3300},
        {"Kirloskar Road", 2000, 5500},
        {"Bata Showroom", 1200, 3500}}}
        },
        {"Adarsh Dress Circle",{
        {{"Ramdev Galli", 200, 1800},
        {"Adarsh Dress Circle", 500, 2500},
        {"SamsunG Showroom", 3000, 8500},
        {"Samadevi Galli", 1000, 3300},
        {"Gondhalli Galli", 1600, 4800},
        {"Gavli Galli", 800, 3000},
        {"Narvekar Gali", 2000, 5500}}}
        },
        {"Ramdev Galli",{
        {{"Ramdev Galli", 200, 1800},
        {"Adarsh Dress Circle", 500, 2500},
        {"SamsunG Showroom", 3000, 8500},
        {"Samadevi Galli", 1000, 3300},
        {"Gondhalli Galli", 1600, 4800},
        {"Gavli Galli", 800, 3000},
        {"Narvekar Gali", 2000, 5500}}}
        },
        {"Samadevi Galli",{
        {{"Ramdev Galli", 200, 1800},
        {"Adarsh Dress Circle", 500, 2500},
        {"SamsunG Showroom", 3000, 8500},
        {"Samadevi Galli", 1000, 3300},
        {"Gondhalli Galli", 1600, 4800},
        {"Gavli Galli", 800, 3000},
        {"Narvekar Gali", 2000, 5500}}}
        },
        {"Gondhalli Galli",{
        {{"Ramdev Galli", 200, 1800},
        {"Adarsh Dress Circle", 500, 2500},
        {"SamsunG Showroom", 3000, 8500},
        {"Samadevi Galli", 1000, 3300},
        {"Gondhalli Galli", 1600, 4800},
        {"Gavli Galli", 800, 3000},
        {"Narvekar Gali", 2000, 5500}}}
        },
        {"Gavli Galli",{
        {{"Ramdev Galli", 200, 1800},
        {"Adarsh Dress Circle", 500, 2500},
        {"SamsunG Showroom", 3000, 8500},
        {"Samadevi Galli", 1000, 3300},
        {"Gondhalli Galli", 1600, 4800},
        {"Gavli Galli", 800, 3000},
        {"Narvekar Gali", 2000, 5500}}}
        },
        {"Risaldar Galli",{
        {{"Risaldar Galli", 1200, 3500},
        {"Kalkundrikar Road", 500, 2500},
        {"Ganga Prabaha Hotel", 1200, 3500},
        {"Kirloskar Road", 1600, 4800},
        {"Bata Showroom", 800, 3000},
        {"Khade Bazar Police Station", 900, 3200},
        {"Shaniwar Khoot - Ganpat Galli", 2500, 6500},
        {"Hira Talkies Backside", 3000, 8500}}}
        },
        {"Kalkundrikar Road",{
        {{"Risaldar Galli", 1200, 3500},
        {"Kalkundrikar Road", 500, 2500},
        {"Ganga Prabaha Hotel", 1200, 3500},
        {"Kirloskar Road", 1600, 4800},
        {"Bata Showroom", 800, 3000},
        {"Khade Bazar Police Station", 900, 3200},
        {"Shaniwar Khoot - Ganpat Galli", 2500, 6500},
        {"Hira Talkies Backside", 3000, 8500}}}
        },
        {"Bata Showroom",{
        {{"Risaldar Galli", 1200, 3500},
        {"Kalkundrikar Road", 500, 2500},
        {"Ganga Prabaha Hotel", 1200, 3500},
        {"Kirloskar Road", 1600, 4800},
        {"Bata Showroom", 800, 3000},
        {"Khade Bazar Police Station", 900, 3200},
        {"Shaniwar Khoot - Ganpat Galli", 2500, 6500},
        {"Hira Talkies Backside", 3000, 8500}}}
        },
        {"Ganga Prabaha Hotel",{
        {{"Risaldar Galli", 1200, 3500},
        {"Kalkundrikar Road", 500, 2500},
        {"Ganga Prabaha Hotel", 1200, 3500},
        {"Kirloskar Road", 1600, 4800},
        {"Bata Showroom", 800, 3000},
        {"Khade Bazar Police Station", 900, 3200},
        {"Shaniwar Khoot - Ganpat Galli", 2500, 6500},
        {"Hira Talkies Backside", 3000, 8500}}}
        },
        {"Shaniwar Khoot - Ganpat Galli",{
        {{"Risaldar Galli", 1200, 3500},
        {"Kalkundrikar Road", 500, 2500},
        {"Ganga Prabaha Hotel", 1200, 3500},
        {"Kirloskar Road", 1600, 4800},
        {"Bata Showroom", 800, 3000},
        {"Khade Bazar Police Station", 900, 3200},
        {"Shaniwar Khoot - Ganpat Galli", 2500, 6500},
        {"Hira Talkies Backside", 3000, 8500}}}
        },
        {"Moksahi Galli",{
        {{"Moksahi Galli", 500, 2500},
        {"Bauxite Road", 3000, 8500},
        {"Bank of Maharashtra", 900, 3200},
        {"Nayaya Marg", 500, 2500},
        {"Vidyagiri", 800, 3000},
        {"Basav Colony", 1600, 4800},
        {"Shivbasav Nagar", 1200, 3500}}}
        },
        {"Bauxite Road",{
        {{"Moksahi Galli", 500, 2500},
        {"Bauxite Road", 3000, 8500},
        {"Bank of Maharashtra", 900, 3200},
        {"Nayaya Marg", 500, 2500},
        {"Vidyagiri", 800, 3000},
        {"Basav Colony", 1600, 4800},
        {"Shivbasav Nagar", 1200, 3500}}}
        },
        {"Bank of Maharashtra",{
        {{"Bauxite Road", 3000, 8500},
        {"Bank of Maharashtra", 900, 3200},
        {"Nayaya Marg", 500, 2500},
        {"Vidyagiri", 800, 3000},
        {"Basav Colony", 1600, 4800},
        {"Shivbasav Nagar", 1200, 3500}}}
        },
        {"Nayaya Marg",{
        {{"Moksahi Galli", 500, 2500},
        {"Bauxite Road", 3000, 8500},
        {"Bank of Maharashtra", 900, 3200},
        {"Nayaya Marg", 500, 2500},
        {"Vidyagiri", 800, 3000},
        {"Basav Colony", 1600, 4800},
        {"Shivbasav Nagar", 1200, 3500}}}
        },
        {"Vidyagiri",{
        {{"Bauxite Road", 3000, 8500},
        {"Bank of Maharashtra", 900, 3200},
        {"Nayaya Marg", 500, 2500},
        {"Vidyagiri", 800, 3000},
        {"Basav Colony", 1600, 4800},
        {"Shivbasav Nagar", 1200, 3500}}}
        },
        {"Basav Colony",{
        {{"Bauxite Road", 3000, 8500},
        {"Bank of Maharashtra", 900, 3200},
        {"Nayaya Marg", 500, 2500},
        {"Vidyagiri", 800, 3000},
        {"Basav Colony", 1600, 4800},
        {"Shivbasav Nagar", 1200, 3500}}}
        },
        {"Shivbasav Nagar",{
        {{"Bauxite Road", 3000, 8500},
        {"Bank of Maharashtra", 900, 3200},
        {"Nayaya Marg", 500, 2500},
        {"Vidyagiri", 800, 3000},
        {"Basav Colony", 1600, 4800},
        {"Shivbasav Nagar", 1200, 3500}}}
        },
        {"Kanakdas Circle",{
        {{"Bauxite Road", 200, 1800},
        {"Kanakdas Circle", 900, 3200},
        {"Shankam Hotel Cross", 800, 3000},
        {"Gandhi Nagar", 500, 2500},
        {"Shivterth Colony", 1000, 3300},
        {"Kanakdas Circle", 1200, 3500},
        {"KLE Compound", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },
        {"Shankam Hotel Cross",{
        {{"Kanakdas Circle", 900, 3200},
        {"Shankam Hotel Cross", 800, 3000},
        {"Gandhi Nagar", 500, 2500},
        {"Shivterth Colony", 1000, 3300},
        {"Kanakdas Circle", 1200, 3500},
        {"KLE Compound", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },
        {"Gandhi Nagar",{
        {{"Kanakdas Circle", 900, 3200},
        {"Shankam Hotel Cross", 800, 3000},
        {"Gandhi Nagar", 500, 2500},
        {"Shivterth Colony", 1000, 3300},
        {"Kanakdas Circle", 1200, 3500},
        {"Jadhav Nagar", 1600, 4800}}}
        },
        {"Shivterth Colony",{
        {{"Bauxite Road", 200, 1800},
        {"Kanakdas Circle", 900, 3200},
        {"Shankam Hotel Cross", 800, 3000},
        {"Gandhi Nagar", 500, 2500},
        {"Shivterth Colony", 1000, 3300},
        {"Kanakdas Circle", 1200, 3500},
        {"KLE Compound", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },
        {"KLE Compound",{
        {{"Kanakdas Circle", 900, 3200},
        {"Shankam Hotel Cross", 800, 3000},
        {"Gandhi Nagar", 500, 2500},
        {"Shivterth Colony", 1000, 3300},
        {"Kanakdas Circle", 1200, 3500},
        {"KLE Compound", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },
        {"Jadhav Nagar",{
        {{"Kanakdas Circle", 900, 3200},
        {"Shankam Hotel Cross", 800, 3000},
        {"Gandhi Nagar", 500, 2500},
        {"Shivterth Colony", 1000, 3300},
        {"Kanakdas Circle", 1200, 3500},
        {"KLE Compound", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },

        {"Shivaji Garden",{
        {{"Shivaji Garden",500, 2500},
        {"Vandan Colony", 900, 3200},
        {"Vidyagiri", 1000, 3300},
        {"Bauxite Road", 800, 3000},
        {"Gandhinagar", 1200, 3500}}}
        },

        {"Vidyagiri",{
        {{"Vandan Colony", 900, 3200},
        {"Vidyagiri", 1000, 3300},
        {"Bauxite Road", 800, 3000},
        {"Gandhinagar", 1200, 3500}}}
        },

        {"Vandan Colony",{
        {{"Shivaji Garden",500, 2500},
        {"Vandan Colony", 900, 3200},
        {"Vidyagiri", 1000, 3300},
        {"Bauxite Road", 800, 3000},
        {"Gandhinagar", 1200, 3500}}}
        },

        {"Chennamma Circle",{
        {{"Chennamma Circle", 200, 1800},
        {"Rayanna Circle", 900, 3200},
        {"Keerti Hotel", 2000, 5500},
        {"Shetti Galli", 1200, 3500},
        {"Old PB Road", 3000, 8500},
        {"SamsunG Showroom", 800, 3000},
        {"Raviwar Peth Main Road", 1600, 4800}}}
        },

        {"Rayanna Circle",{
        {{"Rayanna Circle", 900, 3200},
        {"Keerti Hotel", 2000, 5500},
        {"Shetti Galli", 1200, 3500},
        {"Old PB Road", 3000, 8500},
        {"SamsunG Showroom", 800, 3000},
        {"Raviwar Peth Main Road", 1600, 4800},
        {"Shani Mandir", 500, 2500}}}
        },

        {"Keerti Hotel",{
        {{"Rayanna Circle", 900, 3200},
        {"Keerti Hotel", 2000, 5500},
        {"Shetti Galli", 1200, 3500},
        {"Old PB Road", 3000, 8500},
        {"Raviwar Peth Main Road", 1600, 4800}}}
        },

        {"Shetti Galli",{
        {{"Rayanna Circle", 900, 3200},
        {"Keerti Hotel", 2000, 5500},
        {"Shetti Galli", 1200, 3500},
        {"Old PB Road", 3000, 8500},
        {"SamsunG Showroom", 800, 3000},
        {"Raviwar Peth Main Road", 1600, 4800},
        {"Shani Mandir", 500, 2500}}}
        },

        {"Old PB Road",{
        {{"Rayanna Circle", 900, 3200},
        {"Keerti Hotel", 2000, 5500},
        {"Shetti Galli", 1200, 3500},
        {"Old PB Road", 3000, 8500},
        {"SamsunG Showroom", 800, 3000},
        {"Raviwar Peth Main Road", 1600, 4800}}}
        },

        {"SamsunG Showroom",{
        {{"Rayanna Circle", 900, 3200},
        {"Keerti Hotel", 2000, 5500},
        {"Shetti Galli", 1200, 3500},
        {"Old PB Road", 3000, 8500},
        {"SamsunG Showroom", 800, 3000},
        {"Raviwar Peth Main Road", 1600, 4800}}}
        },

        {"Raviwar Peth Main Road",{
        {{"Keerti Hotel", 2000, 5500},
        {"Shetti Galli", 1200, 3500},
        {"Old PB Road", 3000, 8500},
        {"Raviwar Peth Main Road", 1600, 4800}}}
        },

        {"Shivaji Nagar",{
        {{"Shivaji Nagar", 500, 2500},
        {"Sambhaji Circle", 900, 3200},
        {"Shivbasav Nagar", 1200, 3500},
        {"Ram Nagar", 2000, 5500},
        {"NCC Arts", 1000, 3300},
        {"Bharat Motor School", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },

        {"Sambhaji Circle",{
        {{"Shivaji Nagar", 500, 2500},
        {"Sambhaji Circle", 900, 3200},
        {"Shivbasav Nagar", 1200, 3500},
        {"Ram Nagar", 2000, 5500},
        {"NCC Arts", 1000, 3300},
        {"Bharat Motor School", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },

        {"Shivbasav Nagar",{
        {{"Shivbasav Nagar", 1200, 3500},
        {"Ram Nagar", 2000, 5500},
        {"NCC Arts", 1000, 3300},
        {"Bharat Motor School", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },

        {"Ram Nagar",{
        {{"Sambhaji Circle", 900, 3200},
        {"Shivbasav Nagar", 1200, 3500},
        {"Ram Nagar", 2000, 5500},
        {"NCC Arts", 1000, 3300},
        {"Bharat Motor School", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },

        {"NCC Arts",{
        {{"Shivbasav Nagar", 1200, 3500},
        {"Ram Nagar", 2000, 5500},
        {"Bharat Motor School", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },

        {"Bharat Motor School",{
        {{"Sambhaji Circle", 900, 3200},
        {"Shivbasav Nagar", 1200, 3500},
        {"Ram Nagar", 2000, 5500},
        {"NCC Arts", 1000, 3300},
        {"Bharat Motor School", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },

        {"Jadhav Nagar",{
        {{"Sambhaji Circle", 900, 3200},
        {"Shivbasav Nagar", 1200, 3500},
        {"Ram Nagar", 2000, 5500},
        {"NCC Arts", 1000, 3300},
        {"Bharat Motor School", 3000, 8500},
        {"Jadhav Nagar", 1600, 4800}}}
        },

        {"Sadashiv Nagar",{
        {{"Vengurla Road", 500, 2500},
        {"DC Bungalow Cross", 2000, 5500},
        {"Ambedkar Road", 900, 3200},
        {"Chennamma Circle - College Road", 1200, 3500},
        {"Vengurla Road - DC Bungalow", 1000, 3300},
        {"Rail Nagar South Cross", 3000, 8500}}}
        },

        {"Vengurla Road",{
        {{"Sadashiv Nagar", 200, 1800},
        {"Vengurla Road", 500, 2500},
        {"DC Bungalow Cross", 2000, 5500},
        {"Ambedkar Road", 900, 3200},
        {"Chennamma Circle - College Road", 1200, 3500},
        {"Vengurla Road - DC Bungalow", 1000, 3300},
        {"Rail Nagar South Cross", 3000, 8500}}}
        },

        {"DC Bungalow Cross",{
        {{"DC Bungalow Cross", 2000, 5500},
        {"Ambedkar Road", 900, 3200},
        {"Chennamma Circle - College Road", 1200, 3500},
        {"Vengurla Road - DC Bungalow", 1000, 3300},
        {"Rail Nagar South Cross", 3000, 8500}}}
        },

        {"Ambedkar Road",{
        {{"Sadashiv Nagar", 200, 1800},
        {"Vengurla Road", 500, 2500},
        {"DC Bungalow Cross", 2000, 5500},
        {"Ambedkar Road", 900, 3200},
        {"Chennamma Circle - College Road", 1200, 3500},
        {"Vengurla Road - DC Bungalow", 1000, 3300},
        {"Rail Nagar South Cross", 3000, 8500}}}
        },

        {"Chennamma Circle - College Road",{
        {{"DC Bungalow Cross", 2000, 5500},
        {"Ambedkar Road", 900, 3200},
        {"Chennamma Circle - College Road", 1200, 3500},
        {"Vengurla Road - DC Bungalow", 1000, 3300},
        {"Rail Nagar South Cross", 3000, 8500}}}
        },

        {"Vengurla Road - DC Bungalow",{
        {{"Vengurla Road", 500, 2500},
        {"DC Bungalow Cross", 2000, 5500},
        {"Ambedkar Road", 900, 3200},
        {"Chennamma Circle - College Road", 1200, 3500},
        {"Vengurla Road - DC Bungalow", 1000, 3300},
        {"Rail Nagar South Cross", 3000, 8500}}}
        },

        {"Rail Nagar South Cross",{
        {{"Vengurla Road", 500, 2500},
        {"DC Bungalow Cross", 2000, 5500},
        {"Ambedkar Road", 900, 3200},
        {"Chennamma Circle - College Road", 1200, 3500},
        {"Vengurla Road - DC Bungalow", 1000, 3300},
        {"Rail Nagar South Cross", 3000, 8500}}}
        }




        // You can define other areas similarly
    };

    // Display the areas in the selected zone
    displayAreas(selected_zone, zone_areas);

    // Ask the user to select an area
    cout << "\nEnter your choice (area number): ";
    int area_choice;
    cin >> area_choice;

    if (area_choice < 1 || area_choice > zone_areas[selected_zone].size()) {
        cout << "Invalid area choice" << endl;
        return 1;
    }

    // Get the name of the selected area
    string selected_area = zone_areas[selected_zone][area_choice - 1];
    cout << "You have selected " << selected_area << " as your area.\n";

    // Display the sub-division office and area details for the selected area
    displaySubDivisionDetails(selected_area, area_details);

    // Ask the user for their choice to find the nearest area
    cout << "\nEnter the Choice that you have selected for shortest distance: ";
    int user_choice;
    cin >> user_choice;

    string shortest_area = findShortestDistanceArea(area_details[selected_area].areas);
    cout << "You have selected " << shortest_area << " which is near to your location.\n";
    double outerDiameter, thickness;
    int segmentCount;
    string material;
    double density;

    // Select material
    cout << "Select material (polythene or steel): ";
    cin >> material;

    // Assign density based on material
    if (material == "polythene" || material == "Polythene") {
        density = 950; // kg/m^3 for polyethylene
    } else if (material == "steel" || material == "Steel") {
        density = 7850; // kg/m^3 for steel
    } else {
        cout << "Invalid material selected. Please choose 'polythene' or 'steel'." << endl;
        return 1;
    }

    // Input pipe specifications
    cout << "Enter the outer diameter of the pipe (in meters): ";
    cin >> outerDiameter;
    cout << "Enter the pipe wall thickness (in meters): ";
    cin >> thickness;

    // Input number of segments
    cout << "Enter the number of pipeline segments: ";
    cin >> segmentCount;

    vector<double> segmentLengths(segmentCount);
    double totalLength = 0.0;

    // Input lengths of each segment
    cout << "Enter the length of each segment (in meters):" << endl;
    for (int i = 0; i < segmentCount; i++) {
        cout << "Segment " << i + 1 << ": ";
        cin >> segmentLengths[i];
        totalLength += segmentLengths[i];
    }

    // Calculate total material volume and weight
    double totalVolume = 0.0;
    for (double length : segmentLengths) {
        totalVolume += calculatePipeVolume(length, outerDiameter, thickness);
    }
    double totalWeight = totalVolume * density;

    // Output results
    cout << "\nPipeline Material Usage Summary:" << endl;
    cout << "Material: " << material << endl;
    cout << "Total Length of Pipeline: " << totalLength << " meters" << endl;
    cout << "Total Material Volume: " << totalVolume << " cubic meters" << endl;
    cout << "Total Material Weight: " << totalWeight << " kilograms" << endl;
    string coatingType;


    double coatingThickness, coatingDensity;

    // Select coating type
    cout << "Select coating type (epoxy, polythene, plastic): ";
    cin >> coatingType;

    // Assign properties based on coating type
    if (coatingType == "epoxy") {
        coatingDensity = 1200; // kg/m³
        coatingThickness = 0.005; // 5 mm
    } else if (coatingType == "polythene") {
        coatingDensity = 950; // kg/m³
        coatingThickness = 0.01; // 10 mm
    } else if (coatingType == "plastic") {
        coatingDensity = 1050; // kg/m³
        coatingThickness = 0.008; // 8 mm
    } else {
        cout << "Invalid coating type. Please choose 'epoxy', 'polythene', or 'plastic'." << endl;
        return 1;
    }

    // Input pipe specifications
    cout << "Enter the outer diameter of the pipe (in meters): ";
    cin >> outerDiameter;

    // Input number of pipeline segments
    cout << "Enter the number of pipeline segments: ";
    cin >> segmentCount;



    // Input lengths of each segment
    cout << "Enter the length of each segment (in meters):" << endl;
    for (int i = 0; i < segmentCount; i++) {
        cout << "Segment " << i + 1 << ": ";
        cin >> segmentLengths[i];
        totalLength += segmentLengths[i];
    }

    // Calculate total coating area and weight
    double totalSurfaceArea = 0.0;
    for (double length : segmentLengths) {
        totalSurfaceArea += calculateSurfaceArea(length, outerDiameter);
    }
    double coatingVolume = totalSurfaceArea * coatingThickness;
    double coatingWeight = coatingVolume * coatingDensity;

    // Output results
    cout << "\nCoating Material Usage Summary:" << endl;
    cout << "Coating Type: " << coatingType << endl;
    cout << "Total Length of Pipeline: " << totalLength << " meters" << endl;
    cout << "Total Surface Area: " << totalSurfaceArea << " square meters" << endl;
    cout << "Total Coating Volume: " << coatingVolume << " cubic meters" << endl;
    cout << "Total Coating Weight: " << coatingWeight << " kilograms" << endl;
    double pressure; // Variable to store the pressure in the pipeline

    // Input the pressure value
    cout << "Enter the pressure in the pipeline (in PSI): ";
    cin >> pressure;

    // Validate input
    if (pressure < 0)
    {
        cout << "Pressure cannot be negative. Please enter a valid value." << endl;
        return 1;
    }

    // Determine and display the pressure category
    string category = categorizePressure(pressure);
    cout << "The pipeline pressure is categorized as: " << category << endl;

 // Define safety thresholds
    const float pressureThreshold = 100.0;   // Pressure threshold in bar
    const float temperatureThreshold = 60.0; // Temperature threshold in °C
    const float leakThreshold = 5.0;         // Sensor reading threshold for leak detection

    // Input parameters
    float  temperature, sensorReading;

    // Gather input from the user
    cout << "Enter pipeline pressure (in bar): ";
    cin >> pressure;

    cout << "Enter pipeline temperature (in °C): ";
    cin >> temperature;

    cout << "Enter gas sensor reading: ";
    cin >> sensorReading;

    // Check pipeline safety
    bool isSafe = true;

    if (pressure > pressureThreshold) {
        cout << "Warning: Pressure exceeds safe limit! Current pressure: " << pressure << " bar" << endl;
        isSafe = false;
    }

    if (temperature > temperatureThreshold) {
        cout << "Warning: Temperature exceeds safe limit! Current temperature: " << temperature << " °C" << endl;
        isSafe = false;
    }

    // Leak detection
    if (sensorReading > leakThreshold) {
        cout << "Warning: Gas leak detected! Sensor reading: " << sensorReading << endl;
        isSafe = false;
    }

    // Final safety status
    if (isSafe) {
        cout << "The pipeline is operating within safe limits." << endl;
    } else {
        cout << "Pipeline safety compromised! Take immediate action!" << endl;
    }

     // Variables to hold user inputs
    float unitsUsed, ratePerUnit;

    // Gather input from the user
    cout << "Enter the number of gas units used: ";
    cin >> unitsUsed;

    cout << "Enter the rate per unit (in rupees): ";
    cin >> ratePerUnit;

    // Calculate bills
    float monthlyBill = unitsUsed * ratePerUnit;
    float quarterlyBill = monthlyBill * 3; // Quarterly means 3 months
    float yearlyBill = monthlyBill * 12;  // Yearly means 12 months

    // Display the results
    cout << "Monthly bill: " << monthlyBill << " rupees" << endl;
    cout << "Quarterly bill: " << quarterlyBill << " rupees" << endl;
    cout << "Yearly bill: " << yearlyBill << " rupees" << endl;



// Variables to hold user inputs
    float gasBill, taxRate, totalBill;
    string dueDate, paymentStatus;

    // Gather input from the user
    cout << "Enter the gas bill amount (in rupees): ";
    cin >> gasBill;

    cout << "Enter the tax rate (in percentage): ";
    cin >> taxRate;

    cout << "Enter the due date (e.g., 10-Jan-2025): ";
    cin >> dueDate;

    cout << "Has the bill been paid? (yes/no): ";
    cin >> paymentStatus;

    // Calculate total bill with tax
    float taxAmount = (gasBill * taxRate) / 100;
    totalBill = gasBill + taxAmount;

    // Display the total bill
    cout << "Base gas bill: " << gasBill << " rupees" << endl;
    cout << "Tax (" << taxRate << "%): " << taxAmount << " rupees" << endl;
    cout << "Total bill amount: " << totalBill << " rupees" << endl;

    // Check payment status
    if (paymentStatus == "yes") {
        cout << "Thank you! The bill has been paid on time." << endl;
    } else {
        cout << "The bill has not been paid. Due date was: " << dueDate << endl;
        cout << "Please pay the bill immediately to avoid penalties." << endl;
    }
    int eastHomes, westHomes, northHomes, southHomes;
    int eastUsage, westUsage, northUsage, southUsage;
    long long eastTotal, westTotal, northTotal, southTotal, grandTotal;

    // Input for the East zone
    cout << "Enter the number of homes in the East zone: ";
    cin >> eastHomes;
    cout << "Enter the average gas usage per home in the East zone (in units): ";
    cin >> eastUsage;

    // Input for the West zone
    cout << "Enter the number of homes in the West zone: ";
    cin >> westHomes;
    cout << "Enter the average gas usage per home in the West zone (in units): ";
    cin >> westUsage;

    // Input for the North zone
    cout << "Enter the number of homes in the North zone: ";
    cin >> northHomes;
    cout << "Enter the average gas usage per home in the North zone (in units): ";
    cin >> northUsage;

    // Input for the South zone
    cout << "Enter the number of homes in the South zone: ";
    cin >> southHomes;
    cout << "Enter the average gas usage per home in the South zone (in units): ";
    cin >> southUsage;

    // Calculate total usage for each zone
    eastTotal = static_cast<long long>(eastHomes) * eastUsage;
    westTotal = static_cast<long long>(westHomes) * westUsage;
    northTotal = static_cast<long long>(northHomes) * northUsage;
    southTotal = static_cast<long long>(southHomes) * southUsage;

    // Calculate the grand total
    grandTotal = eastTotal + westTotal + northTotal + southTotal;

    // Display the results
    cout << "\nTotal gas usage by zones:";
    cout << "\nEast zone: " << eastTotal << " units";
    cout << "\nWest zone: " << westTotal << " units";
    cout << "\nNorth zone: " << northTotal << " units";
    cout << "\nSouth zone: " << southTotal << " units";
    cout << "\n\nGrand Total gas usage across all zones: " << grandTotal << " units" << endl;

     // Variables for leak detection system parameters
    double monitoredPressure, maop, distanceFromStructures;
    string leakDetectionMethod, emergencyValveStatus;

    // Input parameters for leak detection system
    cout << "Enter the monitored pressure of the pipeline (in bar): ";
    cin >> monitoredPressure;
    cout << "Enter the Maximum Allowable Operating Pressure (MAOP) (in bar): ";
    cin >> maop;
    cout << "Enter the distance from other structures (in meters): ";
    cin >> distanceFromStructures;
    cout << "Enter the leak detection method used (e.g., Pressure Monitoring, Acoustic Sensors, Odorants): ";
    cin.ignore(); // Clear input buffer
    getline(cin, leakDetectionMethod);
    cout << "Is the emergency shutoff valve functional? (Yes/No): ";
    getline(cin, emergencyValveStatus);

    // Display the entered parameters
    cout << "\nGas Pipeline Leak Detection System Parameters:" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Monitored Pressure: " << monitoredPressure << " bar" << endl;
    cout << "Maximum Allowable Operating Pressure (MAOP): " << maop << " bar" << endl;
    cout << "Distance from Other Structures: " << distanceFromStructures << " meters" << endl;
    cout << "Leak Detection Method: " << leakDetectionMethod << endl;
    cout << "Emergency Shutoff Valve Functional: " << emergencyValveStatus << endl;

    // Warning for exceeding MAOP
    if (monitoredPressure > maop) {
        cout << "\nWARNING: Monitored pressure exceeds MAOP! Immediate action required." << endl;
    }

    // Variables for geotechnical parameters
    string soilType, seismicActivityZone, terrainType;
    double waterTableLevel;

    // Input parameters
    cout << "Enter the soil type (e.g., Sandy, Clay, Rocky): ";
    getline(cin, soilType);
    cout << "Enter the seismic activity zone (e.g., Low, Moderate, High): ";
    getline(cin, seismicActivityZone);
    cout << "Enter the water table level (in meters): ";
    cin >> waterTableLevel;
    cin.ignore(); // Clear input buffer
    cout << "Enter the terrain type (e.g., Flat, Hilly, Mountainous): ";
    getline(cin, terrainType);

    // Display the entered parameters
    cout << "\nGeotechnical Parameters for Gas Pipeline System:" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Soil Type: " << soilType << endl;
    cout << "Seismic Activity Zone: " << seismicActivityZone << endl;
    cout << "Water Table Level: " << waterTableLevel << " meters" << endl;
    cout << "Terrain Type: " << terrainType << endl;

    // Additional considerations based on inputs
    if (waterTableLevel < 1.5) {
        cout << "\nNOTE: High water table level detected. Additional corrosion protection may be required." << endl;
    }

    if (seismicActivityZone == "High")
    {
        cout << "WARNING: High seismic activity zone. Flexible pipeline design recommended." << endl;
    }

    if (terrainType == "Mountainous")
    {
        cout << "CAUTION: Mountainous terrain detected. Advanced stabilization methods may be necessary." << endl;
    }

     // Variables for environmental parameters
    double tempFluctuation, rainfall, snowDepth;
    string proximityToWaterBodies, landUse;

    // Input parameters
    cout << "Enter the temperature fluctuation (in degrees Celsius): ";
    cin >> tempFluctuation;
    cout << "Enter the annual rainfall (in mm): ";
    cin >> rainfall;
    cout << "Enter the snow depth during winter (in cm): ";
    cin >> snowDepth;
    cin.ignore(); // Clear input buffer
    cout << "Enter the proximity to water bodies (e.g., Close, Moderate, Far): ";
    getline(cin, proximityToWaterBodies);
    cout << "Enter the type of land use (e.g., Agricultural, Urban, Industrial): ";
    getline(cin, landUse);


    // Display the entered parameters
    cout << "\nEnvironmental Parameters for Gas Pipeline System:" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Temperature Fluctuation: " << tempFluctuation << " °C" << endl;
    cout << "Annual Rainfall: " << rainfall << " mm" << endl;
    cout << "Snow Depth: " << snowDepth << " cm" << endl;
    cout << "Proximity to Water Bodies: " << proximityToWaterBodies << endl;
    cout << "Land Use: " << landUse << endl;


    // Additional considerations based on inputs
    if (tempFluctuation > 30)
    {
        cout << "\nNOTE: High temperature fluctuations detected. Consider thermal expansion measures." << endl;
    }

    if (proximityToWaterBodies == "Close")
    {
        cout << "CAUTION: Close proximity to water bodies. Ensure measures to prevent contamination." << endl;
    }

    if (landUse == "Agricultural")
    {
        cout << "ADVICE: Agricultural land detected. Take precautions to avoid disrupting farming activities." << endl;
    }
 // Variables for maintenance and inspection parameters
    string inspectionFrequency, repairMethods;
    int lifespan;

    // Input parameters
    cout << "Enter the inspection frequency (e.g., Monthly, Quarterly, Annually): ";
    getline(cin, inspectionFrequency);
    cout << "Enter the repair methods used (e.g., Welding, Clamp Repairs, Section Replacement): ";
    getline(cin, repairMethods);
    cout << "Enter the expected lifespan of the pipeline (in years): ";
    cin >> lifespan;

     // Display the entered parameters
    cout << "\nMaintenance and Inspection Parameters for Gas Pipeline System:" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Inspection Frequency: " << inspectionFrequency << endl;
    cout << "Repair Methods: " << repairMethods << endl;
    cout << "Expected Lifespan: " << lifespan << " years" << endl;

    // Additional suggestions based on inputs
    if (inspectionFrequency == "Annually")
    {
        cout << "\nNOTE: Annual inspections may not be sufficient for high-risk areas. Consider more frequent checks." << endl;
    }

    if (lifespan < 20)
    {
        cout << "ADVICE: Short lifespan detected. Ensure regular maintenance and timely rehabilitation planning." << endl;
    }

    // Variables for regulatory and compliance parameters
    string standards, permits, odorization;

    // Input parameters
    cout << "Enter the standards and codes followed (e.g., ASME B31.8, ISO 9001): ";
    getline(cin, standards);
    cout << "Enter the status of permits and approvals (e.g., Approved, Pending): ";
    getline(cin, permits);
    cout << "Is odorization required? (Yes/No): ";
    getline(cin, odorization);

    // Display the entered parameters
    cout << "\nRegulatory and Compliance Parameters for Gas Pipeline System:" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Standards and Codes: " << standards << endl;
    cout << "Permits and Approvals: " << permits << endl;
    cout << "Odorization Requirement: " << odorization << endl;


    // Additional compliance checks
    if (permits == "Pending")
    {
        cout << "\nWARNING: Permits and approvals are pending. Ensure compliance before operation." << endl;
    }

    if (odorization == "No")
    {
        cout << "NOTE: Odorization is not enabled. Ensure alternative leak detection methods are in place." << endl;
    }
    // Variables for operational parameters
    string controlSystem, pressureRegulatingStation, meteringStation;

    // Input parameters
    cout << "Enter the control system used (e.g., SCADA, DCS): ";
    getline(cin, controlSystem);
    cout << "Enter the pressure regulating station details (e.g., Located at key points, Automated, Manual): ";
    getline(cin, pressureRegulatingStation);
    cout << "Enter the metering station details (e.g., Flow meters, Usage meters, Installed at intervals): ";
    getline(cin, meteringStation);

    // Display the entered parameters
    cout << "\nOperational Parameters for Gas Pipeline System:" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Control System: " << controlSystem << endl;
    cout << "Pressure Regulating Station: " << pressureRegulatingStation << endl;
    cout << "Metering Station: " << meteringStation << endl;

    // Additional suggestions or checks based on inputs
    if (controlSystem == "SCADA")
    {
        cout << "\nNOTE: SCADA system detected. Ensure proper cybersecurity measures are in place for remote monitoring." << endl;
    }

    if (pressureRegulatingStation == "Manual")
    {
        cout << "WARNING: Manual pressure regulation detected. Consider automation for better control and efficiency." << endl;
    }

    if (meteringStation == "Installed at intervals")
    {
        cout << "ADVICE: Ensure metering stations are installed at regular intervals to maintain accurate usage data." << endl;
    }

    // Variables for risk assessment parameters
    string risks, hazardZone, integrityProgram;

    // Input parameters
    cout << "Enter potential risks (e.g., Leaks, Explosions, External Interference): ";
    getline(cin, risks);
    cout << "Enter the hazard zones (e.g., High Risk Areas, Earthquake-Prone Zones, Flood Zones): ";
    getline(cin, hazardZone);
    cout << "Enter the pipeline integrity management program (e.g., Regular Inspections, Cathodic Protection): ";
    getline(cin, integrityProgram);

     // Display the entered parameters
    cout << "\nRisk Assessment for Gas Pipeline System:" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Potential Risks: " << risks << endl;
    cout << "Hazard Zones: " << hazardZone << endl;
    cout << "Pipeline Integrity Management Program: " << integrityProgram << endl;


      // Additional risk management suggestions based on input
    if (risks.find("Leaks") != string::npos)
    {
        cout << "\nNOTE: Ensure effective leak detection systems are in place (e.g., sensors, pressure monitoring)." << endl;
    }

    if (hazardZone.find("Earthquake-Prone Zones") != string::npos)
    {
        cout << "ADVICE: Consider flexible pipeline designs and additional seismic protection measures." << endl;
    }

    if (integrityProgram.find("Cathodic Protection") != string::npos)
    {
        cout << "ADVICE: Ensure regular maintenance and checks of cathodic protection systems to prevent corrosion." << endl;
    }

    return 0;
}
