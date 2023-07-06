/**
 * @file classes_structure.hpp
 * 
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * 
 * @brief Este file describe la estructura de las clases a ser utilizadas
 * 
 * @date 2023-04-19
 * 
 * @copyright MIT
 * 
 */
#pragma once
#include "libraries.hpp"

class Campus;
class Property;
class Building;
class ParkingBuilding;
class ClassRoomBuilding;
class ClassRoom;

/**
 * @brief Esta clase se encarga de inicializar el Campus.
 * @param campus_name Nombre del campus
 * @param property_names Nombre de cada finca en un vector
 * @param _classroom_id Identificador de las clases
 */
class Campus{
    private:
        string campus_name;
        vector<string> property_names;
        short unsigned int _classroom_id;
    public:
        Campus():_classroom_id(0){};
        Campus(string campus_name):campus_name(campus_name),_classroom_id(0){};
        void set_property_names(string property);
        void set_campus_name(string campus_name);
        void print_campus();
        short unsigned int get_number_of_properties();
        vector<Property> properties;
        vector<string> get_property_names();
        string get_campus_name();
        short unsigned int get_classroom_id();
        void set_classroom_id(short unsigned int _classroom_id);
};

/**
 * @brief Aqui se crean las fincas.
 * @param bus Bool que indica si pasa un bus por la propiedad
 * @param property_name Nombre de la Finca
 * @param parking_buildings Vector de edificios de parqueo
 * @param classroom_buildings Vector de edificios de aulas
 */
class Property:Campus{
    private:
        bool bus;
        string property_name;
    public:
        vector<ParkingBuilding> parking_buildings;
        vector<ClassRoomBuilding> classroom_buildings;
        Property():bus(false){};
        Property(bool bus,string property_name):bus(bus),property_name(property_name){};
        string get_property_name();
        bool get_bus();
        void set_bus(bool bus);
        void set_property_name(string property_name);
        void print_bus_location();
        short unsigned int get_number_of_parking_buildings();
        short unsigned int get_number_of_classroom_buildings();
        short unsigned int get_total_number_of_buildings();
};

/**
 * @brief Esta clase es base de los edificios de aulas y parqueos. Agrupa caracteristicas en comun.
 * @param elevator Indica presencia de elevadores
 * @param building_name Nombre del edificio
 * @param number_of_floors Numero de pisos
 */
class Building{
    private:
        bool elevator;
        string building_name;
        short unsigned int number_of_floors;
    public:
        Building():elevator(false),number_of_floors(0){};
        Building(string building_name, bool elevator, short unsigned int number_of_floors):building_name(building_name), elevator(elevator), number_of_floors(number_of_floors) {};
        void set_elevator(bool elevator);
        void set_building_name(string building_name);
        void set_number_of_floors(short unsigned int number_of_floors);
        bool get_elevator();
        string get_building_name();
        short unsigned int get_number_of_floors();
};

/**
 * @brief Esta clase describe los edificios de parqueos
 * @param number_of_parking_spots Numero de estacionamientos
 * @param number_of_washrooms Numero de baños por edificio
 * 
 */
class ParkingBuilding: public Building{
    private:
        short unsigned int number_of_parking_spots;
        short unsigned int number_of_washrooms;
    public:
        ParkingBuilding():number_of_parking_spots(0),number_of_washrooms(0){};
        ParkingBuilding(short unsigned int number_of_parking_spots, short unsigned int number_of_washrooms):number_of_parking_spots(number_of_parking_spots),number_of_washrooms(number_of_washrooms) {};
        void set_number_of_parking_spots(short unsigned int number_of_parking_spots);
        void set_number_of_washrooms(short unsigned int number_of_washrooms);
        short unsigned int get_number_of_parking_spots();
        short unsigned int get_number_of_washrooms();
        void print_parking_info();
};

/**
 * @brief Esta clase describe los edificios de aulas.
 * @param cafeteria Indica si hay una soda
 * @param auditorium Indica si hay auditorio
 * @param classroom Vector de aulas de cada edificio
 * 
 */
class ClassRoomBuilding: public Building{
    private:
        bool cafeteria;
        bool auditorium;
    public:
        vector<ClassRoom> classroom;
        ClassRoomBuilding():cafeteria(false),auditorium(false){};
        ClassRoomBuilding(bool cafeteria, short unsigned int number_of_classrooms, bool auditorium):cafeteria(cafeteria),auditorium(auditorium){};
        void set_cafeteria(bool cafeteria);
        void set_auditorium(bool auditorium);
        bool get_cafeteria();
        bool get_auditorium();
        short unsigned int total_classrooms();
        void print_classroom_building_info();
};

/**
 * @brief Esta clase describe las aulas.
 * @param __id Identificador de cada aula
 * @param number_of_desks Numero de pupitres
 * @param floor Numero de pisos
 * @param projector Presencia de proyector en el
 */
class ClassRoom:public Campus{
    private:
        int __id;
        short unsigned int number_of_desks;
        short unsigned int floor;
        bool projector;
    public:
        ClassRoom();
        ClassRoom(short unsigned int number_of_desks, bool projector, short unsigned int floor);
        void set__id(short unsigned int __id);
        void set_number_of_desks(short unsigned int number_of_desks);
        void set_projector(bool projector);
        void set_floor(short unsigned int floor);
        short unsigned int get__id();
        short unsigned int get_number_of_desks();
        bool get_projector();
        short unsigned int get_floor();
        void print_classroom_info();
};