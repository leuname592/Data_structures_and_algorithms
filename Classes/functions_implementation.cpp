/**
 * @file functions_implementation.cpp
 * 
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * 
 * @brief Este file define como se comporta cada funcion.
 * 
 * @date 2023-04-19
 * 
 * @copyright MIT
 * 
 */

#include "libraries.hpp"
#include "classes_structure.hpp"
#include "functions_structure.hpp"

Campus add_campus(string campus_name){
    Campus campus;
    campus.set_campus_name("Sede Rodrigo Facio");
    return campus;
}

Campus add_property(Campus campus, bool bus, string property_name){
    Property property(bus,property_name);
    campus.properties.push_back(property);
    return campus;
}

string bus_enabled_in_properties(vector<Property> properties){
    string bus_enabled_in_properties = "";
    for(int i = 0; i < properties.size(); i++){
        if(properties[i].get_bus() == true){
            bus_enabled_in_properties += properties[i].get_property_name()+" ";
        }
    }
    if (bus_enabled_in_properties == ""){
        bus_enabled_in_properties="No hay un bus interno";
    }
    return bus_enabled_in_properties;
}

/**
 * @brief Los metodos con prefijo add construyen un objeto y lo agregan al final del vector con un pushback
 * 
 */
Campus add_parking_building(uint8_t property_number,Campus Campus, string parking_building_name, bool elevator, short unsigned int number_of_floors, short unsigned int number_of_parking_spots,short unsigned int number_of_washrooms){
    ParkingBuilding ParkingBuilding;
    ParkingBuilding.set_building_name(parking_building_name);
    ParkingBuilding.set_elevator(elevator);
    ParkingBuilding.set_number_of_floors(number_of_floors);
    ParkingBuilding.set_number_of_parking_spots(number_of_parking_spots);
    ParkingBuilding.set_number_of_washrooms(number_of_washrooms);
    Campus.properties[property_number].parking_buildings.push_back(ParkingBuilding);
    return Campus;
}

Campus add_classroom_building(uint8_t property_number,Campus Campus, string classroom_building_name, bool elevator, short unsigned int number_of_floors, bool cafeteria, bool auditorium){
    ClassRoomBuilding ClassRoomBuilding;
    ClassRoomBuilding.set_building_name(classroom_building_name);
    ClassRoomBuilding.set_elevator(elevator);
    ClassRoomBuilding.set_number_of_floors(number_of_floors);
    ClassRoomBuilding.set_cafeteria(cafeteria);
    ClassRoomBuilding.set_auditorium(auditorium);
    Campus.properties[property_number].classroom_buildings.push_back(ClassRoomBuilding);
    return Campus;
}

int __id=0;
Campus add_classroom(uint8_t property_number, uint8_t classroom_building_number, Campus Campus, short unsigned int number_of_desks, short unsigned int floor, bool projector){
    ClassRoom ClassRoom(number_of_desks,projector,floor);
    ClassRoom.set__id(__id);
    Campus.properties[property_number].classroom_buildings[classroom_building_number].classroom.push_back(ClassRoom);
    __id++;
    return Campus;
}

Campus add_multiple_classrooms(Campus Campus, decltype(Campus)(*add_clasroom)(uint8_t,uint8_t,decltype(Campus),short unsigned int,short unsigned int,bool),uint8_t classrooms_per_floor,uint8_t property_number,uint8_t classroom_building_number,uint8_t number_of_desks, bool projector)
{
    for(int  floor=0;floor<Campus.properties[property_number].classroom_buildings[classroom_building_number].get_number_of_floors();floor++){
        for(int i=0;i<classrooms_per_floor;i++){
            Campus = add_classroom(property_number,classroom_building_number,Campus,number_of_desks,floor,projector);
        }
    }
    return Campus;
}

/**
 * @brief Cada campus itera por cada finca, edificio y aula imprimiendo su respectiva informacion
 * 
 * @param campus_to_print Objeto que contiene el Campus
 */
void print_campus(Campus campus_to_print){
    cout<<endl;
    cout<<"Tarea 1. Emmanuel Chavarria Solis, Carnet: B51977"<<endl<<endl;
    campus_to_print.print_campus();
    cout<<endl;
    cout<<"De estas fincas, por las que pasa el bus interno son: ";
    for(int i=0; i<campus_to_print.properties.size(); i++){
        campus_to_print.properties[i].print_bus_location();
    }
    cout<<endl<<endl;

    cout<<"Informacion sobre las fincas:"<<endl;
    for(int i=0; i<campus_to_print.properties.size(); i++){
        cout<<campus_to_print.properties[i].get_property_name()<<" posee "<<campus_to_print.properties[i].get_total_number_of_buildings()<<" edificios, "<<campus_to_print.properties[i].get_number_of_parking_buildings()<<" son de parqueo y "<<campus_to_print.properties[i].get_number_of_classroom_buildings()<<" de aulas."<<endl;
    }

    for(int j=0; j<campus_to_print.properties.size(); j++){
        cout<<endl;
        cout<<"-Informacion de los edificos de parqueo en: "<<campus_to_print.properties[j].get_property_name()<<endl;
        for(int i=0;i<campus_to_print.properties[j].parking_buildings.size();i++){
            campus_to_print.properties[j].parking_buildings[i].print_parking_info();
        }
        cout<<"-Informacion de los edificos de aulas en la finca: "<<campus_to_print.properties[j].get_property_name()<<endl;
        for(int i=0; i<campus_to_print.properties[j].classroom_buildings.size();i++){
            campus_to_print.properties[j].classroom_buildings[i].print_classroom_building_info();
        }
    }
    cout<<endl;
    cout<<"Informacion de cada aula:"<<endl;
    for(int i=0; i<campus_to_print.properties.size(); i++){
        for(int j=0; j<campus_to_print.properties[i].classroom_buildings.size();j++){
            for(int k=0; k<campus_to_print.properties[i].classroom_buildings[j].classroom.size();k++){
                campus_to_print.properties[i].classroom_buildings[j].classroom[k].print_classroom_info();
                cout<<"del edificio de "<<campus_to_print.properties[i].classroom_buildings[j].get_building_name()<<endl;
            }        
        cout<<endl;
        }
    }
}